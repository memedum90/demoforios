//
//  KobilAstEnums.h
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __KobilAstEnums__
#define __KobilAstEnums__


typedef enum {
    KAstConfirmation_OK,
    KAstConfirmation_Cancel,
    KAstConfirmation_TimeOut
} KAstConfirmation;

typedef enum {
    KAstConfirmationType_NoConfirmation,
    KAstConfirmationType_ConfirmationRequired,
    KAstConfirmationType_SplitConfirmation
} KAstConfirmationType;

typedef enum {
    KAstDeviceType_MIdentity,
    KAstDeviceType_VirtualDevice
} KAstDeviceType;

typedef enum {
    KAstLogLevel_Trace,
    KAstLogLevel_Debug,
    KAstLogLevel_Info,
    KAstLogLevel_Warn,
    KAstLogLevel_Error,
    KAstLogLevel_Fatal
} KAstLogLevel;

typedef enum {
    KAstPropertyFlag_NonPersistance,
    KAstPropertyFlag_ValueEncrypted,
    KAstPropertyFlag_Confidental,
    KAstPropertyFlag_UniqueToUser,
    KAstPropertyFlag_Immediate
} KAstPropertyFlag;

typedef enum {
    KAstPropertyOwner_Device,
    KAstPropertyOwner_User,
    KAstPropertyOwner_Group
} KAstPropertyOwner;

typedef enum {
    KAstPropertyType_OctetString,
    KAstPropertyType_Integer,
    KAstPropertyType_Boolean,
    KAstPropertyType_Utf8string,
    KAstPropertyType_Date
} KAstPropertyType;

typedef enum {
    KAstStatus_OK,
    KAstStatus_UPDATE_AVAILABLE,
    KAstStatus_ACTIVATE_CERTIFICATE,
    KAstStatus_APP_REGISTERED,
    KAstStatus_USER_CANCEL,
    KAstStatus_USER_CONFIRMATION_TIMEOUT,
    KAstStatus_INVALID_PIN,
    KAstStatus_INVALID_NEW_PIN_FORMAT,
    KAstStatus_INVALID_ACTIVATION_CODE,
    KAstStatus_UNKNOWN_VERSION,
    KAstStatus_UNKNOWN_CLIENT_TYPE,
    KAstStatus_UPDATE_NECESSARY,
    KAstStatus_WRONG_CREDENTIALS,
    KAstStatus_UNKNOWN_CERTIFICATE,
    KAstStatus_INTERNAL_ERROR,
    KAstStatus_ACTIVATION_CODE_EXPIRED,
    KAstStatus_LOCKED_CERTIFICATE,
    KAstStatus_LOCKED_USER,
    KAstStatus_INVALID_PUK,
    KAstStatus_PROPERTY_NOT_EXISTS,
    KAstStatus_INVALID_KEY_LENGTH,
    KAstStatus_NOT_UNIQUE,
    KAstStatus_TEXT_TOO_LONG,
    KAstStatus_INVALID_STATE,
    KAstStatus_INVALID_DEVICE,
    KAstStatus_INVALID_PARAMETER,
    KAstStatus_INVALID_USER_ID,
    KAstStatus_USER_ID_ALREADY_EXISTS,
    KAstStatus_DEVICE_NOT_FOUND,
    KAstStatus_REGISTER_APP,
    KAstStatus_MISMATCHED_USER,
    KAstStatus_NEGATIVE,
    KAstStatus_READ_ONLY,
    KAstStatus_TEMPORARY_LOCKED,
    KAstStatus_NOT_SUSPENDED
} KAstStatus;

#endif /* defined(__KobilAstEnums__) */
