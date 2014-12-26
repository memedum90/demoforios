#import "AstSdk.h"
#import "AstSdkListener.h"


/**
 * @brief Creation and destruction of AstSdk objects.
 */
@interface AstSdkFactory : NSObject

/**
 * \brief create an AstSdk instance
 *
 * The returned AstSdk instance is a global object with an internal reference counter, i.e. the method will return the same instance as
 * long as the reference counter is positive. If you call this method twice, you have to call {@link AstSdkFactory::FreeAst} twice, too.
 *
 * @param[in] listener AstSdkListener instance; will be used only during first call (when the AskSdk object is created) and be ignored for further calls
 * @return AstSdk instance
 *
 * @warning You must not release the returned AstSdk instance. Use the {@link AstSdkFactory::FreeAst} method, if you don't need this object anymore.
 */
+ (id<AstSdk>)CreateAst:(id<AstSdkListener>)listener;

/**
 * @brief releases AstSdk object
 *
 * If no AstSdk object is created so far, this method does nothing.
 */
+ (void)FreeAst;

@end
