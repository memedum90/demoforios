/*
 *	Minimum SES plugin
 *
 *  Created by Antti Panula (antti@slicewireless.com) on 11.12.2013
 *  Copyright (c) 2013 Bivium Oy. All rights reserved.
 */
 
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "DPPlugin.h"
#include "SPJSDPPlugin.h"

extern "C"{

JavaVM* g_jvm = NULL;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void * reserved)
{
    g_jvm = vm;
    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM *vm, void *reserved)
{
    g_jvm = NULL;
}
void Java_com_vasco_digipass_sdk_smartfaceplugin_PluginImp_initNative(JNIEnv *env, jobject thiz,jlong jsContext,jlong envMap)
{
	long jscontextlong = (long)jsContext;
	DPPlugin* instance = DPPlugin::getInstance();
	instance->jsContext = (JSContextRef)jsContext;
	instance->envMap = (std::map<long,JNIEnv*>*)envMap;
	instance->pluginImpObject = env->NewGlobalRef(thiz);
    jclass clazz = env->GetObjectClass(thiz);
    jmethodID initMethod = env->GetMethodID(clazz,"init","(Ljava/lang/String;)V");
    jstring fingerprint = env->NewStringUTF(DBFINGERPRINT);
    env->CallVoidMethod(thiz,initMethod,fingerprint);
    env->DeleteLocalRef(fingerprint);
    instance->getBytes = env->GetMethodID(clazz,"getBytes","(Ljava/lang/String;)[B");
    instance->putBytes = env->GetMethodID(clazz,"putBytes","(Ljava/lang/String;Ljava/lang/String;[B)Z");
    instance->initializeRegistrationDataV2JavaFunction = env->GetMethodID(clazz,"initializeRegistrationDataV2","(Ljava/lang/String;[Z)Ljava/lang/String;");
    instance->decryptActivationDataJavaFunction = env->GetMethodID(clazz,"decryptActivationData","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Z)Ljava/lang/String;");
    instance->validateSharedDataChecksumJavaFunction = env->GetMethodID(clazz,"validateSharedDataChecksum","(Ljava/lang/String;[Z)Ljava/lang/String;");
    env->DeleteLocalRef(clazz);
    JSStringRef str = JSStringCreateWithUTF8CString("VASCO");
	JSClassRef classDef = JSClassCreate(&spjsdpplugin_def);
	JSObjectRef classObj = JSObjectMake(instance->jsContext, classDef, (void*)DPPlugin::getInstance());
	JSObjectSetProperty(instance->jsContext, JSContextGetGlobalObject(instance->jsContext), str, classObj, kJSPropertyAttributeNone, NULL);
    JSClassRelease(classDef);
	JSStringRelease(str);
}

}
