//
//  PUREventThrottler.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/18/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PURDefaultsService, PURDefaultsKey, PURDefaultsTokenBag, PURQueue;

// Used for filtering out events that happen more frequently than every `minInterval` secs
@interface PUREventThrottler : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDefaultService:(PURDefaultsService *)defaultsService
                        minIntervalKey:(PURDefaultsKey *)defaultKey
                                 queue:(PURQueue *)target
                             logPrefix:(NSString * _Nullable)name;

- (void)reset;

- (void)forgetEventWithId:(NSString *)identifier;

- (BOOL)recordEventForIdIfPossible:(NSString *)identifier atTimestamp:(NSTimeInterval)timestamp;
- (void)recordEventWithId:(NSString *)identifier atTimestamp:(NSTimeInterval)timestamp;

// Calls didLog if no other callers call with the same identifiers.
- (void)debounceEvent:(NSString *)identifier didLogEvent:(void (^)(void))didLog;
- (void)debounceEvent:(NSString *)identifier shouldLogSchedule:(BOOL)logSchedule didLogEvent:(void (^)(void))didLog;

- (void)cancelDebounceEvent:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
