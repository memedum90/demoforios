#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"

/**
 * @brief Request to be sent over an AstChannel
 *
 * An actual request to be sent over an AstChannel. A request instance is created by using the AstBuilder class.
 * Each AstRequest instance is immutable.
 */
@interface AstRequest : NSObject
/**
 * @return the Url
 */
- (NSString*)getUrl;

/**
 * @return the timeout
 */
- (int)getTimeout;

/**
 * @return the httpMethod
 */
- (AstHttpMethod)getHttpMethod;

/**
 * @return the http header as array of NSString
 */
- (NSArray*)getHeader;

/**
 * @return the http header as dictionary with the header name (not including the ": ") as key and header value as dictionary value (all of type NSString)
 */
- (NSDictionary*)getHeaderMap;

/**
 * @return the data to be sent
 */
- (NSData*)getSendData;
@end
