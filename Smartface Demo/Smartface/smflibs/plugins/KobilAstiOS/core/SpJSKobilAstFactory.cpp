//
//  SpJSKobilAstFactory.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "SpJSKobilAstFactory.h"
#include "SpJSKobilAstSDK.h"
#include "SpJSKobilAstListener.h"
#include "KobilAstSDK.h"
#include "KobilAstContextHolder.h"

bool spjskobilastfactory_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName)
{
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char *)malloc(propertySize * sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
 	if(strcmp("createAST", property) == 0)
    {
        ret = true;
    }
    else if(strcmp("freeAST", property) == 0)
    {
        ret = true;
    }
    free(property);
    return ret;
}

JSValueRef spjskobilastfactory_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    bool ret = false;
    JSValueRef retval;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    if(strcmp("createAST", property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString("createAST");
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, factorycreateast);
        JSStringRelease(str);
        ret = true;
    } else if(strcmp("freeAST", property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString("freeAST");
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, factoryfreeast);
        JSStringRelease(str);
        ret = true;
    }
    free(property);
    return retval;
}

JSValueRef factorycreateast(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception)
{
    if (argumentCount == 1 && JSValueIsObjectOfClass(ctx, arguments[0], astListenerClassRef)) {
        KobilAstContextHolder *contextHolder = KobilAstContextHolder::getInstance();
        
        KobilAstSDK *sdk = new KobilAstSDK();
        sdk->SetListener(contextHolder->ctx, (JSObjectRef)arguments[0]);
        return sdk->GetKobilJSObjectRef(contextHolder->ctx);
    } else {
        JSStringRef str = JSStringCreateWithUTF8CString("Passed arguments are not correct!");
        JSValueRef argumentsErrorValues[] = { JSValueMakeString(ctx, str) };
        JSStringRelease(str);
        *exception = JSObjectMakeError(ctx, 1, argumentsErrorValues, NULL);
    }
    return JSValueMakeNull(ctx);
}

JSValueRef factoryfreeast(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception)
{
    KobilAstSDK::FactoryFreeAst();
    return JSValueMakeNull(ctx);
}


