//
//  PURBackgroundCloudConfigFetcher.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURServiceLocator, PURQueue, PURDefaultsKey, PURDefaultsTokenBag;

NS_ASSUME_NONNULL_BEGIN

@interface PURBackgroundCloudConfigFetcher : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic) NSTimeInterval configFetchInterval;

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                          queue:(PURQueue *)queue
    lastConfigFetchTimestampKey:(PURDefaultsKey *)lastConfigFetchTimestampKey
                  fetchedConfig:(void (^)(NSDictionary *))config API_AVAILABLE(ios(11.0));

- (void)takeOff API_AVAILABLE(ios(11.0));

@end

NS_ASSUME_NONNULL_END
