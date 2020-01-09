//
//  PURCommittableFlagWrapper.h
//  PureSDK
//
//  Created by K on 3/26/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue, PURObserver;

NS_ASSUME_NONNULL_BEGIN

@interface PURCommittableValueWrapper<T> : NSObject

@property (nonatomic, readonly, nullable) T value;
@property (nonatomic, readonly, copy, nullable) void (^commitBlock)(T _Nullable newValue, T _Nullable oldValue);

// `commitBlock` will be called if `newValue` is different from `value`
- (void)commitWithValue:(id _Nullable)newValue;

+ (instancetype)instanceWithQueue:(PURQueue *)queue
                      commitBlock:(void (^ _Nullable)(T _Nullable newValue, T _Nullable oldValue))commitBlock;

+ (instancetype)instanceWithQueue:(PURQueue *)queue
                             name:(NSString * _Nullable)name
                      commitBlock:(void (^ _Nullable)(id _Nullable newValue, id _Nullable oldValue))commitBlock;

- (NSString *)observe:(void (^)(id _Nullable, NSString *))block on:(PURQueue *)queue;

- (void)deregisterObserverFor:(NSString *)token;

- (PURObserver *)valueObserverOnQueue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
