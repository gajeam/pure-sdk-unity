//
//  PURPeriodicScanHelper.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/18/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURDefaultsService, PURDefaultsKey, PURDefaultsTokenBag, PURSwitch, PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURPeriodicScanHelper : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

// The prefix for each outputted log line.
// Format : {service name}> {emoji} {description}:

- (instancetype)initWithDefaultsService:(PURDefaultsService *)defaults
             enabledPhaseTimerLengthKey:(PURDefaultsKey *)enabledPhaseKey
            disabledPhaseTimerLengthKey:(PURDefaultsKey *)disabledPhaseKey
                                  queue:(PURQueue *)queue
                              logPrefix:(NSString *)logPrefix;

// If YES, then we're in one of 1-4 below.
@property (nonatomic, readonly) PURSwitch *isActive;

// Steps:
// 1. Immediately calls `startCallback` to start scanning.
// 2. If stopCallback returns YES, wait for `enabledPhaseDurationSetting` seconds. If NO, done.
// 3. Calls `stopCallback` to stop scanning.
// 4. Waits for `disabledPhaseDurationSetting`, then loop to #1
// Continues until `stop` is called.
- (void)startScanningWithStopCallback:(BOOL (^)(void))stopCallback
                        startCallback:(void (^)(void))startCallback;

// Resets the scanning cycle to #1 no matter where we're currently at.
- (void)scanNowIfWaiting;

// Resets all timers thus interrupts an active scan iteration
// Also, if there is currently a scan ongoing, then call the stop callback.
- (void)stop;

@end

NS_ASSUME_NONNULL_END
