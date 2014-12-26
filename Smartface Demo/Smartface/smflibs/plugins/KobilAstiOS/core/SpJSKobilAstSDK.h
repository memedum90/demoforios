//
//  SpJSKobilAstSDK.h
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpJSKobilAstSDK__
#define __SpJSKobilAstSDK__

#if defined (__APPLE__) && !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

/**
 * The main KobilAstSDK object
 * Has the functions' interface from JavaScript to Core
 */

void spjskobilastsdk_init_cb(JSContextRef ctx, JSObjectRef object);
void spjskobilastsdk_finalize_cb(JSObjectRef object);

static const JSClassDefinition spjskobilastsdk_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "KOBIL.AST.SDK",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjskobilastsdk_init_cb,  // initialize
    spjskobilastsdk_finalize_cb,                  // finalize
    NULL,                  // hasProperty
    NULL,                  // getProperty
    NULL,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};

#endif /* defined(__SpJSKobilAstSDK__) */
