//
//  SPJSDPPlugin.h
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//

#ifndef __Smartface__SPJSDPPlugin__
#define __Smartface__SPJSDPPlugin__

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif
#include "SPJSDPPluginDefs.h"


void spjsdpplugin_init_cb(JSContextRef ctx, JSObjectRef object);
bool spjsdpplugin_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName);
JSValueRef spjsdpplugin_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception);
bool spjsdpplugin_set_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception);

void spjsdata_init_cb(JSContextRef ctx, JSObjectRef object);
bool spjsdata_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName);
JSValueRef spjsdata_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception);

static const JSClassDefinition spjsdpplugin_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    kDPPluginIdentifier,        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjsdpplugin_init_cb,  // initialize
    NULL,                  // finalize
    spjsdpplugin_has_property_cb,                  // hasProperty
    spjsdpplugin_get_property_cb,                  // getProperty
    spjsdpplugin_set_property_cb,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};


static const JSClassDefinition spjsdata_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    kDataIdentifier,        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjsdata_init_cb,  // initialize
    NULL,                  // finalize
    spjsdata_has_property_cb,                  // hasProperty
    spjsdata_get_property_cb,                  // getProperty
    NULL,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};


#endif /* defined(__Smartface__SPJSDPPlugin__) */
