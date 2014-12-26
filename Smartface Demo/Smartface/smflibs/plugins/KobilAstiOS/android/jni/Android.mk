LOCAL_PATH := $(call my-dir)

#include $(CLEAR_VARS)
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
#			$(LOCAL_PATH)/../smf-player-core4.0.5b/JavaScriptCore/inc
#LOCAL_MODULE := sprat-jni
#LOCAL_SRC_FILES := libsprat-jni.so
#include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
			$(LOCAL_PATH)/inc \
			$(LOCAL_PATH)/../../core \
			$(LOCAL_PATH)/../../core/inc \
			$(LOCAL_PATH)/../../../../smf-player-android4_2_2/c/inc

src_files := \
	../plugin-jni-Android.cpp ../KobilAstSDKAndroid.cpp ../../core/KobilAstSDK.cpp ../../core/KobilAstContextHolder.cpp \
	../../core/SpJSKobilAstFactory.cpp ../../core/SpJSKobilAstListener.cpp ../../core/SpJSKobilAstSDK.cpp \
	../../core/SpJSKobilAstSDKFunctions.cpp ../../core/SpJSKobilDefs.cpp

LOCAL_MODULE := kobilast-plugin
LOCAL_SRC_FILES := $(src_files)

LOCAL_ARM_MODE := arm
LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O3 -DANDROID_NDK -DDISABLE_IMPORTGL
LOCAL_LDLIBS := -ldl -llog 
ifeq ($(TARGET_ARCH_ABI),x86)
LOCAL_LDLIBS += -L../../../smf-player-android4_2_2/libs/x86 -lsprat-jni
else
LOCAL_LDLIBS += -L../../../smf-player-android4_2_2/libs/armeabi -lsprat-jni
endif

LOCAL_SHARED_LIBRARIES := sprat-jni

include $(BUILD_SHARED_LIBRARY)
