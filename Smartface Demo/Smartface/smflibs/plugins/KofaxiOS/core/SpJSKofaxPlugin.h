//
//  SpJSKofaxPlugin.h
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpratIOS__SpJSKofaxPlugin__
#define __SpratIOS__SpJSKofaxPlugin__

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

#include "KofaxClass.h"
#include <stdio.h>

void spjskofaxplugin_init_cb(JSContextRef ctx, JSObjectRef object);
bool spjskofaxplugin_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName);
JSValueRef spjskofaxplugin_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception);
bool spjskofaxplugin_set_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception);

static const JSClassDefinition spjskofaxplugin_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "KOFAX",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjskofaxplugin_init_cb,  // initialize
    NULL,                  // finalize
    spjskofaxplugin_has_property_cb,                  // hasProperty
    spjskofaxplugin_get_property_cb,                  // getProperty
    spjskofaxplugin_set_property_cb,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};

#endif /* defined(__SpratIOS__SpJSKofaxPlugin__) */
