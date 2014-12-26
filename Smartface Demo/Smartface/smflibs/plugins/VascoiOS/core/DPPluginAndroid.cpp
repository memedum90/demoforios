#include "DPPlugin.h"
#include "SPJSDPPlugin.h"
#include "DP4Capi.h"
#include <sstream>
#include <jni.h>
#include <android/log.h>
#include "inc/JavaScriptCore.h"
#include <pthread.h>

JNIEnv* DPPlugin::GetJNIEnv()
{
	pthread_t id = pthread_self();
	if ( envMap->find(id) != envMap->end() )
	{
		return envMap->operator [](id);
	}
	else
	{
		__android_log_print(ANDROID_LOG_ERROR,"DPPlugin","GetJNIEnv not jni environment for this thread");
		return 0;
	}
}


void DPPlugin::initializeRegistrationDataV2(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError)
{
	DPPlugin* dp = DPPlugin::getInstance();
	JSContextRef ctx = dp->jsContext;
	JNIEnv* env = dp->GetJNIEnv();

	jbooleanArray arr = env->NewBooleanArray(1);
	jboolean isCopy;
	jstring string = env->NewStringUTF(activationPassword);
	jstring resultjson = (jstring)env->CallObjectMethod(dp->pluginImpObject,dp->initializeRegistrationDataV2JavaFunction,string,arr);
	const char* resultjsonchars = env->GetStringUTFChars(resultjson,&isCopy);
	jboolean* arrptr = env->GetBooleanArrayElements(arr,&isCopy);
	int len = strlen(resultjsonchars) + 40;
	char* buf = new char[len];
	memset(buf,0,len);
	sprintf(buf, "(function(){return %s;})()", resultjsonchars);
	JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
	JSValueRef exception = 0;
	JSValueRef arguments[] = {JSValueMakeNull(ctx)};
	arguments[0] = JSEvaluateScript(ctx,scriptJS,0,0,0,&exception);
	if (arrptr[0] && onSuccess)
	{
		JSObjectCallAsFunction(ctx,onSuccess,0,1,arguments,0);
	}
	else if ( !arrptr[0] && onError)
	{
		JSObjectCallAsFunction(ctx,onError,0,1,arguments,0);
	}
	JSStringRelease(scriptJS);
	env->ReleaseBooleanArrayElements(arr,arrptr,0);
	env->ReleaseStringUTFChars(resultjson,resultjsonchars);
	env->DeleteLocalRef(arr);
	env->DeleteLocalRef(string);
	env->DeleteLocalRef(resultjson);
}

void DPPlugin::decryptActivationData(const char* chsKey,const char* clientPrivateKey,const char* encryptedServerPublicKey
		,const char* encryptedNonces,const char* xfad,const char* xerc,const char* clientNonce
		,const char* serverInitialVector,JSObjectRef onSuccess,JSObjectRef onError)
{
	DPPlugin* dp = DPPlugin::getInstance();
	JSContextRef ctx = dp->jsContext;
	JNIEnv* env = dp->GetJNIEnv();

	jbooleanArray arr = env->NewBooleanArray(1);
	jboolean isCopy;

	jstring stringChsKey = env->NewStringUTF(chsKey);
	jstring stringclientPrivateKey = env->NewStringUTF(clientPrivateKey);
	jstring stringencryptedServerPublicKey = env->NewStringUTF(encryptedServerPublicKey);
	jstring stringencryptedNonces = env->NewStringUTF(encryptedNonces);
	jstring stringxfad = env->NewStringUTF(xfad);
	jstring stringxerc = env->NewStringUTF(xerc);
	jstring stringclientNonce = env->NewStringUTF(clientNonce);
	jstring stringserverInitialVector = env->NewStringUTF(serverInitialVector);


	jstring resultjson = (jstring)env->CallObjectMethod(dp->pluginImpObject
			,dp->decryptActivationDataJavaFunction,stringChsKey,stringclientPrivateKey,stringencryptedServerPublicKey,
			stringencryptedNonces,stringxfad,stringxerc,stringclientNonce,stringserverInitialVector,arr);
	const char* resultjsonchars = env->GetStringUTFChars(resultjson,&isCopy);
	jboolean* arrptr = env->GetBooleanArrayElements(arr,&isCopy);
	int len = strlen(resultjsonchars) + 40;
	char* buf = new char[len];
	memset(buf,0,len);
	sprintf(buf, "(function(){return %s;})()", resultjsonchars);
	JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
	JSValueRef exception = 0;
	JSValueRef arguments[] = {JSValueMakeNull(ctx)};
	arguments[0] = JSEvaluateScript(ctx,scriptJS,0,0,0,&exception);
	if (arrptr[0] && onSuccess)
	{
		JSObjectCallAsFunction(ctx,onSuccess,0,1,arguments,0);
	}
	else if ( !arrptr[0] && onError)
	{
		JSObjectCallAsFunction(ctx,onError,0,1,arguments,0);
	}
	JSStringRelease(scriptJS);
	env->ReleaseBooleanArrayElements(arr,arrptr,0);
	env->ReleaseStringUTFChars(resultjson,resultjsonchars);
	env->DeleteLocalRef(arr);

	env->DeleteLocalRef(stringChsKey);
	env->DeleteLocalRef(stringclientPrivateKey);
	env->DeleteLocalRef(stringencryptedServerPublicKey);
	env->DeleteLocalRef(stringencryptedNonces);
	env->DeleteLocalRef(stringxfad);
	env->DeleteLocalRef(stringxerc);
	env->DeleteLocalRef(stringclientNonce);
	env->DeleteLocalRef(stringserverInitialVector);
	env->DeleteLocalRef(resultjson);
}

void DPPlugin::validateSharedDataChecksum(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError)
{
	DPPlugin* dp = DPPlugin::getInstance();
	JSContextRef ctx = dp->jsContext;
	JNIEnv* env = dp->GetJNIEnv();

	jbooleanArray arr = env->NewBooleanArray(1);
	jboolean isCopy;

	jstring stringactivationPassword = env->NewStringUTF(activationPassword);


	jstring resultjson = (jstring)env->CallObjectMethod(dp->pluginImpObject
			,dp->validateSharedDataChecksumJavaFunction,stringactivationPassword,arr);
	const char* resultjsonchars = env->GetStringUTFChars(resultjson,&isCopy);
	jboolean* arrptr = env->GetBooleanArrayElements(arr,&isCopy);
	int len = strlen(resultjsonchars) + 40;
	char* buf = new char[len];
	memset(buf,0,len);
	sprintf(buf, "(function(){return %s;})()", resultjsonchars);
	JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
	JSValueRef exception = 0;
	JSValueRef arguments[] = {JSValueMakeNull(ctx)};
	arguments[0] = JSEvaluateScript(ctx,scriptJS,0,0,0,&exception);
	if (arrptr[0] && onSuccess)
	{
		JSObjectCallAsFunction(ctx,onSuccess,0,1,arguments,0);
	}
	else if ( !arrptr[0] && onError)
	{
		JSObjectCallAsFunction(ctx,onError,0,1,arguments,0);
	}
	JSStringRelease(scriptJS);
	env->ReleaseBooleanArrayElements(arr,arrptr,0);
	env->ReleaseStringUTFChars(resultjson,resultjsonchars);
	env->DeleteLocalRef(arr);
	env->DeleteLocalRef(stringactivationPassword);
	env->DeleteLocalRef(resultjson);
}

bool DPPlugin::saveFileToDocuments(const char* filename, char* data, int len)
{

	JNIEnv* env = DPPlugin::getInstance()->GetJNIEnv();
	jobject pluginImpObject = DPPlugin::getInstance()->pluginImpObject;
	jmethodID putBytes = DPPlugin::getInstance()->putBytes;
	jbyteArray arr = env->NewByteArray(len);
	env->SetByteArrayRegion(arr,0,len,(jbyte*)data);
	jstring fingerprint = env->NewStringUTF(DBFINGERPRINT);
	jstring key = env->NewStringUTF(filename);
	jboolean result = env->CallBooleanMethod(pluginImpObject,putBytes,fingerprint,key,arr);
	env->DeleteLocalRef(fingerprint);
	env->DeleteLocalRef(key);
	env->DeleteLocalRef(arr);
	return (bool)result;
}
char* DPPlugin::readFileFromDocuments(const char* filename)
{
	JNIEnv* env = DPPlugin::getInstance()->GetJNIEnv();
	jobject pluginImpObject = DPPlugin::getInstance()->pluginImpObject;
	jmethodID getBytes = DPPlugin::getInstance()->getBytes;
	jstring key = env->NewStringUTF(filename);
	jbyteArray result = (jbyteArray)env->CallObjectMethod(pluginImpObject,getBytes,key);
	env->DeleteLocalRef(key);
	char* output;
	if (result)
	{
		jsize len = env->GetArrayLength(result);
		output = new char[len+1];
		env->GetByteArrayRegion(result,0,len,(jbyte*)output);
		output[len] = 0;
		env->DeleteLocalRef(result);
	}
	else
	{
		output = 0;
	}
	return output;
}

// save data with Secure Storage SDK
void DPPlugin::secureSave(const char* keyname, vds_byte* data, int len){
	JNIEnv* env = DPPlugin::getInstance()->GetJNIEnv();
	jobject pluginImpObject = DPPlugin::getInstance()->pluginImpObject;
	jmethodID putBytes = DPPlugin::getInstance()->putBytes;
	jbyteArray arr = env->NewByteArray(len);
	env->SetByteArrayRegion(arr,0,len,(jbyte*)data);
	jstring fingerprint = env->NewStringUTF(DBFINGERPRINT);
	jstring key = env->NewStringUTF(keyname);
	jboolean result = env->CallBooleanMethod(pluginImpObject,putBytes,fingerprint,key,arr);
	env->DeleteLocalRef(fingerprint);
	env->DeleteLocalRef(key);
	env->DeleteLocalRef(arr);
}
// read data with Secure Storage SDK
char* DPPlugin::secureRead(const char* keyname){
	JNIEnv* env = DPPlugin::getInstance()->GetJNIEnv();
	jobject pluginImpObject = DPPlugin::getInstance()->pluginImpObject;
	jmethodID getBytes = DPPlugin::getInstance()->getBytes;
	jstring key = env->NewStringUTF(keyname);
	jbyteArray result = (jbyteArray)env->CallObjectMethod(pluginImpObject,getBytes,key);
	env->DeleteLocalRef(key);
	char* output;
	if (result)
	{
		jsize len = env->GetArrayLength(result);
		output = new char[len+1];
		env->GetByteArrayRegion(result,0,len,(jbyte*)output);
		output[len] = 0;
		env->DeleteLocalRef(result);
	}
	else
	{
		output = 0;
	}
	return output;
}
