//
//  PURAPIRequestTemplate.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/7/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PURHTTPMethod) {
    PURHTTPMethodGet = 1,
    PURHTTPMethodPost,
    PURHTTPMethodPut
};

extern NSString *pur_httpMethodToString(PURHTTPMethod method);

@interface PURAPIRequestTemplate : NSObject

@property (nonatomic, readonly) PURHTTPMethod method;
@property (nonatomic, copy, readonly) NSString *path;

@property (nonatomic) BOOL requiresWiFi;
@property (nonatomic) NSDate *earliestBeginDate;
@property (nonatomic) NSTimeInterval timeoutInterval;

@property (nonatomic) NSDictionary<NSString *, NSString *> *extraHeaders;

@property (nonatomic, readonly, copy, nullable) id parameters;

// gzip headers will be added if [bodyData pur_isGzippedData] = YES`
@property (nonatomic, readonly, nullable) NSData *bodyData;

// or file is ASSUMED to be gzipped, and gzip headers will be added
@property (nonatomic, readonly, nullable) NSURL *bodyDataURL;

// Automatically set when bodyData is supplied, or by expectedFileSize.
@property (nonatomic, readonly) NSUInteger bodyDataURLSize;

@property (nonatomic) NSString *downloadLocationPath; // if set, result is saved to disk

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithMethod:(PURHTTPMethod)method path:(NSString *)path
                             parameters:(id _Nullable)parameters;

- (nullable instancetype)initWithMethod:(PURHTTPMethod)method path:(NSString *)path
                               bodyData:(NSData * _Nullable)bodyData;

- (nullable instancetype)initWithMethod:(PURHTTPMethod)method path:(NSString *)path
                                fileURL:(NSURL *)fileURL fileURLSize:(NSUInteger)bytes;

@end

NS_ASSUME_NONNULL_END
