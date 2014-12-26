//
//  SpJSKobilAstListener.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "SpJSKobilAstListener.h"
#include "SpJSKobilAstSDK.h"

const JSClassRef astListenerClassRef = JSClassCreate(&spjskobilastlistener_def);

JSObjectRef spjskobilastlistener_construct_cb(JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
    JSObjectRef kobilAstListenerObject = JSObjectMake(ctx, astListenerClassRef, (void*)NULL);
    /**
     * Listener object have event properties as array
     */
    if(argumentCount >= 1)
    {
        JSObjectRef arrObject = (JSObjectRef)arguments[0];
        JSPropertyNameArrayRef propertyNames = JSObjectCopyPropertyNames(ctx, arrObject);
        int count = JSPropertyNameArrayGetCount(propertyNames);
        for(int i = 0; i < count; i++)
        {
            JSStringRef propertyName = JSPropertyNameArrayGetNameAtIndex(propertyNames, i);
            JSValueRef valexception = NULL;
            JSValueRef value = JSObjectGetProperty(ctx, arrObject, propertyName, &valexception);
            JSObjectSetProperty(ctx, kobilAstListenerObject, propertyName, value, NULL, NULL);
            JSStringRelease(propertyName);
        }
    }
    
    return kobilAstListenerObject;
}
