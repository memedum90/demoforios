#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"
#import "AstRequest.h"

/**
 * @brief For convinient creation of AstRequest objects
 *
 * Builder class for {@link AstRequest}. Generate an instance similar to the following code
 * example:
 *
 * <code>AstRequest * test = [[[[[[AstBuilder alloc] initWithUrl: @"https://www.kobil.com"] timeout:60] header:foo] transferData:data] build];</code>
 *
 * It is possible to reuse a Builder instance for the creation of multiple objects.
 */
@interface AstBuilder: NSObject

/**
 * Build a new AstBuilder instance. The URL must be a valid SSL URL.
 * @param[in] URL URL for the request
 */
- (id)initWithUrl:(NSString*)URL;

/**
 * Set transfer timeout. Use 0 for infinity. Default is 0.
 *
 * @param[in] timeout timeout of transfer
 */
- (AstBuilder*)timeout:(int)timeout;

/**
 * Set a list of additional http headers. Default is an empty list of headers. It is
 * not allowed to set the cookie headers "Set-Cookie", "Cookie" or "Set-Cookie2".
 * Any headers already set are overwritten.
 *
 * @param[in] headers HTTP headers to be set
 */
- (AstBuilder*)header:(NSArray*)headers;

/**
 * Same as method {@link header:}, but takes NSDictionary of NSStrings as parameter.
 * Any headers already set are overwritten.
 *
 * @param[in] headers HTTP headers to be set
 */
- (AstBuilder*)headerMap:(NSDictionary*)headers;

/**
 * Set the http method for this transfer. Default is http "GET".
 *
 * @param[in] method HTTP method
 */
- (AstBuilder*)httpMethod:(AstHttpMethod)method;

/**
 * Set data to be transfered. Default is an empty byte array (0 bytes).
 *
 * @param[in] data data to be transfered
 */
- (AstBuilder*)transferData:(NSData*)data;

/**
 * Create a AstRequest using the currently set parameters for a transfer.
 * @note If ARC is not used, caller gets ownership of returned object.
 */
- (AstRequest*)build;
@end
