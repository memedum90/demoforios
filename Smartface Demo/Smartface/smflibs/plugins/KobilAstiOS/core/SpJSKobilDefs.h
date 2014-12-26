//
//  SpJSKobilDefs.h
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
 * JSClassDefinition connectect directly with player
 */

void spjskobil_init_cb(JSContextRef ctx, JSObjectRef object);
static const JSClassDefinition spjskobil_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "KOBIL",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjskobil_init_cb,  // initialize
    NULL,                  // finalize
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


/**
 * Deeper level JSClassDefinition
 */

void spjskobilast_init_cb(JSContextRef ctx, JSObjectRef object);
static const JSClassDefinition spjskobilast_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "KOBIL.AST",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL, // staticFunctions
    spjskobilast_init_cb,  // initialize
    NULL,                  // finalize
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

/**
 * Dummy JSClassDefinition for creating enum properties
 */

static const JSClassDefinition spjskobilenum_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "KOBIL.AST.Enums",           // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL,                   // staticFunctions
    NULL,                   // initialize
    NULL,                  // finalize
    NULL,                  // hasProperty
    NULL,                  // getProperty
    NULL,                  // setProperty
    NULL,                  // deleteProperty
    NULL,                   // getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};

#endif /* defined(__SpJSKobilAstSDK__) */
