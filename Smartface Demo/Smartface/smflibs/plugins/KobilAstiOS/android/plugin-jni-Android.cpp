/*
 *	Minimum SES plugin
 *
 *  Created by Antti Panula (antti@slicewireless.com) on 11.12.2013
 *  Copyright (c) 2013 Bivium Oy. All rights reserved.
 */
 
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "inc/JavaScriptCore.h"
#include "KobilAstSDK.h"
#include "SpJSKobilDefs.h"
#include "SpContext.h"

#define USE_THREADS_FOR_EVENTS 0

extern "C"{

JavaVM* g_jvm = NULL;
pthread_mutex_t onActivationBeginLock;
pthread_mutex_t onActivationEndLock;
pthread_mutex_t onLoginBeginLock;
pthread_mutex_t onLoginEndLock;
pthread_mutex_t onPinChangeBeginLock;
pthread_mutex_t onPinChangeEndLock;
pthread_mutex_t onTransactionBeginLock;
pthread_mutex_t onTransactionEndLock;
pthread_mutex_t onAlertLock;
pthread_mutex_t onSetPropertyBeginLock;
pthread_mutex_t onSetPropertyEndLock;
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void * reserved)
{
    g_jvm = vm;
    pthread_mutex_init(&onActivationBeginLock, NULL);
    pthread_mutex_init(&onActivationEndLock, NULL);
    pthread_mutex_init(&onLoginBeginLock, NULL);
    pthread_mutex_init(&onLoginEndLock, NULL);
    pthread_mutex_init(&onPinChangeBeginLock, NULL);
    pthread_mutex_init(&onPinChangeEndLock, NULL);
    pthread_mutex_init(&onTransactionBeginLock, NULL);
    pthread_mutex_init(&onTransactionEndLock, NULL);
    pthread_mutex_init(&onAlertLock, NULL);
    pthread_mutex_init(&onSetPropertyBeginLock, NULL);
    pthread_mutex_init(&onSetPropertyEndLock, NULL);
    __android_log_print(ANDROID_LOG_ERROR,"KobilASTClass","----------------------------------- initNative vm: %d ", (int)vm);
    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM *vm, void *reserved)
{
    pthread_mutex_destroy(&onActivationBeginLock);
    pthread_mutex_destroy(&onActivationEndLock);
    pthread_mutex_destroy(&onLoginBeginLock);
    pthread_mutex_destroy(&onLoginEndLock);
    pthread_mutex_destroy(&onPinChangeBeginLock);
    pthread_mutex_destroy(&onPinChangeEndLock);
    pthread_mutex_destroy(&onTransactionBeginLock);
    pthread_mutex_destroy(&onTransactionEndLock);
    pthread_mutex_destroy(&onAlertLock);
    pthread_mutex_destroy(&onSetPropertyBeginLock);
    pthread_mutex_destroy(&onSetPropertyEndLock);
    g_jvm = NULL;
}

struct OnActivationBeginArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
};

struct OnActivationEndArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
};

class OnLoginBeginArgs{
public:
	OnLoginBeginArgs(){};
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	std::vector<std::string> userIdList;
};

class OnDeactivateEndArgs{
public:
	OnDeactivateEndArgs(){};
	KobilAstSDK * sdk;
	KAstStatus status;
	std::vector<std::string> userIdList;
};


struct OnLoginEndArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
	const char* loginOtp;
	const char* userId;
	int retryCounter;
	int retryDelay;
};

struct OnPinChangeBeginArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
};

struct OnPinChangeEndArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
	int retryCounter;
};

struct OnTransactionBeginArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	const char* displayData;
	KAstConfirmationType confirmationType;
};

struct OnTransactionEndArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
};

struct OnAlertArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	unsigned int subSystem;
	unsigned int errorCode;
};

struct OnSetPropertyBeginArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
};

struct OnSetPropertyEndArgs{
	KobilAstSDK * sdk;
	KAstDeviceType deviceType;
	KAstStatus status;
	uint32_t subSystem;
	uint32_t errorCode;
};

void *onActivationBeginFunc(void * args) {
	//pthread_mutex_lock(&onActivationBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onActivationBeginFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnActivationBeginArgs * arguments = (OnActivationBeginArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	sdk->onActivationBegin(deviceType);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onActivationBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onActivationBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onActivationEndFunc(void * args) {
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onActivationEndFunc  1  threadid: %d", (int)pthread_self());
	//pthread_mutex_lock(&onActivationEndLock);
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnActivationEndArgs *arguments = (OnActivationEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	sdk->onActivationEnd(deviceType, status);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onActivationEndFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onActivationEndLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onLoginBeginFunc(void * args) {
	//pthread_mutex_lock(&onLoginBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onLoginBeginFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnLoginBeginArgs *arguments = (OnLoginBeginArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	std::vector<std::string> userIdList = arguments->userIdList;
	sdk->onLoginBegin(deviceType, userIdList);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onLoginBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onLoginBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onDeactivateEndFunc(void * args) {
	//pthread_mutex_lock(&onLoginBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onDeactivateEndFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    //JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	/*pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}*/

	OnDeactivateEndArgs *arguments = (OnDeactivateEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstStatus status = arguments->status;
	__android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onDeactivateEndFunc  1.5  threadid: %d", (int)pthread_self());
	sdk->onDeactivateEnd((KAstStatus)status, arguments->userIdList);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onLoginBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onLoginBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onLoginEndFunc(void * args) {
	//pthread_mutex_lock(&onLoginEndLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onLoginEndFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnLoginEndArgs *arguments = (OnLoginEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	const char* loginOtp = arguments->loginOtp;
	const char* userId = arguments->userId;
	int retryCounter = arguments->retryCounter;
	int retryDelay = arguments->retryDelay;
	sdk->onLoginEnd(deviceType, status, loginOtp, userId, retryCounter, retryDelay);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onLoginEndFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onLoginEndLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onPinChangeBeginFunc(void * args) {
	//pthread_mutex_lock(&onPinChangeBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onPinChangeBeginFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnPinChangeBeginArgs *arguments = (OnPinChangeBeginArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	sdk->onPinChangeBegin(deviceType, status);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onPinChangeBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onPinChangeBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onPinChangeEndFunc(void * args) {
	//pthread_mutex_lock(&onPinChangeEndLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onPinChangeEndFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnPinChangeEndArgs *arguments = (OnPinChangeEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	int retryCounter = arguments->retryCounter;
	sdk->onPinChangeEnd(deviceType, status, retryCounter);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onPinChangeEndFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onPinChangeEndLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onTransactionBeginFunc(void * args) {
	//pthread_mutex_lock(&onTransactionBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onTransactionBeginFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnTransactionBeginArgs *arguments = (OnTransactionBeginArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	const char* displayData = arguments->displayData;
	KAstConfirmationType confirmationType = arguments->confirmationType;
	sdk->onTransactionBegin(deviceType, displayData, confirmationType);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onTransactionBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onTransactionBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onTransactionEndFunc(void * args) {
	//pthread_mutex_lock(&onTransactionEndLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onTransactionEndFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}


	OnTransactionEndArgs *arguments = (OnTransactionEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	sdk->onTransactionEnd(deviceType, status);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onTransactionEndFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onTransactionEndLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onAlertFunc(void * args) {
	//pthread_mutex_lock(&onAlertLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onAlertFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif

	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnAlertArgs *arguments = (OnAlertArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	unsigned int subSystem = arguments->subSystem;
	unsigned int errorCode = arguments->errorCode;
	sdk->onAlert(deviceType, subSystem, errorCode);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onAlertFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onAlertLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onSetPropertyBeginFunc(void * args) {
	//pthread_mutex_lock(&onSetPropertyBeginLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onSetPropertyBeginFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif
	pthread_t threadid = pthread_self();
	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnSetPropertyBeginArgs *arguments = (OnSetPropertyBeginArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	sdk->onSetPropertyBegin(deviceType, status);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onSetPropertyBeginFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onSetPropertyBeginLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void *onSetPropertyEndFunc(void * args) {
	//pthread_mutex_lock(&onSetPropertyEndLock);
	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onSetPropertyEndFunc  1  threadid: %d", (int)pthread_self());
	jint res;
    JNIEnv* env = NULL;
    JavaVM* jvm = g_jvm;
#if USE_THREADS_FOR_EVENTS
    res = jvm->AttachCurrentThread (&env, NULL);
#endif
	pthread_t threadid = pthread_self();

	if(KobilAstSDK::envMap->find(threadid) == KobilAstSDK::envMap->end()) {
		(*(KobilAstSDK::envMap))[threadid] = env;
		(*(KobilAstSDK::envMap))[threadid] = env;
	}

	OnSetPropertyEndArgs *arguments = (OnSetPropertyEndArgs *) args;
	KobilAstSDK *sdk = arguments->sdk;
	KAstDeviceType deviceType = arguments->deviceType;
	KAstStatus status = arguments->status;
	uint32_t subSystem = arguments->subSystem;
	uint32_t errorCode = arguments->errorCode;
	sdk->onSetPropertyEnd(deviceType, status, subSystem, errorCode);

	 __android_log_print(ANDROID_LOG_DEBUG,"KobilASTClass","----------------------------------- onSetPropertyEndFunc  2  threadid: %d", (int)pthread_self());
#if USE_THREADS_FOR_EVENTS
	jvm->DetachCurrentThread();
	//pthread_mutex_unlock(&onSetPropertyEndLock);
	pthread_exit(NULL);
#endif
	return NULL;
}

void Java_com_kobil_ast_smartfaceplugin_PluginImp_initNative(JNIEnv *env, jobject thiz,jlong jsContext,jlong envMap)
{
	KobilAstSDK::envMap = (std::map<pthread_t,JNIEnv*>*)envMap;
	KobilAstSDK::pluginImpObject = env->NewGlobalRef(thiz);
	JSContextRef ctx = (JSContextRef)jsContext;

	__android_log_print(ANDROID_LOG_ERROR,"KobilASTClass","----------------------------------- initNative ctx: %d 1", (int)ctx);
	JSClassRef classDef1 = JSClassCreate(&spjskobil_def);
	JSObjectRef classObj1 = JSObjectMake(ctx, classDef1, NULL);
    JSStringRef str1 = JSStringCreateWithUTF8CString("KOBIL");
    JSObjectSetProperty(ctx, JSContextGetGlobalObject(ctx), str1, classObj1, kJSPropertyAttributeNone, NULL);
    JSClassRelease(classDef1);
}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_setJSContextRef(JNIEnv *env, jobject thiz, jlong nativeObjRef, jlong jsContextRef)
{
	/*if(nativeObjRef != 0ll) {
		__android_log_print(ANDROID_LOG_ERROR,"KobilASTClass","----------------------------------- jsContextRef: %d", (int)jsContextRef);
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		astSdk->SetContextRef((JSContextRef)jsContextRef);
	}*/

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onActivationBegin(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0ll) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnActivationBeginArgs *arguments = (OnActivationBeginArgs*)malloc(sizeof(OnActivationBeginArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onActivationBeginFunc, arguments);
#else
    	onActivationBeginFunc(arguments);
#endif
	}
}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onActivationEnd(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint status)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0ll) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnActivationEndArgs *arguments = (OnActivationEndArgs*)malloc(sizeof(OnActivationEndArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus)status;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onActivationEndFunc, arguments);
#else
    	onActivationEndFunc(arguments);
#endif
	}

}


void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onLoginBegin(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jobjectArray juserIdList)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	int stringCount = 0;
	if(juserIdList){
		stringCount = env->GetArrayLength(juserIdList);
	}
	std::vector<std::string> userIdList;
	if (nativeObjRef != 0ll) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnLoginBeginArgs *arguments = new OnLoginBeginArgs();//(OnLoginBeginArgs*)malloc(sizeof(OnLoginBeginArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		for (int i = 0; i < stringCount; i++) {
			jstring string = (jstring) env->GetObjectArrayElement(juserIdList, i);
			jboolean isCopy;
			const char *rawString = env->GetStringUTFChars(string, &isCopy);
			std::string str(strdup(rawString));
			env->ReleaseStringUTFChars(string, rawString);
			arguments->userIdList.push_back(str);
		}
#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onLoginBeginFunc, arguments);
#else
    	onLoginBeginFunc(arguments);
#endif

	}

}


void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onLoginEnd(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType,
		jint status, jstring jloginOtp, jstring juserId, jint retryCounter, jint retryDelay)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	const char* loginOtp;
	const char* userId;
	if(jloginOtp != NULL) {
		jboolean isCopy;
		const char *rawString = env->GetStringUTFChars(jloginOtp, &isCopy);
		loginOtp = strdup(rawString);
		env->ReleaseStringUTFChars(jloginOtp, rawString);
	} else {
		loginOtp = NULL;
	}
	if(juserId != NULL) {
		jboolean isCopy;
		const char *rawString = env->GetStringUTFChars(juserId, &isCopy);
		userId = strdup(rawString);
		env->ReleaseStringUTFChars(juserId, rawString);
	} else {
		userId = NULL;
	}
	if(nativeObjRef != 0ll) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnLoginEndArgs *arguments = (OnLoginEndArgs*)malloc(sizeof(OnLoginEndArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus)status;
		arguments->loginOtp = loginOtp;
		arguments->userId = userId;
		arguments->retryCounter = (int)retryCounter;
		arguments->retryDelay = (int)retryDelay;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onLoginEndFunc, arguments);
#else
    	onLoginEndFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onPinChangeBegin(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint status)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnPinChangeBeginArgs *arguments = (OnPinChangeBeginArgs*)malloc(sizeof(OnPinChangeBeginArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus)status;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onPinChangeBeginFunc, arguments);
#else
    	onPinChangeBeginFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onPinChangeEnd(JNIEnv *env, jobject thiz, jlong nativeObjRef, jint deviceType, jint status, jint retryCounter)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnPinChangeEndArgs *arguments = (OnPinChangeEndArgs*)malloc(sizeof(OnPinChangeEndArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus)status;
		arguments->retryCounter = (int) retryCounter;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onPinChangeEndFunc, arguments);
#else
    	onPinChangeEndFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onTransactionBegin(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jstring jdisplayData, jint confirmationType)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	const char* displayData;
	if(jdisplayData != NULL) {
		jboolean isCopy;
		const char *rawString = env->GetStringUTFChars(jdisplayData, &isCopy);
		displayData = strdup(rawString);
		env->ReleaseStringUTFChars(jdisplayData, rawString);
	} else {
		displayData = NULL;
	}
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnTransactionBeginArgs *arguments = (OnTransactionBeginArgs*)malloc(sizeof(OnTransactionBeginArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->displayData = displayData;
		arguments->confirmationType = (KAstConfirmationType)confirmationType;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onTransactionBeginFunc, arguments);
#else
    	onTransactionBeginFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onTransactionEnd(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint status)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnTransactionEndArgs *arguments = (OnTransactionEndArgs*)malloc(sizeof(OnTransactionEndArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus) status;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onTransactionEndFunc, arguments);
#else
    	onTransactionEndFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onAlert(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint subSystem, jint errorCode)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnAlertArgs *arguments = (OnAlertArgs*)malloc(sizeof(OnAlertArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->subSystem = (unsigned int)subSystem;
		arguments->errorCode = (unsigned int)errorCode;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onAlertFunc, arguments);
#else
    	onAlertFunc(arguments);
#endif
	}

}


void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onSetPropertyBegin(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint status)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnSetPropertyBeginArgs *arguments = (OnSetPropertyBeginArgs*)malloc(sizeof(OnSetPropertyBeginArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus) status;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onSetPropertyBeginFunc, arguments);
#else
    	onSetPropertyBeginFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onSetPropertyEnd(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint deviceType, jint status, jint subSystem, jint errorCode)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	if(nativeObjRef != 0) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnSetPropertyEndArgs *arguments = (OnSetPropertyEndArgs*)malloc(sizeof(OnSetPropertyEndArgs));
		arguments->sdk = astSdk;
		arguments->deviceType = (KAstDeviceType) deviceType;
		arguments->status = (KAstStatus) status;
		arguments->subSystem = (uint32_t) subSystem;
		arguments->errorCode = (uint32_t) errorCode;

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onSetPropertyEndFunc, arguments);
#else
    	onSetPropertyEndFunc(arguments);
#endif
	}

}

void Java_com_kobil_ast_smartfaceplugin_KobilAstSdk_onDeactivateEnd(JNIEnv *env, jobject thiz,jlong nativeObjRef, jint status, jobjectArray juserIdList)
{
	SpContext::GetInstance()->SetJniEnvironment(env);
	int stringCount = 0;
	if(juserIdList){
		stringCount = env->GetArrayLength(juserIdList);
	}
	if (nativeObjRef != 0ll) {
		KobilAstSDK *astSdk = (KobilAstSDK *)nativeObjRef;
		OnDeactivateEndArgs *arguments = new OnDeactivateEndArgs();//(OnDeactivateEndArgs*)malloc(sizeof(OnDeactivateEndArgs));
		arguments->sdk = astSdk;
		arguments->status = (KAstStatus)status;
		for (int i = 0; i < stringCount; i++) {
			jstring string = (jstring) env->GetObjectArrayElement(juserIdList, i);
			jboolean isCopy;
			const char *rawString = env->GetStringUTFChars(string, &isCopy);
			std::string str(strdup(rawString));
			env->ReleaseStringUTFChars(string, rawString);
			arguments->userIdList.push_back(str);
		}

#if USE_THREADS_FOR_EVENTS
    	pthread_t t1;
    	pthread_create(&t1, NULL, &onDeactivateEndFunc, arguments);
#else
    	onDeactivateEndFunc(arguments);
#endif

	}
}



}
