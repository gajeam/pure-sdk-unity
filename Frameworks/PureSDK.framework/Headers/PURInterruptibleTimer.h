//
//  PURInterruptibleTimer.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/20/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PUREventStore, PURQueue;

NS_ASSUME_NONNULL_BEGIN

// Timer does NOT trigger while testing. The pur_fireTimerNow method has to be used.
@interface PURInterruptibleTimer : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString * _Nullable)name
                       queue:(PURQueue *)queue;

- (instancetype)initWithName:(NSString * _Nullable)name
                       queue:(PURQueue *)queue
                      strict:(BOOL)strict;

// Returns zero if the timer is not running.
@property (nonatomic, readonly) NSTimeInterval fireTimestamp;
@property (nonatomic, readonly) NSTimeInterval secondsWaited;

@property (nonatomic, readonly) NSString *timerName;
@property (nonatomic, readonly) NSTimeInterval timeInterval;
@property (nonatomic, readonly) NSTimeInterval tolerance; // adjusted based on max tolerance
@property (nonatomic, readonly) BOOL isRunning;

- (void)scheduleTimerWithInterval:(NSTimeInterval)interval
                 overrideExisting:(BOOL)overrideExisting
                          repeats:(BOOL)repeats
                            block:(void (^)(void))block;

- (void)scheduleTimerWithInterval:(NSTimeInterval)interval
                 overrideExisting:(BOOL)overrideExisting
                          repeats:(BOOL)repeats
                            block:(void (^)(void))block
                        shouldLog:(BOOL)shouldLog;

// behaves like overrideExisting:NO, repeats:YES
// Times the length of the first interval according to how long ago lastRepeatTimestamp was.
// May trigger the block immediately.
- (void)scheduleLongRunningRepeatingTimerWithInterval:(NSTimeInterval)fullRepeatInterval
                       lastRepeatTimestamp:(NSTimeInterval)lastRepeatTimestamp
                                     block:(void (^)(void))block;

- (void)interruptTimer;

- (NSDictionary *)serialized;

@end

NS_ASSUME_NONNULL_END
