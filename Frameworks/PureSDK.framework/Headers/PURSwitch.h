//
//  PURSwitch.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/9/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

// Threadsafe wrapper for a BOOL.
// Callbacks are executed on a serial queue.
@interface PURSwitch : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithBool:(BOOL)value queue:(PURQueue *)queue;
- (instancetype)initWithBool:(BOOL)value queue:(PURQueue *)queue name:(NSString * _Nullable)name;

// Sets the value to YES.
// Returns NO if already enabled.
// Action is run only is return value is YES.
- (BOOL)tryEnableWithAction:(nullable void (^)(void))action;

// Sets the value to NO.
// Returns NO is already disabled.
// Action is run only is return value is YES.
- (BOOL)tryDisableWithAction:(nullable void (^)(void))action;

// Sets the the current value of the switch.
- (void)setValue:(BOOL)value action:(nullable void (^)(void))action;
@property (nonatomic) BOOL boolValue;

- (NSString *)observeOn:(PURQueue *)queue withBlock:(void (^)(BOOL value, NSString *token))block;
- (void)stopObservingWithToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
