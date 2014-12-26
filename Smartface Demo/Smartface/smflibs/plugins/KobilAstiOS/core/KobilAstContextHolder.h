//
//  KobilAstContextHolder.h
//  Smartface
//
//  Created by Ugur Kilic on 01.07.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __KobilAstContextHolder__
#define __KobilAstContextHolder__

#if defined (__APPLE__) && !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#endif
#include <map>
#include <pthread.h>
#endif

class KobilAstContextHolder {
public:
	KobilAstContextHolder();
    static KobilAstContextHolder *getInstance();
    JSContextRef ctx;
};

#endif /* __KobilAstContextHolder__ */
