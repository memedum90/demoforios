//
//  SpJSKofaxFuncDefs.cpp
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include "SpJSKofaxFuncDefs.h"
#include "SpJSKofaxPlugin.h"
#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#include "SpJSCommon.h"
#endif
#include <string.h>


JSValueRef kfx_setSDKLicense(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception){
    KofaxClass* kfxClass = KofaxClass::getInstance();
    char *licenseStr;
    if (argumentCount == 1 && JSValueIsString(ctx, arguments[0])){
        JSStringRef jsStringVal = JSValueToStringCopy(ctx, arguments[0], NULL);
        size_t jsSize = JSStringGetMaximumUTF8CStringSize(jsStringVal);
        licenseStr = (char*)malloc(jsSize);
        JSStringGetUTF8CString(jsStringVal, licenseStr, jsSize);
        JSStringRelease(jsStringVal);
        kfxClass->SetSDKLicense(licenseStr);
    }
    return JSValueMakeNull(ctx);
}

JSValueRef kfx_openCaptureScreen(JSContextRef ctx,
                                 JSObjectRef function,
                                 JSObjectRef thisObject,
                                 size_t argumentCount,
                                 const JSValueRef arguments[],
                                 JSValueRef* exception){
    KofaxClass* kfxClass = KofaxClass::getInstance();
    OptionParameter * options = NULL;
    
    if (argumentCount == 1 && JSValueIsObject(ctx, arguments[0])){
        JSObjectRef arrObject = (JSObjectRef)arguments[0];
        kfxClass->SetKofaxCallbackFunction(arrObject, "openCaptureScreen");
        
        JSObjectRef optionsObject = (JSObjectRef)kfx_getArrayObject(ctx, arrObject, "options");
        if (optionsObject) {
            options = new OptionParameter();
            
            JSValueRef optionRef = kfx_getArrayObject(ctx, optionsObject, "stabilityDelay");
            options->stabilityDelay = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "levelIndicator");
            options->levelIndicator = JSValueToBoolean(ctx, optionRef);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "doContinuousMode");
            options->doContinues = JSValueToBoolean(ctx, optionRef);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "setPageDetect");
            options->setPageDetect = JSValueToBoolean(ctx, optionRef);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "levelThresholdPitch");
            options->levelThresholdPitch = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "levelThresholdRoll");
            options->levelTresholdRoll = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "deviceDeclinationPitch");
            options->deviceDeclinationPitch = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "deviceDeclinationRoll");
            options->deviceDeclinationRoll = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "flash");
            options->flash = JSValueToNumber(ctx, optionRef, NULL);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "showFlashControl");
            options->showFlashControl = JSValueToBoolean(ctx, optionRef);
            
            optionRef = kfx_getArrayObject(ctx, optionsObject, "overlayImage");
            if (optionRef) {
                JSStringRef imageStringRef = JSValueToStringCopy(ctx, optionRef, NULL);
                size_t jsSize = JSStringGetMaximumUTF8CStringSize(imageStringRef);
                options->overlayImg = (char*)malloc(jsSize);
                JSStringGetUTF8CString(imageStringRef, options->overlayImg, jsSize);
                JSStringRelease(imageStringRef);
            }
        }

        kfxClass->OpenCaptureScreen(options);
        
        if (options)
            delete options;
    }
    return JSValueMakeNull(ctx);
}


JSValueRef kfx_processImage(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception){
    KofaxClass* kfxClass = KofaxClass::getInstance();
    char *imageUri = NULL;
    char *imagePerfectionProfile = NULL;
    if (argumentCount == 1 && JSValueIsObject(ctx, arguments[0])){
        JSObjectRef arrObject = (JSObjectRef)arguments[0];
        kfxClass->SetKofaxCallbackFunction(arrObject, "processImage");
        
        JSValueRef imageRef = kfx_getArrayObject(ctx, arrObject, "image");
        if (imageRef) {
            JSStringRef imageStringRef = JSValueToStringCopy(ctx, imageRef, NULL);
            size_t jsSize = JSStringGetMaximumUTF8CStringSize(imageStringRef);
            imageUri = (char*)malloc(jsSize);
            JSStringGetUTF8CString(imageStringRef, imageUri, jsSize);
            JSStringRelease(imageStringRef);
        }
        
        JSValueRef imagePerfectionProfileRef = kfx_getArrayObject(ctx, arrObject, "imagePerfectionProfile");
        if (imagePerfectionProfileRef)
        {
            JSStringRef imageStringRef = JSValueToStringCopy(ctx, imagePerfectionProfileRef, NULL);
            size_t jsSize = JSStringGetMaximumUTF8CStringSize(imageStringRef);
            imagePerfectionProfile = (char*)malloc(jsSize);
            JSStringGetUTF8CString(imageStringRef, imagePerfectionProfile, jsSize);
            JSStringRelease(imageStringRef);
        }

        if (imageUri && imagePerfectionProfile)
        {
            kfxClass->ProcessImg(imageUri, imagePerfectionProfile);
        }
        
        if (imageUri)
            free(imageUri);
        if (imagePerfectionProfile)
            free(imagePerfectionProfile);
    }
    return JSValueMakeNull(ctx);
}

JSValueRef kfx_getArrayObject(JSContextRef ctx, JSObjectRef arrayRef, const char *property) {
    JSValueRef retVal = NULL;
    JSStringRef jspropertyName = JSStringCreateWithUTF8CString(property);
    if (JSObjectHasProperty(ctx, arrayRef, jspropertyName)) {
        retVal = JSObjectGetProperty(ctx, arrayRef, jspropertyName, NULL);
    }
    JSStringRelease(jspropertyName);
    return retVal;
}
