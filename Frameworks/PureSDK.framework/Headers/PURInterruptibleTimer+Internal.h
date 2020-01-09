//
//  PURInterruptibleTimer+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 12/28/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURInterruptibleTimer.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURInterruptibleTimer (Internal)

- (void)pur_fireTimerNow;

- (void)pur_scheduleTimerWithInterval:(NSTimeInterval)interval
                     overrideExisting:(BOOL)overrideExisting
                              repeats:(BOOL)repeats
                                block:(void (^)(void))block
                            shouldLog:(BOOL)shouldLog
            allowSchedulingDuringTest:(BOOL)allowSchedulingDuringTest;


@end

NS_ASSUME_NONNULL_END

