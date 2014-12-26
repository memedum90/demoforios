//
//  SpJSKofaxFuncDefs.h
//  SpratIOS
//
//  Created by Mehmet Akyol on 17/02/14.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __SpratIOS__SpJSKofaxFuncDefs__
#define __SpratIOS__SpJSKofaxFuncDefs__

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif


JSValueRef kfx_setSDKLicense(JSContextRef ctx,
                          JSObjectRef function,
                          JSObjectRef thisObject,
                          size_t argumentCount,
                          const JSValueRef arguments[],
                          JSValueRef* exception);

JSValueRef kfx_openCaptureScreen(JSContextRef ctx,
                             JSObjectRef function,
                             JSObjectRef thisObject,
                             size_t argumentCount,
                             const JSValueRef arguments[],
                             JSValueRef* exception);

JSValueRef kfx_processImage(JSContextRef ctx,
                                 JSObjectRef function,
                                 JSObjectRef thisObject,
                                 size_t argumentCount,
                                 const JSValueRef arguments[],
                                 JSValueRef* exception);

JSValueRef kfx_getArrayObject(JSContextRef ctx, JSObjectRef arrayRef, const char *property);

#endif /* defined(__SpratIOS__SpJSKofaxFuncDefs__) */
