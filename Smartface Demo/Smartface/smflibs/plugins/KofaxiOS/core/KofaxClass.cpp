//
//  KofaxClass.cpp
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include "KofaxClass.h"

static KofaxClass *kfxClass = NULL;

KofaxClass::KofaxClass() {
    functionObjectOnCapture = NULL;
    functionObjectOnCancelCapture = NULL;
    functionObjectOnErrorCapture = NULL;
    functionObjectOnSuccessProcess = NULL;
    functionObjectOnErrorProcess = NULL;
}

KofaxClass* KofaxClass::getInstance() {
	if (kfxClass == NULL) {
		kfxClass = new KofaxClass();
	}
	return kfxClass;
}

void KofaxClass::ImageCaptured(char *image) {
    if (functionObjectOnCapture) {
        int len = strlen(image) + 128;
        char* buf = new char[len];
        memset(buf, 0, len);
        sprintf(buf, "(function(){return {\"photoUri\" : \"%s\"};})()", image);
        
        JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
        JSValueRef exception = 0;
        JSValueRef cbarguments[] = {JSValueMakeNull(jsContext)};
        cbarguments[0] = JSEvaluateScript(jsContext, scriptJS, 0, 0, 0, &exception);
        delete []buf;
        
        JSObjectCallAsFunction(jsContext, functionObjectOnCapture, 0, 1, cbarguments, 0);
        
        JSStringRelease(scriptJS);
        JSValueUnprotect(jsContext, functionObjectOnCapture);
    }
    if (functionObjectOnErrorCapture) {
        JSValueUnprotect(jsContext, functionObjectOnErrorCapture);
    }
    if (functionObjectOnCancelCapture) {
        JSValueUnprotect(jsContext, functionObjectOnCancelCapture);
    }
    functionObjectOnCapture = NULL;
    functionObjectOnErrorCapture = NULL;
    functionObjectOnCancelCapture = NULL;
}

void KofaxClass::ImageCaptureCancelled() {
    if (functionObjectOnCapture) {
        JSValueUnprotect(jsContext, functionObjectOnCapture);
    }
    if (functionObjectOnErrorCapture) {
        JSValueUnprotect(jsContext, functionObjectOnErrorCapture);
    }
    if (functionObjectOnCancelCapture) {
        JSObjectCallAsFunction(jsContext, functionObjectOnCancelCapture, 0, 0, NULL, 0);
        JSValueUnprotect(jsContext, functionObjectOnCancelCapture);
    }
    functionObjectOnCapture = NULL;
    functionObjectOnErrorCapture = NULL;
    functionObjectOnCancelCapture = NULL;
}

void KofaxClass::ImageProcessed(char *image, char *imageMetaData, int width, int height) {
    if (functionObjectOnSuccessProcess) {
        int len = strlen(image) + strlen(imageMetaData) + 1208;
        char* buf = new char[len];
        memset(buf, 0, len);
        sprintf(buf, "(function(){return {\"photoUri\" : \"%s\",\"imageWidth\" : %d,\"imageHeight\" : %d, \"metaData\" : %s};})()", image, width, height, imageMetaData);

        JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
        JSValueRef exception = 0;
        JSValueRef cbarguments[] = {JSValueMakeNull(jsContext)};
        cbarguments[0] = JSEvaluateScript(jsContext, scriptJS, 0, 0, 0, &exception);
        delete []buf;
        
        JSObjectCallAsFunction(jsContext, functionObjectOnSuccessProcess, 0, 1, cbarguments, 0);
        
        JSStringRelease(scriptJS);
        JSValueUnprotect(jsContext, functionObjectOnSuccessProcess);
    }
    if (functionObjectOnErrorProcess) {
        JSValueUnprotect(jsContext, functionObjectOnErrorProcess);
    }
    functionObjectOnErrorProcess = NULL;
    functionObjectOnSuccessProcess = NULL;
}

void KofaxClass::ImageProcessError(char *errorMessage) {
    if (functionObjectOnErrorProcess) {
        int len = strlen(errorMessage) + 128;
        char* buf = new char[len];
        memset(buf, 0, len);
        sprintf(buf, "(function(){return {\"message\" : \"%s\"};})()", errorMessage);
        
        JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
        JSValueRef exception = 0;
        JSValueRef cbarguments[] = {JSValueMakeNull(jsContext)};
        cbarguments[0] = JSEvaluateScript(jsContext, scriptJS, 0, 0, 0, &exception);
        delete []buf;
        
        JSObjectCallAsFunction(jsContext, functionObjectOnErrorProcess, 0, 1, cbarguments, 0);
        
        JSStringRelease(scriptJS);
        JSValueUnprotect(jsContext, functionObjectOnErrorProcess);
    }
    if (functionObjectOnSuccessProcess) {
        JSValueUnprotect(jsContext, functionObjectOnSuccessProcess);
    }
    functionObjectOnErrorProcess = NULL;
    functionObjectOnSuccessProcess = NULL;
}

void KofaxClass::SetKofaxCallbackFunction(JSObjectRef arrObject, const char *functionName) {
    if (strcmp(functionName, "openCaptureScreen") == 0) {
        JSStringRef jspropertyName = JSStringCreateWithUTF8CString("onCapture");
        if(JSObjectHasProperty(jsContext, arrObject, jspropertyName)) {
            functionObjectOnCapture = (JSObjectRef)JSObjectGetProperty(jsContext, arrObject, jspropertyName, NULL);
            JSValueProtect(jsContext, functionObjectOnCapture);
        }
        JSStringRelease(jspropertyName);
        
        jspropertyName = JSStringCreateWithUTF8CString("onCancel");
        if(JSObjectHasProperty(jsContext, arrObject, jspropertyName)) {
            functionObjectOnCancelCapture = (JSObjectRef)JSObjectGetProperty(jsContext, arrObject, jspropertyName, NULL);
            JSValueProtect(jsContext, functionObjectOnCancelCapture);
        }
        JSStringRelease(jspropertyName);
        
        jspropertyName = JSStringCreateWithUTF8CString("onError");
        if(JSObjectHasProperty(jsContext, arrObject, jspropertyName)) {
            functionObjectOnErrorCapture = (JSObjectRef)JSObjectGetProperty(jsContext, arrObject, jspropertyName, NULL);
            JSValueProtect(jsContext, functionObjectOnErrorCapture);
        }
        JSStringRelease(jspropertyName);
    } else if (strcmp(functionName, "processImage") == 0) {
        JSStringRef jspropertyName = JSStringCreateWithUTF8CString("onSuccess");
        if(JSObjectHasProperty(jsContext, arrObject, jspropertyName)) {
            functionObjectOnSuccessProcess = (JSObjectRef)JSObjectGetProperty(jsContext, arrObject, jspropertyName, NULL);
            JSValueProtect(jsContext, functionObjectOnSuccessProcess);
        }
        JSStringRelease(jspropertyName);
        
        jspropertyName = JSStringCreateWithUTF8CString("onError");
        if(JSObjectHasProperty(jsContext, arrObject, jspropertyName)) {
            functionObjectOnErrorProcess = (JSObjectRef)JSObjectGetProperty(jsContext, arrObject, jspropertyName, NULL);
            JSValueProtect(jsContext, functionObjectOnErrorProcess);
        }
        JSStringRelease(jspropertyName);
    }
}

OptionParameter::OptionParameter() {
    stabilityDelay = -1;
    levelIndicator = false;
    doContinues = false;
    setPageDetect = false;
    levelThresholdPitch = -1;
    levelTresholdRoll = -1;
    deviceDeclinationPitch = -1;
    deviceDeclinationRoll = -1;
    flash = -1;
    showFlashControl = false;
    overlayImg = NULL;
}

OptionParameter::~OptionParameter() {
    if (overlayImg)
        delete overlayImg;
}


