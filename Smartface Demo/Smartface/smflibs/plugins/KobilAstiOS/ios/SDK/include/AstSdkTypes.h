typedef enum AstStatus_ {
    AstStatus_OK,							/*!< 0 -- The process was completed successfully. */
    AstStatus_UPDATE_AVAILABLE,				/*!< 1 -- An update of the app is available. (Info only) */
    AstStatus_ACTIVATE_CERTIFICATE,			/*!< 2 -- Login failed, because device not yet activated. Please continue with activation. (Info only) */
    AstStatus_APP_REGISTERED,               /*!< Will be sent from SSMS to the app when the app registration was successful. (Info only) */
    AstStatus_USER_CANCEL,					/*!< The user cancelled a process, e.g. a transaction. */
    AstStatus_USER_CONFIRMATION_TIMEOUT,	/*!< The process was cancelled by a timeout. */
    AstStatus_INVALID_PIN,					/*!< The user entered a wrong pin. */
    AstStatus_INVALID_NEW_PIN_FORMAT,       /*!< The user specified a new PIN, but the format is not correct. */
    AstStatus_INVALID_ACTIVATION_CODE,		/*!< Activation process: The activation code does not match. */
    AstStatus_UNKNOWN_VERSION,				/*!< Activation and Logon process: The app has a wrong version. */
    AstStatus_UNKNOWN_CLIENT_TYPE,			/*!< Activation and Logon process: The app has a wrong type. */
    AstStatus_UPDATE_NECESSARY,				/*!< This version of the app was replace by a newer one and the user must update. */
    AstStatus_WRONG_CREDENTIALS,            /*!< Activation and Logon process: The user ID, activation code or the PIN are incorrect. */
    AstStatus_UNKNOWN_CERTIFICATE,			/*!< Activation process: SSMS does not know this certificate. */
    AstStatus_INTERNAL_ERROR,               /*!< An internal error occurred. */
    AstStatus_ACTIVATION_CODE_EXPIRED,		/*!< Activation process: The activation code expired. */
    AstStatus_LOCKED_CERTIFICATE,			/*!< Activation and Logon process: The app is locked. */
    AstStatus_LOCKED_USER,					/*!< Activation and Logon process: The user is locked. */
    AstStatus_INVALID_PUK,					/*!< Activation process and PIN recovery: The user entered a wrong PUK. */
    AstStatus_PROPERTY_NOT_EXISTS,			/*!< Requested property is not stored on SSMS. */
    AstStatus_INVALID_KEY_LENGTH,			/*!< Property key is too long. */
    AstStatus_NOT_UNIQUE,                   /*!< Sent property string is not unique for this user. */
    AstStatus_TEXT_TOO_LONG,                /*!< Sent property string is too long. */
    AstStatus_INVALID_STATE,                /*!< The AstSdk can't proceed the corresponding do-method call. */
    AstStatus_INVALID_DEVICE,               /*!< the corresponding do-method call cannot be proceeded with this device */
    AstStatus_INVALID_PARAMETER,			/*!< the one of the parameters of the called do-method has an invalid format */
    AstStatus_INVALID_USER_ID,              /*!< the given userId is invalid (e.g. no user credentials are available) */
    AstStatus_USER_ID_ALREADY_EXISTS,       /*!< User credentials already exists for the given userId at the user credential path */
    AstStatus_DEVICE_NOT_FOUND,             /*!< the selected device wasn't found (e.g. it has been removed from the system) */
    AstStatus_REGISTER_APP,                 /*!< the app isn't registered at SSMS */
    AstStatus_MISMATCHED_USER,              /*!< the certificate doesn't match to the user (e.g. typing error for the userId) */
    AstStatus_NEGATIVE,                     /*!< a negative status has been occured */
    AstStatus_READ_ONLY,                    /*!< Requested property is a read only property */
    AstStatus_TEMPORARY_LOCKED,             /*!< Logon process: The user ID is temporary locked by entering wrong PINs. */
    AstStatus_NOT_SUSPENDED,
} AstStatus;

typedef enum AstUpdateStatus_ {
    AstUpdateStatus_OK,                         /*!< The process was completed successfully. */
    AstUpdateStatus_CANCELLED,                  /*!< The process was cancelled successfully. */
    AstUpdateStatus_INVALID_PARAMETER,          /*!< At least one parameter was invalid for the corresponding do-method. */
    AstUpdateStatus_INVALID_STATE,              /*!< The AstSdk can't proceed the corresponding do-method call. */
    AstUpdateStatus_DOWNLOAD_ERROR,				/*!< An error occured during the download of the update */
    AstUpdateStatus_INTERNAL_ERROR
} AstUpdateStatus;


typedef enum AstPinReason_ {
    AstPinReason_TRANSPORT_PIN,             /*!< deprecated */
    AstPinReason_TRANSACTION,               /*!< PIN to confirm a transaction is required */
    AstPinReason_PREVIOUS_PIN_WRONG         /*!< deprecated */
} AstPinReason;


typedef enum AstCheckPinReason_ {
    AstCheckPinReason_SC_BLOCKED,
    AstCheckPinReason_SC_INVALID,
    AstCheckPinReason_SC_NEED_PIN,
    AstCheckPinReason_SC_NEED_PUK_PIN,
    AstCheckPinReason_SC_OK
} AstCheckPinReason;


typedef enum AstDeviceType_ {
    AstDeviceType_MIDENTITY,
    AstDeviceType_VIRTUAL_DEVICE
} AstDeviceType;


typedef enum AstMessageType_ {
    AstMessageType_INFO,
    AstMessageType_WARNING,
    AstMessageType_ERROR
} AstMessageType;


typedef enum AstConfirmation_ {
    AstConfirmation_OK,
    AstConfirmation_CANCEL,
    AstConfirmation_TIMEOUT
} AstConfirmation;


typedef enum AstConfirmationType_ {
    AstConfirmationType_NO_CONFIRMATION,
    AstConfirmationType_CONFIRMATION_REQUIRED,
    AstConfirmationType_SPLIT_CONFIRMATION
} AstConfirmationType;


typedef enum AstConfigParameter_ {
    AstConfigParameter_WHITELIST,
    AstConfigParameter_CONFIG_BUNDLE,
    AstConfigParameter_USER_CREDENTIALS_PATH,
    AstConfigParameter_CERTIFICATE_POLICY,  
    AstConfigParameter_SERVER_BUSY_TIMEOUT,
    AstConfigParameter_CONNECTION_RETRY_COUNTER,
    AstConfigParameter_CONNECTION_RETRY_INTERVAL,
    AstConfigParameter_USE_DEVICE_NAME_SOFTWARE,
    AstConfigParameter_USE_DEVICE_NAME_HARDWARE,
    AstConfigParameter_WEB_VIEW_BASIC_AUTH,
    AstConfigParameter_ALLOWED_HOST_DEVICES,
} AstConfigParameter;


#define AstProxyParameter_HOST @"ProxyParameter_HOST"
#define AstProxyParameter_PORT @"ProxyParameter_PORT"
#define AstProxyParameter_USERNAME @"ProxyParameter_USERNAME"
#define AstProxyParameter_PASSWORD @"ProxyParameter_PASSWORD"


typedef enum AstConnectionState_ {
    AstConnectionState_UNDEFINED,
    AstConnectionState_CONNECTED,
    AstConnectionState_CONNECTING,
    AstConnectionState_DISCONNECTED,
    AstConnectionState_DISCONNECTING,
    AstConnectionState_CONNECTION_LOST,
    AstConnectionState_RECONNECTED,
} AstConnectionState;


const static uint32_t AstPropertyFlags_NON_PERSISTANCE     = 0x01;
const static uint32_t AstPropertyFlags_VALUE_ENCRYPTED     = 0x02;
const static uint32_t AstPropertyFlags_CONFIDENTIAL        = 0x04;
const static uint32_t AstPropertyFlags_UNIQUE_TO_USER      = 0x08;
const static uint32_t AstPropertyFlags_IMMEDIATE           = 0x10;


typedef enum AstPropertyType_ {
    PropertyType_INVALID,
    PropertyType_OCTET_STRING,
    PropertyType_INTEGER,
    PropertyType_BOOLEAN,
    PropertyType_UTF8STRING,
    PropertyType_DATE
} AstPropertyType;


typedef enum AstPropertyOwner_ {
    AstPropertyOwner_DEVICE,
    AstPropertyOwner_USER,
    AstPropertyOwner_GROUP
} AstPropertyOwner;


typedef enum UrlBlockedReason_ {
    UrlBlockedReason_UNKNOWN_ERROR,
    UrlBlockedReason_WHITELIST_ERROR,
    UrlBlockedReason_CERTIFICATE_ERROR,
    UrlBlockedReason_CERTS_FROM_SERVER_EMPTY,
    UrlBlockedReason_TRUSTED_CERTS_EMPTY
} UrlBlockedReason;


typedef enum AstInformationKey {
    AstInformationKey_LOCAL_KS_DEVICE_NAME,
    AstInformationKey_DEVICE_SERIAL_NUMBER,
    AstInformationKey_SERVER_SUPPORTS_PROPERTIES,
    AstInformationKey_DEVICE_HARDWARE_VERSION,
    AstInformationKey_UNSUPPORTED_HOST_DEVICE,
} AstInformationKey;


typedef enum AstContextType_ {
    ContextType_MIDENTITY_MINI,
    ContextType_MIDENTITY_AIR,
    ContextType_MIDENTITY_AIR_PLUS,
    ContextType_VIRTUAL_DEVICE,
    ContextType_SSMS,
    ContextType_SYSTEM
} AstContextType;


typedef enum AstUpdateType_ {
    AstUpdateType_CLIENT,
    AstUpdateType_FIRMWARE,
} AstUpdateType;


typedef enum AstTransferStatus_ {
	AstTransferStatus_OK,					// If transfer completed successfully with http status 200
	AstTransferStatus_HTTP_STATUS,			// If transfer completed with a http status other than 200
	AstTransferStatus_SSL_ERROR,			// An SSL error occurred.
	AstTransferStatus_INTERNAL_ERROR,		// Internal error
	AstTransferStatus_CONN_FAILED,			// Connection to remote host could not be established
	AstTransferStatus_CONN_TIMEOUT,			// Transfer took longer than the allowed timeout.
	AstTransferStatus_CONN_CLOSED,			// The channel was already closed with AstChannel::closeConnection().
	AstTransferStatus_CONN_ABORTED,			// The transfer was aborted by calling AstChannel::cancelTransfer().
	AstTransferStatus_WRONG_THREAD,			// The channel was called from the wrong thread context.
	AstTransferStatus_INVALID_PARAMETER,	// request was null or a non-ssl URL was provided.
} AstTransferStatus;


typedef enum AstHttpMethod_ {
	AstHttpMethod_POST,
	AstHttpMethod_GET
} AstHttpMethod;


typedef enum AstLogLevel_ {
    AstLogLevel_TRACE,
    AstLogLevel_DEBUG,
    AstLogLevel_INFO,
    AstLogLevel_WARN,
    AstLogLevel_ERROR,
    AstLogLevel_FATAL,
} AstLogLevel;
