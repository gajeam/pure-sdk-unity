//
//  PUREventIntervalSerializer.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/17/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURIntervalProtocol.h>
#import <PureSDK/PURMulticastDispatcher.h>

@class PURServiceLocator, PUREventStore, PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PUREventIntervalSerializer<EventClass: NSManagedObject<PURExportableEvent> *, IntervalClass: PURIntervalObject *> : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                 frameworkQueue:(PURQueue *)queue
                concurrentQueue:(PURQueue *)concurrent
                  intervalClass:(Class)intervalClass // should be a NSManagedObject<PURIntervalProtocol>
                  matchingClass:(Class)matchingClass // should be a NSManagedObject<PURExportableEvent>
         queueDataDirectoryName:(NSString *)queuedDirectory
   queueDataBackupDirectoryName:(NSString *)queuedBackupDirectory
                      logPrefix:(NSString *)logPrefix
      shouldExportAsEventsArray:(BOOL)shouldExportAsEventsArray;

@property (nonatomic, readonly) PURMulticastDispatcher<NSArray<PURIntervalObject *> *> *serializedIntervalsDispatcher;
@property (nonatomic) BOOL shouldBroadcastSerializedIntervals;

- (void)serializeEventsForProducedBatches:(dispatch_group_t)takeOffGroup;

- (void)serializeAllEligibleEventsCompletion:(void (^)(void))completion;

- (void)serializeCreatedEventIntervalsForUpload:(NSArray<IntervalClass> *)intervalsForSerilization
                                     completion:(void (^ _Nullable)(NSArray<IntervalClass> *))completion;

@end

NS_ASSUME_NONNULL_END
