#ifndef AST_H
#define AST_H

#import "AstSdk.h"
#import "AstSdkTypes.h"
#import "AstSdkListener.h"
#import "AstUpdate.h"
#import "AstUpdateListener.h"
#import "AstSdkFactory.h"
#import "AstChannel.h"
#import "AstRequest.h"
#import "AstBuilder.h"
#import "AstResponse.h"

/*!
 \if ASTSDK
 \mainpage AST SDK Documentation
 \endif
 \section intro_astsdk Introduction
 
 Using the AST SDK is very simple:
 By including Ast.h you receive following interfaces, which will be all interfaces you will need to develop an app that is secured with AST SDK.
 - AstSdkFactory
 - AstSdk
 - AstSdkListener
 - AstUpdate
 - AstUpdateListener
 
 Furthermore, it also includes the interfaces needed for the AstChannels
 - AstChannel
 - AstRequest
 - AstBuilder
 - AstResponse
 
 \section usage_sec Usage of AST SDK
 - AstSdkFactory needs an AstSdkListener as a parameter, this interface will be used when the AST SDK talks to your application,
   every command from the AST SDK will enter here, so if you want to receive commands from inside the AST SDK you have to implement this interface.
 - The return value will be an object of type AstSdk which is the interface to our AST SDK. So every command that you will send to the AST SDK is send from this interface.
 - if you need the update-capability, use {@link AstSdk::registerUpdate:} to make objects of the protocols AstUpdate and AstUpdateListener known to the AST SDK.
 - The AST SDK has an internal logging mechanism, which is described in more detail on \ref loggingMechanism
 
 \section usage_astChannels Usage of AstChannels
 - with {@link AstSdk::getAstChannel} you get the AstChannel instance belonging to the current thread
 - AstBuilder is used to create AstRequest instances, which can be send with {@link AstChannel::transfer:}. The response can be found in the returned AstResponse instance.

 \section environment_requirements Environment requirements
 - An App using the AST SDK needs to have the entitlement 'Keychain Access Group' with the value '$(AppIdentifierPrefix)UdidAccessGroup'.
 */

 /*!
 \page apiChangeLog API Change Log
 \brief List of changes to the API
 \section ms6b Version 2.5 (MS6b)
 - all parameters of AstBuilder and AstChannel are changed to lower case
 - type of last parameter of {@link AstSdk::init:version:appName:logLevel:} changed to AstLogLevel
 - removed method AstSdk::deactivate
 - changed all occurences of parameter "userIdlist" in AstSdkListener to "userIdList"
 - removed method AstSdkListener::onLogMessage:message:
 - changed parameter name "seconds" of {@link AstUpdateListener::onUpdateInformationAvailable:status:updateUrl:infoUrl:updateType:expiresInSeconds:} to "expiresInSeconds"
 - added enum value AstConfigParameter_ALLOWED_HOST_DEVICES
 - renamed enume value UrlBlockedReason_WHITE_LIST_ERROR to UrlBlockedReason_WHITELIST_ERROR
 - removed unused enum values UrlBlockedReason_SCREEN_OVERLAY_ERROR and UrlBlockedReason_HTTP_ERROR
 - added enum value AstInformationKey_UNSUPPORTED_HOST_DEVICE
 - added enum AstLogLevel
 - removed unused integer constants AstSdkError_...
 - removed file LogLevel.h include corresponding enum
 - added method AstSdk::suspend and AstSdk::resume
 - added enum value AstStatus_NOT_SUSPENDED
 */

/*!
 \page loggingMechanism Logging mechanism
 \brief Description of the App interactions with the AST SDK to control logging
 - The AST SDK enables logging during AstSdkFactory::CreateAst:, if for the key "enabled_logging" in [NSUserDefaults standardUserDefaults] there is an NSNumber instance with the value TRUE. This should be done by adding a Settings bundle to the App, which has as Toggle Switch with the this key as identifier.
 - When logging is enabled in AstSdkFactory::CreateAst:, the value for key "enabled_logging" in [NSUserDefaults standardUserDefaults] is reset to FALSE. Thus, the user has to consciously enable logging each time.
 - The log may be found at "./Documents/astSdkLogging.dat" (most recent log) and "./Documents/astSdkLogging.dat.1" (previous log).
 - The App should set the option "Application supports iTunes file sharing" in Info.plist to YES, to allow access to the Documents folder via iTunes.
 - The actual logs are encrypted, allowing only KOBIL to read them.
 */

/*!
 \page properties Properties
 \brief Description of Properties

 The AST allows to write and read small amounts of data called properties, which are normally stored on the SSMS and may be set and/or get from
 both the portal and the App. Each property consists of a key-value-pair.

 In the following the possible options are explained:
 
 PropertType
 Each property has a type out of the following list:
 - OCTET-STRING is represented as NSData
 - INTEGER and BOOLEAN are represented as NSString
 - UTF8String is represented as NSString
 - DATE is represented as NSDate

 PropertyOwner
 Each property has an owner, which allows to share a property between a group of devices or not. Possible values are:
 - DEVICE: the property is specific for this devie only
 - USER: the property is shared between all device of the user; changing it on one device will change it on all other devices
 - GROUP:simialr to USER, but property is sharde between all devices of all users of the group

 PropertyFlags
 For each property so called flags may be set to assign different options to a property. Some flag/onwer-combinations are not allowed.
 - NON_PERSISTANCE: TBD
 - VALUE_ENCRYPTED: if stored in SSMS database, the property value will be encrypted
 - CONFIDENTIAL: will not be displayed on SSMS management GUI
 - UNIQUE_TO_USER: the value of this property must be unique to all devices belonging to the same user
 - IMMEDIATE: TBD
 - READ_ONLY: This property may not be written by portal and App.
 */

#endif
