#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#ifdef TARGET_PLATFORM_ANDROID
#include <android/log.h>
#endif

#ifndef __SPDEFS_H_
#define __SPDEFS_H_
#define SPRAT_VERSION		"4.1.0"

#define SPRAT_LOGGING
//#undef SPRAT_LOGGING

#ifdef SPRAT_LOGGING
#define ACTIONEVENT_LOGGING
//#undef ACTIONEVENT_LOGGING
#define LOG_TO_FILE
#undef LOG_TO_FILE
#endif

#define MOBINEX
//#undef MOBINEX

// note: this is not about debug functionality
#define DEVELOPER_DEBUGGING
#undef SPRAT_DEBUGGING

//#ifdef SPRAT_LOGGING
// for emulator
#define DEBUGGER_PLAYER
#undef DEBUGGER_PLAYER
//#endif

// for android ndk debugging
#define NDKDEBUG
#undef NDEBUG

#define ON_MEMORY_DB_DEV
//#undef ON_MEMORY_DB_DEV


#ifdef SPRAT_LOGGING
#define LOG_NETWORK_TO_FILE
#endif

const char kPathSeparator =
#ifdef _WIN32
                            '\\';
#else
                            '/';
#endif

#define TARGET_PLATFORM_WINDOWS
#undef TARGET_PLATFORM_WINDOWS

#define ANDROID_INIT_TIME_BUFFER 10
#undef ANDROID_INIT_TIME_BUFFER

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
    #include "SPDefsIOS.h"

    #define TARGET_PLATFORM_IOS

    #define SPRAT_LOGGING
    #define ACTIONEVENT_LOGGING

    #if defined __arm__ || defined __thumb__
        #define TARGET_PLATFORM_IOS_DEVICE
    #else
        #define TARGET_PLATFORM_IOS_SIMULATOR
    #endif

    #define MOBINEX

    #ifdef DEVELOPER_DEBUGGING
        #undef DEBUGGER_PLAYER
    #endif

	#ifdef IOS_PLAYER
        #undef SPRAT_LOGGING
        #undef DEVELOPER_DEBUGGING
        #undef ACTIONEVENT_LOGGING
        #undef DEBUGGER_PLAYER
        #undef LOG_NETWORK_TO_FILE
    #endif
    #ifdef SMARTFACE_IOS_EMULATOR
        #undef DEVELOPER_DEBUGGING
        #define DEBUGGER_PLAYER
        #undef LOG_NETWORK_TO_FILE
    #endif
#elif _WIN32
    #define TARGET_PLATFORM_WINDOWS
 	#define TARGET_PLATFORM_ANDROID
	#define snprintf sprintf_s
	#define GL_GLEXT_PROTOTYPES
#else
    #define TARGET_PLATFORM_ANDROID 
    #define GL_GLEXT_PROTOTYPES
    #undef DEVELOPER_DEBUGGING
#endif

#ifdef TARGET_ANDROID_PLAYER_RELEASE
    #ifdef SPRAT_LOGGING
	    #undef SPRAT_LOGGING
    #endif
    #ifdef ACTIONEVENT_LOGGING
        #undef ACTIONEVENT_LOGGING
    #endif
#elif defined(TARGET_ANDROID_EMULATOR_RELEASE)
	#ifndef SPRAT_LOGGING
    	#define SPRAT_LOGGING
	#endif
    #ifdef ACTIONEVENT_LOGGING
        #undef ACTIONEVENT_LOGGING
    #endif
	#ifndef DEBUGGER_PLAYER
		#define DEBUGGER_PLAYER
	#endif
#endif

#ifdef NULL
#undef NULL
#endif

#define NULL 0

#define HTTP_CONNECTION_TIMEOUT 30

typedef enum {
	TSALeft = 0,
	TSACenter = 1,
	TSARight = 2
} TScrollAlignment;

typedef enum {
	TSCDNone = 0,
	TSCDVertical = 1,
	TSCDHorizontal = 2,
} TScrollDirection;

typedef enum {
	TSIFJPEG = 0,
	TSIFPNG = 1
} TImageFormat;

typedef enum {
	TDESTRUCTIVE = 0,
	TCANCEL = 1
} TMenuItemType;

typedef enum {
    VATop = 0,
    VAMiddle,
    VABottom
} TVerticalAlign;

typedef enum {
    HALeft = 0,
    HACenter,
    HARight
} THorizontalAlign;

typedef enum {
    EBTTCurrency = 0,
    EBTTDateTime,
    EBTTGeneric,
    EBTTPassword,
    EBTTPhoneNumber,
    EBTTNumber,
    EBTTNumericPassword
} TEditBoxTextType;

typedef enum {
    EBITTextInput = 0,
    EBITNumericInput
} TEditBoxInputType;

typedef enum {
    EBKTDefault = 1,
    EBKTAsciiCapable,
    EBKTNumbersAndPunctuation,
    EBKTUrl,
    EBKTNumberPad,
    EBKTPhonePad,
    EBKTNamePhonePad,
    EBKTEmailAddress,
    EBKTDecimalPad,
    EBKTTwitter,
    EBKTWebSearch,
    EBKTTextCapCharacters,
    EBKTTextCapWords,
    EBKTTextCapSentences,
    EBKTTextAutoCorrect,
    EBKTTextAutoComplete,
    EBKTTextNoSuggestions,
    EBKTTextEmailSubject,
    EBKTTextShortMessage,
    EBKTTextLongMessage,
    EBKTTextPersonName,
    EBKTNumberSigned,
    EBKTNumberDecimal,
    EBKTDatetime,
    EBKTDate,
    EBKTTime
} TEditBoxKeyboardType;

typedef	enum {
    PTDialog,
    PTPage,
    PTContainer,
    PTScrollView,
    PTNavigationBar,
    PTTabBar
} TPageType;

typedef enum {
    STSha160,
    STSha224,
    STSha256,
    STSha384,
    STSha512
} TShaType;

typedef enum {
    DITBase64,
    DITHexadecimal,
    DITByte
} DataInputType;

typedef enum {
    DBBTConstant,
    DBBTObjectAttribute,
    DBBTDataSet,
    DBBTResource,
    DBBTNotUsedType,
    DBBTSystemVariable,
    DBBTCustomVariable,
    DBBTBindValue
} TDataBridgeBindingType;

/**
 * SMF.UI.Alignment.topLeft
SMF.UI.Alignment.top
SMF.UI.Alignment.topRight
SMF.UI.Alignment.left
SMF.UI.Alignment.center
SMF.UI.Alignment.right
SMF.UI.Alignment.bottomLeft
SMF.UI.Alignment.bottom
SMF.UI.Alignment.bottomRight
 */
typedef enum {
    TIATTopLeft = 0x03,
    TIATTop = 0x07,
    TIATTopRight = 0x06,
    TIATLeft = 0x0B,
    TIATCenter = 0x0F,
    TIATRight = 0x0E,
    TIATBottomLeft = 0x09,
    TIATBottom = 0x0D,
    TIATBottomRight = 0x0C,
} TImageAlignmentType;

typedef enum {
    DTCTBinary,
    DTCTFloat,
    DTCTInteger,
    DTCTString,
    DTCTDateTime
} TDataTableColumnType;

typedef enum {
    DSORefreshed = 0x01,
    DSOIndexChanged = 0x02,
    DSORowAdded = 0x04,
    DSORowDeleted = 0x08,
    DSORowUpdated = 0x10,
    DSONewBinaryAdded = 0x20
} TDataSetOperation;

typedef enum {
    FSNormal,
    FSBold,
    FSItalic
} TFontStyle;

typedef enum {
    VCSNone,
    VCSEmbedded,
    VCSFullScreen
} TVideoControlStyla;

typedef enum {
    MSMNone,
    MSMAspectFit,
    MSMAspectFill,
    MSMModeFill
} TMovieScalingMode;

typedef enum {
    SVISDefault,
    SVISBlack,
    SVISWhite
} TScrollViewIndicatorStyle;

typedef enum {
    PTNone,
    PTUpToDown,
    PTDownToUp,
    PTRightToLeft,
    PTLeftToRight,
    PTFlipFromLeft,
    PTFlipFromRight,
    PTCurlUp,
    PTCurlDown
} TPageEffectType;

typedef enum {
    PESTPush,
    PESTCover,
    PESTReveal
} TPageEffectSubType;

typedef enum {
    LTAbsolute,
    LTLinear,
    LTFlow
} TLayoutType;

typedef enum {
    PENone,
    PEAccelerating,
    PEDecelerating,
    PEPlain,
    PEAccelerateAndDecelerate,
    PEBounce
} TPageEffectEase;

typedef enum {
    ATPostToFacebook,
    ATPostToTwitter,
    ATPostToWeibo,
    ATMessage,
    ATMail,
    ATPrint,
    ATCopyToPasteboard,
    ATAssignToContact,
    ATSaveToCameraRoll,
    ATAddToReadingList,
    ATPostToFlickr,
    ATPostToVimeo,
    ATPostToTencentWeibo,
    ATAirDrop,
} TActivityType;

typedef enum {
    CUEra = 1,
    CUYear,
    CUMonth,
    CUDay,
    CUHour,
    CUMinute,
    CUSecond,
    CUWeekday,
    CUWeekdayOrdinal
} TCalendarUnit;

typedef enum {
    FLApplicationUsageDurations = 0x01,
    FLNetworkUsage = 0x02,
    FLApplicationStartEvents = 0x04,
    FLAudioPlayDurations = 0x08,
    FLVideoPlayDurations = 0x10,
    FLShowPageActions = 0x20,
    FLCallActions = 0x40,
    FLSendSMSActions = 0x80
} TFlurryLog;

typedef enum {
	TINYXML_DOCUMENT = 0,
	TINYXML_ELEMENT = 1,
	TINYXML_COMMENT = 2,
	TINYXML_UNKNOWN = 3,
	TINYXML_TEXT = 4,
	TINYXML_DECLARATION = 5,
	TINYXML_TYPECOUNT = 6
} TiXmlNodeTypes;

typedef enum {
    CRTLinear,
    CRTDataMatrix,
    CRTQRCode
} TCodeReaderType;

typedef enum {
    AAODeviceOrientationUnknown = 0x01,
    AAODeviceOrientationPortrait = 0x02,
    AAODeviceOrientationUpsideDown = 0x04,
    AAODeviceOrientationLandscapeRight = 0x08,
    AAODeviceOrientationLandscapeLeft = 0x10,
    AAODeviceOrientationFaceUp = 0x20,
    AAODeviceOrientationFaceDown = 0x40
} TApplicationAllowedOrientation;

typedef enum {
    EBRKTDone,
    EBRKTGo,
    EBRKTNext,
    EBRKTSearch,
    EBRKTSend
} TEditBoxReturnKeyType;

typedef enum {
    RKTDefault = 1,
    RKTGo,
    RKTGoogle,
    RKTJoin,
    RKTNext,
    RKTRoute,
    RKTSearch,
    RKTSend,
    RKTYahoo,
    RKTDone,
    RKTEmergencyCall,
    RKTActionPrevious
} TReturnKeyType;

typedef enum {
    OPortrait,
    OLandscape
} TOrientation;

typedef enum {
	TGradientLeftToRight,
	TGradientTopToBottom,
	TGradientLeftTopToRightBottom,
	TGradientRightTopToLeftBottom,
	TGradientRadian,
} TGradient;

typedef enum {
    AISWhite,
    AISGray,
    AISWhiteLarge
} TActivityIndicatorStyle;

typedef enum {
    BCMCBC,
    BCMECB,
    BCMCFB,
    BCMOFB,
    BCMCTR
} TBlockCipherMode;

typedef enum {
    CMEncrypt,
    CMDecrypt
} CryptoMode;

typedef enum {
    TCPTDefault,
    TCPTNo,
    TCPTPKCS
} TCryptoPaddingType;

typedef enum {
    RHNone,
    RHNotScrolling,
    RHScrolling
} TRepeatBoxHeader;

typedef enum {
    LOHorizontal,
    LOVertical
} TLayoutOrientation;

typedef enum {
    LALeftORTop,
    LARightORBottom,
    LACenter,
    LAJustified
} TLayoutAlignment;

typedef enum {
    WWMAppend,
    WWMOverWrite
} TWebobjectWriteMode;

typedef enum {
    MTOptional = 0,
    MTContextual = 1,
    MTPopup = 2,
} TMenuType;

typedef enum {
    TRPurchased,
    TRRestored,
    TRKeyInvalid,
    TRUserCancelled,
    TRGenericError
} TTransactionResult;

typedef enum {
	BVTNotDefined,
	BVTConstant,
	BVTDataSet,
	BVTVariable,
	BVTObjectValue,
	BVTResourceProtocol,
	BVTUnknown,
} BVTypes;

typedef enum {
	GVTPixel,
	GVTPercent,
	GVTDp,
	GVTPunto,
} GeometryValueTypes;

typedef enum {
	TLCFromDataset,
	TLCFromConstantValue
} TLineChartDFType;

typedef enum {
	THMGet,
	THMPost,
	THMPut,
	THMDelete,
} THttpMethod;


typedef enum {
	TLTDemo,
	TLTCommunity,
	TLTFull,
} TLicenceType;

typedef enum {
    TISANone,
    TISAFade
} TImageSwitchAnimation;

typedef enum {
    HTMLCTypeJson,
    HTMLCTypeXML,
    HTMLCTypeOther
} HTMLContentType;

typedef enum {
    AppCTCall,
    AppCTCallBack
} AppCallType;

typedef enum {
    NTLocal,
    NTRemote
} NotificationType;

typedef enum {
    KBBDone,
    KBBCancel,
    KBBEdit,
    KBBSave,
    KBBAdd,
    KBBFlexibleSpace,
    KBBFixedSpace,
    KBBCompose,
    KBBReply,
    KBBAction,
    KBBOrganize,
    KBBBookmarks,
    KBBSearch,
    KBBRefresh,
    KBBStop,
    KBBCamera,
    KBBTrash,
    KBBPlay,
    KBBPause,
    KBBRewind,
    KBBFastForward,
    KBBUndo,
    KBBRedo,
    KBBPageCurl
} KBarButtonSystemItem;

typedef enum {
    KBSPlain,
    KBSBordered,
    KBSDone
} KBarButtonStyle;

typedef enum {
    KTVTText,
    KTVTImage
} KTitleViewType;

typedef enum {
    KITALeft,
    KITACenter,
    KITARight,
    KITAJustified,
    KITANatural
} KIOSTextAlignment;

typedef enum {
    IOSTRead,
    IOSTWrite,
    IOSTAppend
} IOStreamType;

typedef enum {
    IOAPApplicationDataDirectory,
    IOAPApplicationCacheDirectory,
    IOAPApplicationResources,
    IOAPApplicationTemporaryData,
    IOAPExternalStroges,
} IOApplicationPath;

typedef enum {
	WCRHAutomatic,
	WCRHForceFile,
	WCRHForceText,
	WCRHNone,
} WCResponseHandling;

typedef enum {
    KRRAFade,
    KRRARight,
    KRRALeft,
    KRRATop,
    KRRABottom,
    KRRANone,
    KRRAMiddle,
    KRRAAutomatic
} KRepeatBoxRowAnimation;

struct CropImageOption {
    int aspectX;
    int aspectY;
    int outputX;
    int outputY;
};

#define KConfigFile                         "config.bin"
#define KDataFile                           "data.smf"
#define KSettingsFile                       "settings.bin"
#define KVariablesTable                     "tblSmfVariables"
#define KSettingsTable                      "tblSmfSettings"
#define KImageCacheTable                    "tlbSmfImageCacheTbl"
#define KImageCacheStatusTable              "tlbSmfImageCacheStatusTbl"
#define KTLSymbol                           "\xc2\xa8"
#define KTLFont                             "AbakuTLSymSans"

#define KFalse                              "false"
#define KTrue                               "true"
#define KFirstStart                         "firststart"

#define KMaxInt32                           0x7FFFFFFF
#define KErrNone                            0
#define KErrGeneric                        -1
#define DEFAULTMAXCHARS                     5000
#define KSpPageEffectDuration1              0.25
#define KSpPageEffectDuration2              0.60
#define KSPageNativeDuration                0.5
#define KDialogEffectDuration               0.35
#define KButtonTextMargin                   2
#define PAGE_CACHE_SIZE						3
#define KDefaultWebTimeOutValue             60

#define KSpYES                              "1"
#define KSpNO                               "0"
#define KNetworkNotAvailable                "0"
#define KNetworkWWAN                        "1"
#define KNetworkWiFi                        "2"
#define KAppActive                          "0"
#define KAppInactive                        "1"
#define KAppBackground                      "2"

#ifndef _WINRT_DLL
#define MOBINEX_MUTEX pthread_mutex_t
#else
#define MOBINEX_MUTEX std::mutex
#endif

#ifndef _WINRT_DLL
#define MOBINEX_MUTEX_INIT(lockmutex) pthread_mutex_init(&lockmutex,NULL)
#else
#define MOBINEX_MUTEX_INIT(lockmutex)
#endif

#ifndef _WINRT_DLL
#define MOBINEX_MUTEX_DESTROY(lockmutex) pthread_mutex_destroy(&lockmutex)
#else
#define MOBINEX_MUTEX_DESTROY(lockmutex)
#endif


#ifndef _WINRT_DLL
//#define MOBINEX_MUTEX_LOCK(lockmutex) __android_log_print(ANDROID_LOG_DEBUG,"LOCK","LOCK < line=%d file=%s",__LINE__,__FILE__);  pthread_mutex_lock(&lockmutex); __android_log_print(ANDROID_LOG_DEBUG,"LOCK","LOCK > line=%d file=%s",__LINE__,__FILE__)
#define MOBINEX_MUTEX_LOCK(lockmutex) pthread_mutex_lock(&lockmutex)
#define MOBINEX_MUTEX_LOCK_(lockmutex) pthread_mutex_lock(&lockmutex)
#else
#define MOBINEX_MUTEX_LOCK(lockmutex) lockmutex.lock()
#endif

#ifndef _WINRT_DLL
//#define MOBINEX_MUTEX_UNLOCK(lockmutex) __android_log_print(ANDROID_LOG_DEBUG,"LOCK","UNLOCK < line=%d file=%s",__LINE__,__FILE__); pthread_mutex_unlock(&lockmutex); __android_log_print(ANDROID_LOG_DEBUG,"LOCK","UNLOCK > line=%d file=%s",__LINE__,__FILE__)
#define MOBINEX_MUTEX_UNLOCK(lockmutex) pthread_mutex_unlock(&lockmutex)
#define MOBINEX_MUTEX_UNLOCK_(lockmutex) pthread_mutex_unlock(&lockmutex)
#else
#define MOBINEX_MUTEX_UNLOCK(lockmutex) lockmutex.unlock()
#endif

#ifndef _WINRT_DLL
#define MOBINEX_COND_BROADCAST(cond) pthread_cond_broadcast(&cond)
#else

#endif

#ifndef _WINRT_DLL
#define MOBINEX_COND_SIGNAL(cond) pthread_cond_signal(&cond)
#else

#endif

#ifndef _WINRT_DLL
#define MOBINEX_COND_WAIT(cond, lockmutex) pthread_cond_wait(&cond, &lockmutex)
#else

#endif

#define JS_COLLECT_INVALIDATE
#undef JS_COLLECT_INVALIDATE

#ifdef JS_COLLECT_INVALIDATE
	#define JS_INVALIDATE_VIEW(view) \
		if(SpContext::GetInstance()->invalidatedObjs[view]) \
		{ \
			SpContext::GetInstance()->invalidatedObjs[view] += 1; \
		} \
		else \
		{ \
			SpContext::GetInstance()->invalidatedObjs[view] = 1; \
		}
#else
	#define JS_INVALIDATE_VIEW(view) view->Invalidate();
#endif

#endif
