//
//  PURQueue.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/4/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/NSProcessInfo+PURProcessInfo.h>

@class PURAsyncBlockOperation, PUROperation;

NS_ASSUME_NONNULL_BEGIN

#define PURAssertOnTargetQueue(target) \
do { \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wshadow\"") \
    PURRequireNonNil(target); \
    PURAssert(pur_isOnQueue(target), @"Must be on targeted queue : %@ (%s:%i)", target.name, __FILE__, __LINE__); \
    _Pragma("clang diagnostic pop") \
} while (false);

#define PURCAssertOnTargetQueue(target) \
do { \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wshadow\"") \
    PURRequireNonNil(target); \
    PURCAssert(pur_isOnQueue(target), @"Must be on targeted queue : %@ (%s:%i)", target.name, __FILE__, __LINE__); \
    _Pragma("clang diagnostic pop") \
} while (false);

@interface PURQueue : NSObject

+ (instancetype)concurrent:(BOOL)concurrent name:(NSString *)name;

+ (instancetype)concurrent:(BOOL)concurrent
                      name:(NSString *)name
                  qosClass:(qos_class_t)qosClass
          relativePriority:(int)relativePriority;

+ (void)initializeQueues;

+ (void)waitForAllTasksToComplete:(void (^)(void))completion;

- (void)sync:(void (^)(void))block;
- (void)async:(void (^)(void))block; // if already on queue, just executes block
- (void)forceAsync:(void (^)(void))block; // always async
- (void)barrier_async:(void (^)(void))block;
- (void)after:(NSTimeInterval)wait exec:(void (^)(void))block;

- (void)notify:(dispatch_group_t)group block:(void (^)(void))block;

- (void)performAsync:(PUROperation *)operation
              result:(void (^ _Nullable)(__kindof NSObject *))result
             failure:(void (^ _Nullable)(NSError *))failure;

- (void)performAsync:(PUROperation *)operation
             success:(void (^ _Nullable)(void))success
             failure:(void (^ _Nullable)(NSError *))failure;

- (PUROperation * _Nullable)performAllAsync:(NSArray<PUROperation *> *)operations
                                    success:(void (^ _Nullable)(void))success
                                    failure:(void (^ _Nullable)(NSError *))failure;

@property (nonatomic, readonly, copy) NSString *name;
@property (nonatomic, readonly) BOOL isConcurrent;

// Use only if you really need to. Queuing tasks directly here will
// bypass the waiting system we've set up in blockingWaitForTasksToComplete
@property (nonatomic, readonly) dispatch_queue_t pur_internalQueue;
@property (nonatomic, readonly) NSOperationQueue *pur_operationQueue;

@property (nonatomic, class, readonly) PURQueue *serial;
@property (nonatomic, class, readonly) PURQueue *concurrent;
@property (nonatomic, class, readonly) PURQueue *highPriorityConcurrent;
@property (nonatomic, class, readonly) PURQueue *main;

@end

extern BOOL pur_isOnQueue(PURQueue *target);

NS_ASSUME_NONNULL_END
