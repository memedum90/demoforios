/*
 *	Minimum SES plugin
 *
 *  Created by Antti Panula (antti@slicewireless.com) on 24.9.2014
 *  Copyright (c) 2014 Bivium Oy. All rights reserved.
 */

#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "KobilAstContextHolder.h"
#include "SpJSKobilDefs.h"

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

void Java_com_kobil_ast_smartfaceplugin_PluginImp_initNative(JNIEnv *env, jobject thiz,jlong jsContext,jlong envMap)
{
	long jscontextlong = (long)jsContext;
    KobilAstContextHolder *contextHolder = KobilAstContextHolder::getInstance();
    contextHolder->ctx = (JSContextRef)jsContext;
    contextHolder->envMap = (std::map<long,JNIEnv*>*)envMap;
    contextHolder->pluginImpObject = env->NewGlobalRef(thiz);

    JSStringRef str = JSStringCreateWithUTF8CString("KOBIL");
	JSClassRef classDef = JSClassCreate(&spjskobil_def);
	JSObjectRef classObj = JSObjectMake(contextHolder->ctx, classDef, (void*)KobilAstContextHolder::getInstance());
	JSObjectSetProperty(contextHolder->ctx, JSContextGetGlobalObject(contextHolder->ctx), str, classObj, kJSPropertyAttributeNone, NULL);
    JSClassRelease(classDef);
    jclass clazz = env->GetObjectClass(thiz);
    contextHolder->createKobilAstSDK = env->GetMethodID(clazz,"createKobilAstSDK__N","()Ljava/lang/Object;");
    env->DeleteLocalRef(clazz);
    JSStringRelease(str);

}

}
