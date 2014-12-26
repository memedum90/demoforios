//
//  KofaxClass.h
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpratIOS__KofaxClass__
#define __SpratIOS__KofaxClass__

#include <iostream>
#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif
#include <string>
#include <pthread.h>
#include <map>

#ifdef ANDROID_NDK
#include <jni.h>
#endif

class SpBrNuiSmfImage;

class OptionParameter{
public:
    OptionParameter();
    ~OptionParameter();
    
    int stabilityDelay;
    bool levelIndicator;
    bool doContinues;
    bool setPageDetect;
    int levelThresholdPitch;
    int levelTresholdRoll;
    int deviceDeclinationPitch;
    int deviceDeclinationRoll;
    int flash;
    bool showFlashControl;
    char *overlayImg;
};

class KofaxClass {
public:
#ifdef ANDROID_NDK
	jobject pluginImpObject;
	std::map<pthread_t,JNIEnv*> *envMap;
	JNIEnv* GetJNIEnv();
#endif
	KofaxClass();
	~KofaxClass();
    
    static KofaxClass* getInstance();
    
public:
    void SetSDKLicense(char* licenseStr);
    void OpenCaptureScreen(OptionParameter* temp);
    void ProcessImg(char *imgUrl,char *profile);
    
    void ImageCaptured(char *image);
    void ImageCaptureCancelled();
    void ImageProcessed(char *image, char *imageMetaData, int width, int height);
    void ImageProcessError(char *errorMessage);

public:
    void SetKofaxCallbackFunction(JSObjectRef arrObject, const char *functionName);
    
public:
	JSContextRef jsContext;
    
private:
    JSObjectRef functionObjectOnCapture;
    JSObjectRef functionObjectOnCancelCapture;
    JSObjectRef functionObjectOnErrorCapture;
    JSObjectRef functionObjectOnSuccessProcess;
    JSObjectRef functionObjectOnErrorProcess;
};

#endif
