/*
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
 */

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#define MIME_TYPES_HANDLED  "application/x-secondlife:sl:Second Life(tm) Client"
#define PLUGIN_NAME         "Second Life(tm) Client"
#define PLUGIN_DESCRIPTION  "Second Life in firefox, for the win"
#include <gtk/gtk.h>

typedef struct _PluginInstance
{
    uint16 mode;
#ifdef MOZ_X11
    Window window;
    Display *display;
#endif
    uint32 x, y;
    uint32 width, height;
    NPMIMEType type;
    char *message;

    NPP instance;
    char *pluginsPageUrl;
    char *pluginsFileUrl;
    NPBool pluginsHidden;
#ifdef MOZ_X11
    Visual* visual;
    Colormap colormap;
#endif
    unsigned int depth;
    GtkWidget* dialogBox;

    NPBool exists;  
    int action; 

} PluginInstance;

typedef struct _MimeTypeElement
{
    PluginInstance *pinst;
    struct _MimeTypeElement *next;
} MimeTypeElement;

/* Extern functions */
extern void makeWidget(PluginInstance *This);
extern NPMIMEType dupMimeType(NPMIMEType type);
extern void destroyWidget(PluginInstance *This);
extern void makePixmap(PluginInstance *This);
extern void destroyPixmap();
extern NPMIMEType dupMimeType(NPMIMEType type);
extern NPError NPP_GetValue(NPP instance, NPPVariable variable, void *value);

