//
//  SpJSKofaxPlugin.cpp
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include "SpJSKofaxPlugin.h"
#include "SpJSKofaxFuncDefs.h"

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

#include <stdlib.h>
#include <string.h>

void spjskofaxplugin_init_cb(JSContextRef ctx, JSObjectRef object){

}

bool spjskofaxplugin_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName){
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char *)malloc(propertySize * sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    
    // Checking property names , if class includes or not.
 	if(strcmp("setSDKLicense",property) == 0)
    {
        ret = true;
    }
    else if(strcmp("openCaptureScreen",property) == 0)
    {
        ret = true;
    }
    else if(strcmp("processImage",property) == 0)
    {
        ret = true;
    }
    
    free(property);
    return ret;
}

JSValueRef spjskofaxplugin_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception){

    bool ret = false;
    JSValueRef retval;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    
    
    // Function to get all properties of Class.
    // For now these are all functions. But you can add a variable.
    if (strcmp("setSDKLicense", property) == 0){
        JSStringRef str = JSStringCreateWithUTF8CString("setSDKLicense");
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, kfx_setSDKLicense);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp("openCaptureScreen", property) == 0){
        JSStringRef str = JSStringCreateWithUTF8CString("openCaptureScreen");
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, kfx_openCaptureScreen);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp("processImage",property) == 0)
    {
        JSStringRef str = JSStringCreateWithUTF8CString("processImage");
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, kfx_processImage);
        JSStringRelease(str);
        ret = true;
    }

    free(property);
    return retval;

}

bool spjskofaxplugin_set_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception){
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    
    /*
    if(strcmp("optOut",property) == 0 )
    {
        ret = js_set_optOut(ctx,value);
    }*/
    free(property);
    return ret;
}