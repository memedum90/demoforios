#include "inc/JavaScriptCore.h"
#include "KobilAstSDK.h"
#include <jni.h>
#include <string>
#include <map>
#include <android/log.h>
std::map<pthread_t,JNIEnv*> * KobilAstSDK::envMap;
jobject KobilAstSDK::pluginImpObject;

KobilAstSDK::KobilAstSDK() {
    kobilAstObjectRef = NULL;
    kobilAstSdkListenerRef = NULL;
    sdkListener = NULL;
	JNIEnv * env = GetJNIEnv();
	if(pluginImpObject != NULL) {
		jclass pluginClazz = env->GetObjectClass(pluginImpObject);
		jmethodID method = env->GetMethodID(pluginClazz, "createKobilAstSDK__N", "()Ljava/lang/Object;");
		jobject obj = env->CallObjectMethod(pluginImpObject, method);
		objRef = env->NewGlobalRef(obj);
		env->DeleteLocalRef(pluginClazz);
		LoadAstSDK();
	}

}

void KobilAstSDK::LoadAstSDK(){
	__android_log_print(ANDROID_LOG_ERROR,"KobilASTClass","----------------------------------- LoadAstSDK this: %d ", (int)this);
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "setNativeObjectRef__N", "(J)V");
		env->CallVoidMethod(objRef, method, (jlong)this);
		env->DeleteLocalRef(objClazz);
	}
}

KobilAstSDK::~KobilAstSDK() {
	JNIEnv * env = GetJNIEnv();
	env->DeleteGlobalRef(objRef);
}

void KobilAstSDK::SetContextRef(JSContextRef ctx) {
	jsContextRef = ctx;
}

JNIEnv* KobilAstSDK::GetJNIEnv()
{
	pthread_t id = pthread_self();
	if ( envMap->find(id) != envMap->end() )
	{
		return envMap->operator [](id);
	}
	else
	{
		__android_log_print(ANDROID_LOG_ERROR,"KobilASTClass","GetJNIEnv not jni environment for this thread");
		return 0;
	}

}

void KobilAstSDK::FactoryFreeAst(){

}

KAstStatus KobilAstSDK::init(const char *locale, const char *version, const char *appName, KAstLogLevel logLevel) {
	KAstStatus result = KAstStatus_DEVICE_NOT_FOUND;
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "init__N", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)I");
		jstring string = NULL;
		jstring string2 = NULL;
		jstring string3 = NULL;
		if(locale) {
			string = env->NewStringUTF(locale);
		}
		if(version) {
			string2 = env->NewStringUTF(version);
		}
		if(appName) {
			string3 = env->NewStringUTF(appName);
		}
		result = (KAstStatus)env->CallIntMethod(objRef, method, string, string2, string3, (jint)logLevel);
		env->DeleteLocalRef(objClazz);
	}
	return result;
}

void KobilAstSDK::doActivation(KAstDeviceType deviceType, const char *pin, const char *userId, const char *activationCode) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doActivation__N", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring string = NULL;
		jstring string2 = NULL;
		jstring string3 = NULL;
		if(pin) {
			string = env->NewStringUTF(pin);
		}
		if(userId) {
			string2 = env->NewStringUTF(userId);
		}
		if(activationCode) {
			string3 = env->NewStringUTF(activationCode);
		}
		env->CallVoidMethod(objRef, method, (jint)deviceType, string, string2, string3 );
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doLogin(KAstDeviceType deviceType, const char *pin, const char *userId) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doLogin__N", "(ILjava/lang/String;Ljava/lang/String;)V");
		jstring string = NULL;
		jstring string2 = NULL;
		if(pin) {
			string = env->NewStringUTF(pin);
		}
		if(userId) {
			string2 = env->NewStringUTF(userId);
		}
		env->CallVoidMethod(objRef, method, (jint)deviceType, string, string2);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doPinChangeRequest(KAstDeviceType deviceType) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doPinChangeRequest__N", "(I)V");
		env->CallVoidMethod(objRef, method, (jint)deviceType);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doPinChange(KAstDeviceType deviceType, KAstConfirmation confirm, const char *currentPin, const char *newPin) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doPinChange__N", "(IILjava/lang/String;Ljava/lang/String;)V");
		jstring string = NULL;
		jstring string2 = NULL;
		if(currentPin) {
			string = env->NewStringUTF(currentPin);
		}
		if(newPin) {
			string2 = env->NewStringUTF(newPin);
		}
		env->CallVoidMethod(objRef, method, (jint)deviceType, (jint)confirm, string, string2);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doSetPropertyRequest(KAstDeviceType deviceType) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doSetPropertyRequest__N", "(I)V");
		env->CallVoidMethod(objRef, method, (jint)deviceType);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doSetProperty(KAstDeviceType deviceType, const char *propertyKey, const char *propertyData,
		KAstPropertyType propertyType, KAstPropertyOwner propertyOwner, int propertyTTL, KAstPropertyFlag propertyFlag) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doSetProperty__N", "(ILjava/lang/String;Ljava/lang/String;IIII)V");
		jstring string = NULL;
		jstring string2 = NULL;
		if(propertyKey) {
			string = env->NewStringUTF(propertyKey);
		}
		if(propertyData) {
			string2 = env->NewStringUTF(propertyData);
		}
		env->CallVoidMethod(objRef, method, (jint)deviceType, string, string2, (jint)propertyType, (jint)propertyOwner, (jint)propertyTTL, (jint)propertyFlag);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doTransaction(KAstDeviceType deviceType, KAstConfirmation confirmation, const char *displayData) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "doTransaction__N", "(IILjava/lang/String;)V");
		jstring string = NULL;
		if(displayData) {
			string = env->NewStringUTF(displayData);
		}
		env->CallVoidMethod(objRef, method, (jint)deviceType, (jint)confirmation, string);
		env->DeleteLocalRef(objClazz);
	}
}

void KobilAstSDK::doDeactivate(const char *userId) {
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jstring juserId = NULL;
		if(userId)
		{
			juserId = env->NewStringUTF(userId);
		}
		jmethodID method = env->GetMethodID(objClazz,"doDeactivate__N","(Ljava/lang/String;)V");
		env->CallVoidMethod(objRef,method,juserId);
		env->DeleteLocalRef(objClazz);
	}
}

KAstStatus KobilAstSDK::resume()
{
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz,"resume__N","()I");
		int ret = env->CallIntMethod(objRef,method);
		env->DeleteLocalRef(objClazz);
		return (KAstStatus)ret;
	}
}
void KobilAstSDK::suspend()
{
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz,"suspend__N","()V");
		env->CallVoidMethod(objRef,method);
		env->DeleteLocalRef(objClazz);
	}
}

int KobilAstSDK::exit(int errorCode) {
	int result = -1;
	if(objRef != NULL) {
		JNIEnv * env = GetJNIEnv();
		jclass objClazz = env->GetObjectClass(objRef);
		jmethodID method = env->GetMethodID(objClazz, "exit__N", "(I)I");
		result = (int)env->CallIntMethod(objRef, method, (jint)errorCode);
		env->DeleteLocalRef(objClazz);
	}
	return result;
}

