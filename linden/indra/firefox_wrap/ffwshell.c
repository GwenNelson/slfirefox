/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: GPL 2.0
 * Copyright(C) 2008 Litesim Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Stephen Mak <smak@sun.com>
 *
 * ***** END LICENSE BLOCK ***** */

/*
 * ffwshell.c
 *
 * Netscape Client Plugin API
 * - Function that need to be implemented by plugin developers
 *
 * based on sample code from mozilla.org
 *
 * dp Suresh <dp@netscape.com>
 * updated 5/1998 <pollmann@netscape.com>
 * updated 9/2000 <smak@sun.com>
 * modified 4/2008 <abhinav.lele@gmail.com>
 * modified 9/2008 <gareth@litesim.com>
 */

#define MOZ_X11
#include <stdio.h>
#include <string.h>
#include "npapi.h"
#include "ff_wrap.h"
#include "strings.h"
#include "plstr.h"
#include "prproces.h"
#include <X11/Xutil.h>
#include <X11/Xlib.h>


/***********************************************************************
 *
 * Implementations of plugin API functions
 *
 ***********************************************************************/


int16   NPP_HandleEvent(NPP instance, void* event)
{
    return 0;
}

char*
NPP_GetMIMEDescription(void)
{
    return(MIME_TYPES_HANDLED);
}

NPError
NPP_GetValue(NPP instance, NPPVariable variable, void *value)
{
    NPError err = NPERR_NO_ERROR;

    switch (variable) {
        case NPPVpluginNameString:
            *((char **)value) = PLUGIN_NAME;
            break;
        case NPPVpluginDescriptionString:
            *((char **)value) = PLUGIN_DESCRIPTION;
            break;
        default:
            err = NPERR_GENERIC_ERROR;
    }
    return err;
}

NPError
NPP_Initialize(void)
{

    return NPERR_NO_ERROR;
}

#ifdef OJI
jref
NPP_GetJavaClass()
{
    return NULL;
}
#endif

void
NPP_Shutdown(void)
{
}

NPError 
NPP_New(NPMIMEType pluginType,
    NPP instance,
    uint16 mode,
    int16 argc,
    char* argn[],
    char* argv[],
    NPSavedData* saved)
{

    PluginInstance* This;

    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;
        
    instance->pdata = NPN_MemAlloc(sizeof(PluginInstance));
    
    This = (PluginInstance*) instance->pdata;

    if (This == NULL) 
    {
        return NPERR_OUT_OF_MEMORY_ERROR;
    }

    memset(This, 0, sizeof(PluginInstance));

    /* mode is NP_EMBED, NP_FULL, or NP_BACKGROUND (see npapi.h) */
    This->mode = mode;
    This->type = dupMimeType(pluginType);
    This->instance = instance;
    This->pluginsPageUrl = NULL;
    This->exists = FALSE;

    /* Parse argument list passed to plugin instance */
    /* We are interested in these arguments
     *  PLUGINSPAGE = <url>
     */
    while (argc > 0)
    {
        argc --;
        if (argv[argc] != NULL)
        {
        if (!PL_strcasecmp(argn[argc], "PLUGINSPAGE"))
            This->pluginsPageUrl = strdup(argv[argc]);
        else if (!PL_strcasecmp(argn[argc], "PLUGINURL"))
            This->pluginsFileUrl = strdup(argv[argc]);
        else if (!PL_strcasecmp(argn[argc], "CODEBASE"))
            This->pluginsPageUrl = strdup(argv[argc]);
        else if (!PL_strcasecmp(argn[argc], "CLASSID"))
            This->pluginsFileUrl = strdup(argv[argc]);
        else if (!PL_strcasecmp(argn[argc], "HIDDEN"))
            This->pluginsHidden = (!PL_strcasecmp(argv[argc],
            "TRUE"));
        }
    }

    return NPERR_NO_ERROR;
}

NPError 
NPP_Destroy(NPP instance, NPSavedData** save)
{

    PluginInstance* This;

    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    This = (PluginInstance*) instance->pdata;

    if (This != NULL) {
	if (This->dialogBox)
	   destroyWidget(This);
        if (This->type)
            NPN_MemFree(This->type);
        if (This->pluginsPageUrl)
            NPN_MemFree(This->pluginsPageUrl);
        if (This->pluginsFileUrl)
                NPN_MemFree(This->pluginsFileUrl);
        NPN_MemFree(instance->pdata);
        instance->pdata = NULL;
    }
    SDL_Quit();
    return NPERR_NO_ERROR;
}

PRProcess* viewer_proc = NULL;
NPError 
NPP_SetWindow(NPP instance, NPWindow* window)
{
    PluginInstance* This;
    NPSetWindowCallbackStruct *ws_info;
    const SDL_VideoInfo* info = NULL;
    char windowEnv[3][500];
   	
    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    This = (PluginInstance*) instance->pdata;

    if (This == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    ws_info = (NPSetWindowCallbackStruct *)window->ws_info;

    fprintf(stderr,"Setting up events for viewer\n");
    int app_event_mask = !ButtonPressMask;
    XSelectInput(ws_info->display, (int)(window->window), app_event_mask);

    fprintf(stderr,"Loading environment for viewer:\n");
    sprintf(windowEnv[0],"SDL_WINDOWID=%d",(int)(window->window));
    sprintf(windowEnv[1],"FFW_WINX=%d",(int)(window->width));
    sprintf(windowEnv[2],"FFW_WINY=%d",(int)(window->height));
    int i=0;
    for(i=0; i<3; i++) putenv(windowEnv[i]);

    fprintf(stderr, "Window=(%i)\n", (int)(window->window));
    fprintf(stderr, "W=(%i) H=(%i)\n",(int)window->width, (int)window->height);

/*
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1) return NPERR_GENERIC_ERROR;
    info = SDL_GetVideoInfo();
	if(!info) { fprintf(stderr,"err1\n"); return NPERR_GENERIC_ERROR; }

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
	

	if((SDL_SetVideoMode(window->x,window->y,0,SDL_OPENGL | SDL_RESIZABLE | SDL_DOUBLEBUF | SDL_ASYNCBLIT ))==0) { fprintf(stderr,"err2\n"); return NPERR_GENERIC_ERROR; }
	glViewport(0,0,(GLsizei) window->x , (GLsizei) window->y );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0, (GLdouble) window->x, 0.0, (GLdouble) window->y);
	/*glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1,0,0,1);*/
	/**/
#ifdef MOZ_X11
//    if (This->window == (Window) window->window) {
        /* The page with the plugin is being resized.
           Save any UI information because the next time
           around expect a SetWindow with a new window
           id.
        */
//        return NPERR_NO_ERROR;
 //   } else {

      This->window = (Window) window->window;
      This->x = window->x;
      This->y = window->y;
      This->width = window->width;
      This->height = window->height;
      This->display = ws_info->display;
      This->visual = ws_info->visual;
      This->depth = ws_info->depth;
      This->colormap = ws_info->colormap;
      makePixmap(This);
      makeWidget(This);
//    }
#endif  /* #ifdef MOZ_X11 */
    if (viewer_proc == NULL) {
        char viewerArgs[2][50];
        PRProcessAttr* viewerProcAttr = PR_NewProcessAttr();
        PR_ProcessAttrSetCurrentDirectory(viewerProcAttr,"/slbrowser/");
        sprintf(viewerArgs[0],"/slbrowser/packaged/secondlife\0");
        sprintf(viewerArgs[1],"--autologin\0");
        fprintf(stderr,"Starting viewer!\n");
        viewer_proc = PR_CreateProcess("/slbrowser/secondlife",NULL,NULL,viewerProcAttr);
        PR_DetachProcess(viewer_proc);
    }

    return NPERR_NO_ERROR;
}


NPError 
NPP_NewStream(NPP instance,
          NPMIMEType type,
          NPStream *stream, 
          NPBool seekable,
          uint16 *stype)
{
    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    return NPERR_NO_ERROR;
}


int32 
NPP_WriteReady(NPP instance, NPStream *stream)
{
    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    /* We don't want any data, kill the stream */
    NPN_DestroyStream(instance, stream, NPRES_DONE);

    /* Number of bytes ready to accept in NPP_Write() */
    return -1L;   /* don't accept any bytes in NPP_Write() */
}


int32 
NPP_Write(NPP instance, NPStream *stream, int32 offset, int32 len, void *buffer)
{
    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    /* We don't want any data, kill the stream */
    NPN_DestroyStream(instance, stream, NPRES_DONE);

    return -1L;   /* don't accept any bytes in NPP_Write() */
}


NPError 
NPP_DestroyStream(NPP instance, NPStream *stream, NPError reason)
{
    if (instance == NULL)
        return NPERR_INVALID_INSTANCE_ERROR;

    /***** Insert NPP_DestroyStream code here *****\
    PluginInstance* This;
    This = (PluginInstance*) instance->pdata;
    \**********************************************/

    return NPERR_NO_ERROR;
}


void 
NPP_StreamAsFile(NPP instance, NPStream *stream, const char* fname)
{
    /***** Insert NPP_StreamAsFile code here *****\
    PluginInstance* This;
    if (instance != NULL)
        This = (PluginInstance*) instance->pdata;
    \*********************************************/
}


void
NPP_URLNotify(NPP instance, const char* url,
                NPReason reason, void* notifyData)
{
    /***** Insert NPP_URLNotify code here *****\
    PluginInstance* This;
    if (instance != NULL)
        This = (PluginInstance*) instance->pdata;
    \*********************************************/
}


void 
NPP_Print(NPP instance, NPPrint* printInfo)
{
    if(printInfo == NULL)
        return;

    if (instance != NULL) {
    /***** Insert NPP_Print code here *****\
        PluginInstance* This = (PluginInstance*) instance->pdata;
    \**************************************/
    
        if (printInfo->mode == NP_FULL) {
            /*
             * PLUGIN DEVELOPERS:
             *  If your plugin would like to take over
             *  printing completely when it is in full-screen mode,
             *  set printInfo->pluginPrinted to TRUE and print your
             *  plugin as you see fit.  If your plugin wants Netscape
             *  to handle printing in this case, set
             *  printInfo->pluginPrinted to FALSE (the default) and
             *  do nothing.  If you do want to handle printing
             *  yourself, printOne is true if the print button
             *  (as opposed to the print menu) was clicked.
             *  On the Macintosh, platformPrint is a THPrint; on
             *  Windows, platformPrint is a structure
             *  (defined in npapi.h) containing the printer name, port,
             *  etc.
             */

    /***** Insert NPP_Print code here *****\
            void* platformPrint =
                printInfo->print.fullPrint.platformPrint;
            NPBool printOne =
                printInfo->print.fullPrint.printOne;
    \**************************************/
            
            /* Do the default*/
            printInfo->print.fullPrint.pluginPrinted = FALSE;
        }
        else {  /* If not fullscreen, we must be embedded */
            /*
             * PLUGIN DEVELOPERS:
             *  If your plugin is embedded, or is full-screen
             *  but you returned false in pluginPrinted above, NPP_Print
             *  will be called with mode == NP_EMBED.  The NPWindow
             *  in the printInfo gives the location and dimensions of
             *  the embedded plugin on the printed page.  On the
             *  Macintosh, platformPrint is the printer port; on
             *  Windows, platformPrint is the handle to the printing
             *  device context.
             */

    /***** Insert NPP_Print code here *****\
            NPWindow* printWindow =
                &(printInfo->print.embedPrint.window);
            void* platformPrint =
                printInfo->print.embedPrint.platformPrint;
    \**************************************/
        }
    }
}
