#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"
#import "AstRequest.h"
#import "AstResponse.h"

/**
 * @brief Generic communication channel for https-communication.
 *
 * Each channel can perform independent transfers with remote servers. SSL authentication is based
 * on the trusted_certs.pem known to the AstSdk.
 *
 * For each thread there can be only a single AstChannel instance. The App can get the channel instance of
 * the current thread with getAstChannel(). Each transfer is synchronous and will be initiated by
 * calling {@link transfer:}. Upon completion of the HTTP-transfer this function will return a
 * AstResponse object with the server response.
 *
 * Each AstChannel may only be used from its thread. However, {@link cancelTransfer} may be called from other
 * threads to cancel blocking transfers before timeout.
 *
 * It is possible to share cookies between different AstChannel instances and and the WebView. Only
 * cookies as defined by RFC 2109 are supported. Cookie sharing can be controlled with
 * {@link AstSdk::enableCookieSharing:}. By default it is enabled.
 *
 * Calling {@link AstSdk::exit:} closes all AstChannel instances.
 */
@protocol AstChannel

/**
 * Perform a http transfer. This is a blocking call. Close the current http connection. May
 * only be called from the thread the AstChannel belongs to.
 *
 * @param[in] request AstRequest to transfer
 * @return AstResponse instance with the result of the transfer
 */
- (id<AstResponse>)transfer:(AstRequest*)request;

/**
 * Mark a pending http transfer on this channel to be cancelled as soon as possible. This
 * function may be called from a different thread context. The function returns immediately,
 * the transmission is only cancelled when its {@link transfer:} returns.
 */
- (void)cancelTransfer;

/**
 * Close the current http connection. May only be called from the thread the AstChannel belongs to.
 */
- (void)closeConnection;

@end