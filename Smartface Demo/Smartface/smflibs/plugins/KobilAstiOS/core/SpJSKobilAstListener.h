//
//  SpJSKobilAstListener.h
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpJSKobilAstListener__
#define __SpJSKobilAstListener__

#if defined (__APPLE__) && !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

JSObjectRef spjskobilastlistener_construct_cb(JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
static const JSClassDefinition spjskobilastlistener_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "SDKListener",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL,                   // staticFunctions
    NULL,                   // initialize
    NULL,                  // finalize
    NULL,                  // hasProperty
    NULL,                  // getProperty
    NULL,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    spjskobilastlistener_construct_cb,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};

extern const JSClassRef astListenerClassRef;

#endif /* defined(__SpJSKobilAstListener__) */