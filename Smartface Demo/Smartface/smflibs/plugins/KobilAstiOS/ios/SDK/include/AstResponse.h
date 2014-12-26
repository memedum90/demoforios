#import "AstSdkTypes.h"

/**
 * @brief Response received over an AstChannel
 *
 * The response for a transfer over AstChannel. Check {@link getStatus} to see if the
 * transfer finished successfully. In that case this object contains the received data and header.
 *
 * If {@link getStatus} indicates an error during transfer, the {@link getHttpCode} and {@link getInternalError} provide
 * additional information on the actual error.
 */
@protocol AstResponse

/**
 * @return the received http response
 */
- (NSData*)getReceivedData;

/**
 * @return the {@link AstTransferStatus} for the transfer that generated this response.
 */
- (AstTransferStatus)getStatus;

/**
 * @return the received header during transfer ast NSArray of NSString; it is not possible to access the cookie headers "Set-Cookie", "Cookie" or "Set-Cookie2".
 */
- (NSArray*)getReceivedHeader;

/**
 * Same as {@link getReceivedHeader}, but returns HTTP header as dictionary.
 *
 * @return received HTTP header as NSDictionary with header names as keys and header values as dictionary values (all of type NSString)
 */
- (NSDictionary*)getReceivedHeaderMap;

/**
 * @return the received http response code
 */
- (long)getHttpCode;

/**
 * @return an internal error code for unmanaged errors
 */
- (int)getInternalError;
@end