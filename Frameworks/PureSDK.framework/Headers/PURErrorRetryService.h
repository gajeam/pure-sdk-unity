//
//  PURErrorRetryService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 3/27/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURErrorRetryService : PURService

- (void)logErrorHappened:(NSString *)name queue:(PURQueue *)queue errorRetry:(void (^)(NSInteger retryCount))retry;

- (void)logErrorResolved:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
