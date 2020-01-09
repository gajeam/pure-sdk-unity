//
//  PUREventIntervalProducer.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/10/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURDefaultsKey.h>
#import <PureSDK/PURIntervalProtocol.h>
#import <PureSDK/PURMulticastDispatcher.h>

@class PURServiceLocator, PUREventIntervalProducer;
@class PURSerializeRequestOperation, PURQueue, PUREventInterval;
@class PURDefaultsTokenBag;

NS_ASSUME_NONNULL_BEGIN

// Listens to CoreData for inserted LogEvents, and emits EventInterval objects through delegate.
@interface PUREventIntervalProducer<EventClass: NSManagedObject<PURExportableEvent> *, IntervalClass: PURIntervalObject *> : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                maxBatchSizeKey:(PURDefaultsKey *)maxBatchSizeKey
          maxTimeBetweenBatches:(PURDefaultsKey *)maxTimeBetweenBatchesKey
               lastBatchTimeKey:(PURDefaultsKey *)lastBatchTimeKey
                          queue:(PURQueue *)queue
                      logPrefix:(NSString *)logPrefix
                       tokenBag:(PURDefaultsTokenBag *)tokenBag
         batchingObjectsOfClass:(Class)matchingClass // should be a NSManagedObject<PURExportableEvent>
         intoIntervalClass:(Class)intervalClass; // should be a NSManagedObject<PURIntervalProtocol>


@property (nonatomic, readonly) PURMulticastDispatcher<NSArray<PURIntervalObject *> *> *createdIntervalsDispatcher;
@property (nonatomic) BOOL shouldBroadcastProducedIntervals;

// `createdIntervalsBlock` will not be called before `takeOffWithDispatchGroup` is called.
- (void)countUnbatchedEvents:(dispatch_group_t)takeOffGroup shouldForceBatch:(BOOL)forceBatchEvents;

- (void)takeOffWithDispatchGroup:(dispatch_group_t)takeOffGroup
                forceBatchEvents:(BOOL)forceBatchEvents
             intervalsCompletion:(void (^ _Nullable)(NSArray *))completion;

// Force=YES creates a batch even if we have not reached max size.
- (void)createEventIntervalsForce:(BOOL)force
                       completion:(void (^ _Nullable)(NSArray<PURIntervalObject *> *))finalCompletion;

@end

NS_ASSUME_NONNULL_END
