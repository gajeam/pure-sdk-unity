//
//  PURObserver.h
//  PureSDK
//
//  Created by K on 3/26/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURObserver.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURObserverCallback)(NSArray *values);

// mimics +[RACSignal combineLatest:]
@interface PURObserver : NSObject

@property (nonatomic, readonly) NSUInteger numberOfSources;
@property (nonatomic, readonly) NSString *name;

// callback will be called on the concurrent sdk queue when `lastValuesFromSources` changes
@property (nonatomic, copy, readonly) void(^callback)(NSArray *lastValuesFromSources);

- (void)registerOnDeallocCallback:(void (^)(void))callback;

// generic, callback will be called on concurrent sdk queue
+ (nullable instancetype)initWithSourceCount:(NSUInteger)N
                                        name:(NSString *)name
                                       queue:(PURQueue *)queue
                                    callback:(nullable void (^)(NSArray *))callback;

// Treating nil values as [NSNull null] and vice versa.
// nil values mapped are stored as [NSNull null] in `lastValuesFromSources`
- (void)updateLastValueForSourceAtIndex:(NSUInteger)i withValue:(id)value;
- (void)updateLastValueForSourceAtIndexes:(NSIndexSet *)indexes withValues:(NSArray *)values;

- (PURObserver *)observerWithName:(NSString *)name queue:(PURQueue *)queue additionalCallback:(void (^)(NSArray *))callback;

@end

@class PURDefaultsKey, PURDefaultsService, PURDefaultsTokenBag;

@interface PURObserver (Initialization)

// Merging/flattening sub-observers
// For example: given observer A with slots [ a0, a1 ] and observer B with slots [ b0, b1, b2 ].
// Combining them would result in a new observer with slots [ a0, a1, b0, b1, b2 ]
+ (instancetype)instanceByMergingObservers:(NSArray<PURObserver *> *)observers
                                      name:(NSString *)name
                                     queue:(PURQueue *)queue
                                  callback:(void (^ _Nullable)(NSArray *))callback;

+ (instancetype)initWithDefault:(PURDefaultsKey *)defaultKey
                defaultsService:(PURDefaultsService *)defaultsService
                       tokenBag:(PURDefaultsTokenBag *)tokenBag
                          queue:(PURQueue *)queue
                       callback:(nullable void (^)(NSArray *))callback; // callback will be called on the concurrent sdk queue

+ (NSMutableArray<PURObserver *> *)observersForDefaultKeys:(NSArray<PURDefaultsKey *> *)defaultKey
                                                      defaultsService:(PURDefaultsService *)defaultsService
                                                             tokenBag:(PURDefaultsTokenBag *)tokenBag
                                                                queue:(PURQueue *)queue;

+ (PURObserver *)observerForDefaultKey:(PURDefaultsKey *)defaultKey
                                  defaultsService:(PURDefaultsService *)defaultsService
                                         tokenBag:(PURDefaultsTokenBag *)tokenBag
                                            queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
