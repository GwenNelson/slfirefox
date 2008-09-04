/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
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
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

/*
 * nullplugin.c
 *
 * Implementation of the null plugins for Unix.
 *
 * dp <dp@netscape.com>
 * updated 5/1998 <pollmann@netscape.com>
 * updated 9/2000 <smak@sun.com>
 * modified 4/2008 <abhinav.lele@gmail.com>
 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <gdk/gdkkeysyms.h>

/* Xlib/Xt stuff */
#ifdef MOZ_X11
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/cursorfont.h>
#endif

#include "npapi.h"
#include "ff_wrap.h"
#include "prprf.h"

#define DIALOGID "dialog"

/* Global data */
static MimeTypeElement *head = NULL;

/* destroy the dialog box */
void
destroyWidget(PluginInstance *This)
{
    if (This && This->dialogBox)
    {
      gtk_widget_destroy (GTK_WIDGET(This->dialogBox));
    }
}



/* a handy procedure to add a widget and pack it as well */
static GtkWidget *
AddWidget (GtkWidget *widget, GtkWidget *packingbox)
{
    gtk_box_pack_start(GTK_BOX(packingbox), widget, TRUE, TRUE, 2);
    return widget;
}



/* MIMETypeList maintenance routines */

static gboolean
isEqual(NPMIMEType t1, NPMIMEType t2)
{
    return (t1 && t2) ? (strcmp(t1, t2) == 0) : FALSE; 
}

static MimeTypeElement * 
isExist(MimeTypeElement **typelist, NPMIMEType type)
{
    MimeTypeElement *ele;

    ele = *typelist;
    while (ele != NULL) {
        if (isEqual(ele->pinst->type, type))
            return ele;
        ele = ele->next;
    }
    return NULL;
}

NPMIMEType
dupMimeType(NPMIMEType type)
{
    NPMIMEType mimetype = NPN_MemAlloc(PL_strlen(type)+1);
    if (mimetype)
        PL_strcpy(mimetype, type);
    return(mimetype);
}

static gboolean 
addToList(MimeTypeElement **typelist, PluginInstance *This)
{
    if (This && This->type && !isExist(typelist, This->type))
    {
        MimeTypeElement *ele;
        if ((ele = (MimeTypeElement *) NPN_MemAlloc(sizeof(MimeTypeElement))))
        {
            ele->pinst = This;
            ele->next = *typelist;
            *typelist = ele;
            return(TRUE);
        }
    }
    return(FALSE);
}

static gboolean
delFromList(MimeTypeElement **typelist, PluginInstance *This)
{
    if (typelist && This)
    {
        MimeTypeElement *ele_prev;
        MimeTypeElement *ele = *typelist;
        while (ele)
        {
            if (isEqual(ele->pinst->type, This->type))
            {
                if (*typelist == ele)
                {
                    *typelist = ele->next;
                } else {
                    ele_prev->next = ele->next;
                }
                NPN_MemFree(ele);
                return(TRUE);
            }
            ele_prev = ele;
            ele = ele->next;
        }
    }
    return(FALSE);
}

static void
onDestroyWidget(GtkWidget *w, gpointer data)
{
    PluginInstance* This = (PluginInstance*) data;
    if (This && This->dialogBox && This->dialogBox == w)
    {
        This->dialogBox = 0;
        delFromList(&head, This);
    }
}

/* create and display the dialog box */
void 
makeWidget(PluginInstance *This)
{
    
    GtkWidget *dialogWindow;
    GtkWidget *dialogMessage;
    GtkWidget *okButton;
    GtkWidget *cancelButton;
    char message[1024];
    MimeTypeElement *ele;
    
    return; // don't do anything
    if (!This) return;

}

/* XPM */
static char * npnul320_xpm[] = {
"32 32 6 1",
"       c None",
".      c #808080",
"+      c #F8F8F8",
"@      c #C0C0C0",
"#      c #000000",
"$      c #00F8F8",
"........................++++++++",
".++++++++++++++++++++++..+++++++",
".+++++++++++++++++++++@.@.++++++",
".++@@@@@@@@@@@@@@@@@@@@.+@.+++++",
".++@@@@@@@@@.....@@@@@@.++@.++++",
".++@@@@@@@@.+++++#@@@@@.+++@.+++",
".++@@@@@@@.++$$$$$#@@@@.++++@.++",
".++@@@@@@@.+$$$$$$#.@@@.+++++@.+",
".++@@@...@@.+$$$$#..###.#######+",
".++@@.+++$$++$$$$$##++$#......#+",
".++@@.+$$$++$$$$$$$+$$$#......#+",
".++@@.+$$$$$$$$$$$$$$$$#..@@++#+",
".++@@@$$$$$$$$$$$$$$$$#...@@++#+",
".++@@@$#$##.$$$$$$##$$#...@@++#+",
".++@@@@##...$$$$$#..##...@@@++#+",
".++@@@@@....+$$$$#.......@@@++#+",
".++@@@@@@...+$$$$#.@@@..@@@@++#+",
".++@@@@..@@.+$$$$#.@##@@@@@@++#+",
".++@@@.++$$++$$$$$##$$#@@@@@++#+",
".++@@@.+$$++$$$$$$$$$$#@@@@@++#+",
".++@@.++$$$$$$$$$$$$$$$#@@@@++#+",
".++@@.+$$$$$$$$$$$$$$$$#.@@@++#+",
".++@@.+$$##$$$$$$$##$$$#..@@++#+",
".++@@@###...$$$$$#.@###...@@++#+",
".++@@@@....$$$$$$$#.@.....@@++#+",
".++@@@@@...$$$$$$$#..@...@@@++#+",
".++@@@@@@@@#$$$$$#...@@@@@@@++#+",
".++@@@@@@@@@#####...@@@@@@@@++#+",
".++@@@@@@@@@@......@@@@@@@@@++#+",
".+++++++++++++....++++++++++++#+",
".+++++++++++++++++++++++++++++#+",
"###############################+"};


static GdkPixmap *nullPluginGdkPixmap = 0;

static GdkWindow *getGdkWindow(PluginInstance *This)
{
#ifdef MOZ_X11
    GdkWindow *gdk_window;
    Window xwin = (Window) This->window;
    Widget xt_w = XtWindowToWidget(This->display, xwin);

    if (xt_w) {
      xt_w = XtParent(xt_w);
      if (xt_w) {
         xwin = XtWindow(xt_w);
         /* xwin = xt_w->core.window; */
      }
    }
    gdk_window = gdk_window_lookup(xwin);
    return gdk_window;
#else
    return NULL;
#endif
}

static void
createPixmap(PluginInstance *This)
{
    int err = 0;

    if (nullPluginGdkPixmap == 0)
    { 
       GtkStyle *style;
       GdkBitmap *mask;
       GdkWindow *gdk_window = getGdkWindow(This);
       if (gdk_window)
       {
           GtkWidget *widget;
           gpointer user_data = NULL;
           gdk_window_get_user_data( gdk_window, &user_data);
           widget = GTK_WIDGET(user_data);
           style = gtk_widget_get_style(widget);
           nullPluginGdkPixmap = gdk_pixmap_create_from_xpm_d(gdk_window , &mask,
                                             &style->bg[GTK_STATE_NORMAL], npnul320_xpm);
#ifdef MOZ_X11
	   /* Pixmap is created on original X session but used by new session */
	   XSync(GDK_DISPLAY(), False);
#endif
       }
    }
}

static void
drawPixmap(PluginInstance *This)
{
    return;
    if (nullPluginGdkPixmap)
    {
        int pixmap_with, pixmap_height, dest_x, dest_y;
        gdk_window_get_size((GdkWindow *)nullPluginGdkPixmap, &pixmap_with, &pixmap_height);
        dest_x = This->width/2 - pixmap_with/2;
        dest_y = This->height/2 - pixmap_height/2;
        if (dest_x >= 0 && dest_y >= 0)
        {
#ifdef MOZ_X11
            GC gc;
            gc = XCreateGC(This->display, This->window, 0, NULL);
            XCopyArea(This->display, GDK_WINDOW_XWINDOW(nullPluginGdkPixmap) , This->window, gc,
                0, 0, pixmap_with, pixmap_height, dest_x, dest_y);
            XFreeGC(This->display, gc);
#endif
        }
    }
}

static void
setCursor (PluginInstance *This)
{
#ifdef MOZ_X11
    static Cursor nullPluginCursor = 0;
    if (!nullPluginCursor)
    {
        nullPluginCursor = XCreateFontCursor(This->display, XC_hand2);
    }
    if (nullPluginCursor)
    {
        XDefineCursor(This->display, This->window, nullPluginCursor);
    }
#endif
}

#ifdef MOZ_X11
static void
xt_event_handler(Widget xt_w, PluginInstance *This, XEvent *xevent, Boolean *b)
{
    switch (xevent->type)
    {
        case Expose:
            /* get rid of all other exposure events */
            while(XCheckTypedWindowEvent(This->display, This->window, Expose, xevent));
            drawPixmap(This);
            break;
        case ButtonRelease:
            fprintf(stderr,"buttonrelease\n");
            glClearColor(1,0,0,1);
            glColor4f(1,0,0,0);
            glBegin(GL_POLYGON);
    	glVertex2f(0,0 );
	    glVertex2f(0,50 );
	    glVertex2f(50,50 );
	    glVertex2f(50,0 );
	    glEnd();
            SDL_GL_SwapBuffers();
            if (xevent->xbutton.button == Button1)
            {
                makeWidget(This);
            } 
            break;
        default:
            break;
    }
}
#endif

static void
addXtEventHandler(PluginInstance *This)
{
#ifdef MOZ_X11
     Display *dpy = (Display*) This->display;
     Window xwin = (Window) This->window;
     Widget xt_w = XtWindowToWidget(dpy, xwin);
     if (xt_w)
     {
         long event_mask = ExposureMask | ButtonReleaseMask | ButtonPressMask;
         XSelectInput(dpy, xwin, event_mask);
         XtAddEventHandler(xt_w, event_mask, False, (XtEventHandler)xt_event_handler, This);
     }
#endif
}


void
makePixmap(PluginInstance *This)
{
    createPixmap(This);
    drawPixmap(This);
    setCursor(This);
    addXtEventHandler(This);
}
