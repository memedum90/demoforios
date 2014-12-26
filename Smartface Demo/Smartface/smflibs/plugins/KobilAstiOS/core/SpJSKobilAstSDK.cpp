//
//  SpJSKobilAstSDK.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "KobilAstEnums.h"
#include "SpJSKobilAstSDK.h"
#include "SpJSKobilAstSDKFunctions.h"
#include "KobilAstSDK.h"

void spjskobilastsdk_init_cb(JSContextRef ctx, JSObjectRef object)
{
    // Define functions
    JSStringRef str = JSStringCreateWithUTF8CString("init");
    JSObjectRef functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkInit);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("exit");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkExit);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doActivation");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoActivation);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doLogin");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoLogin);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doPinChangeRequest");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoPinChangeRequest);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doPinChange");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoPinChange);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doSetPropertyRequest");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoSetPropertyRequest);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doSetProperty");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoSetProperty);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doTransaction");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoTransaction);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("doDeactivate");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkDoDeactivate);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("resume");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkResume);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
    
    str = JSStringCreateWithUTF8CString("suspend");
    functionObjectRef = JSObjectMakeFunctionWithCallback(ctx, str, sdkSuspend);
    JSObjectSetProperty(ctx, object, str, functionObjectRef, NULL, NULL);
    JSStringRelease(str);
}

void spjskobilastsdk_finalize_cb(JSObjectRef object) {
    KobilAstSDK *sdkObject = (KobilAstSDK*)JSObjectGetPrivate(object);
    delete sdkObject;
}

