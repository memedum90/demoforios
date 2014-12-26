//
//  SpJSKobilAstFactory.h
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpJSKobilAstFactory__
#define __SpJSKobilAstFactory__

#if defined (__APPLE__) && !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

/**
 * SDKFactory object that's responsible for creating KobilAstSDK object with listener
 * And call static Freeing function of Ast
 */

bool spjskobilastfactory_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName);
JSValueRef spjskobilastfactory_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception);

static const JSClassDefinition spjskobilastfactory_def =
{
    0,                     // version
    kJSClassAttributeNone, // attributes
    "SDKFactory",        // className
    NULL,                  // parentClass
    NULL,                  // staticValues
    NULL,                   // staticFunctions
    NULL,                   // initialize
    NULL,                  // finalize
    spjskobilastfactory_has_property_cb,                  // hasProperty
    spjskobilastfactory_get_property_cb,                  // getProperty
    NULL,                  // setProperty
    NULL,                  // deleteProperty
    NULL,            	// getPropertyNames
    NULL,                  // callAsFunction
    NULL,                  // callAsConstructor
    NULL,                  // hasInstance
    NULL                   // convertToType
};

JSValueRef factorycreateast(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception);

JSValueRef factoryfreeast(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception);

#endif /* defined(__SpJSKobilAstFactory__) */
