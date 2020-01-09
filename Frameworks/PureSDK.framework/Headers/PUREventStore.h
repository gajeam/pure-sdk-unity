//
//  PUREventStore.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>

#import <PureSDK/PURService.h>

#import <PureSDK/PURLogEvent.h>
#import <PureSDK/PURMessageEvent.h>
#import <PureSDK/PURMessageInterval.h>
#import <PureSDK/PUREventInterval.h>
#import <PureSDK/PURBaseDataStore.h>
#import <PureSDK/PURAsyncBlockOperation.h>
#import <PureSDK/PURQueue.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^PURSingleObjectCompletion)(NSManagedObject * _Nullable, NSError * _Nullable);
typedef void (^PURQueryCompletion)(NSArray<NSManagedObject *> *, NSError * _Nullable);
typedef void (^PURCountQueryCompletion)(NSUInteger, NSError * _Nullable);

@interface PUREventStore : PURService

@property (nonatomic, readonly) NSString *persistentStoreType;

#pragma mark - Saving

- (void)saveChangesForce:(BOOL)force; // synchronous call
- (PUROperation *)saveChangesOperationForce:(BOOL)force
                                      queue:(PURQueue *)queue;

// callee passed block is called with the class name of the object that is inserted
// callback are executed on `queue`
- (NSString *)registerDidInsertObserverOnQueue:(PURQueue *)queue
                                      observer:(void (^)(NSManagedObject *object, NSString *token))didInsertBlock;

- (void)deregisterObserverForToken:(NSString *)token;

- (void)performBlockAndWait:(void (^)(NSManagedObjectContext *context))perform;

- (void)performContext:(id _Nullable (^)(NSManagedObjectContext *context, NSError * __autoreleasing *errorp))perform
       completionQueue:(PURQueue * _Nullable)queue
            completion:(void (^ _Nullable)(id _Nullable performResult, NSError * _Nullable performError))completion;

- (void)performBlock:(id _Nullable (^)(void))perform
     completionQueue:(PURQueue * _Nullable)queue
          completion:(void (^ _Nullable)(id _Nullable))completion;

#pragma mark - Insertion

// modify blocks are run on the CoreData managed object context queue.
// completion blocks are run on passed in queue, concurrent SDK queue if nil.
- (void)insertEventIntervalOnQueue:(PURQueue * _Nullable)queue
                            modify:(void (^ _Nullable)(PUREventInterval *))modifyBlock
                        completion:(void (^ _Nullable)(PUREventInterval *))completion;

- (void)insertMessageIntervalOnQueue:(PURQueue * _Nullable)queue
                          modify:(void (^ _Nullable)(PURMessageInterval *))modifyBlock
                      completion:(void (^ _Nullable)(PURMessageInterval *))completion;

- (void)insertLogEventOnQueue:(PURQueue * _Nullable)queue
                       modify:(void (^ _Nullable)(PURLogEvent *))modifyBlock
                   completion:(void (^ _Nullable)(PURLogEvent *))completion;

- (void)insertMessageEventOnQueue:(PURQueue * _Nullable)queue
                           modify:(void (^ _Nullable)(PURMessageEvent *))modifyBlock
                       completion:(void (^ _Nullable)(PURMessageEvent *))completion;

- (void)insertObjectWithClass:(Class)objectClass
                        queue:(PURQueue * _Nullable)queue
                       modify:(void (^ _Nullable)(__kindof NSManagedObject *))modifyBlock
                   completion:(void (^ _Nullable)(__kindof NSManagedObject *))completion;

#pragma mark - Querying

// if completionQueue == nil, completion block called on concurrent SDK queue.

- (void)countForRequest:(NSFetchRequest *)request
                  queue:(PURQueue * _Nullable)queue
             completion:(PURCountQueryCompletion)completion;

- (void)countEventIntervalsForPredicate:(NSPredicate * _Nullable)eventPredicate
                                  queue:(PURQueue * _Nullable)completionQueue
                             completion:(PURCountQueryCompletion)completion;

- (void)countMessageEventsForPredicate:(NSPredicate * _Nullable)eventPredicate
                                 queue:(PURQueue * _Nullable)completionQueue
                            completion:(PURCountQueryCompletion)completion;

- (void)logEventsForQuery:(NSFetchRequest<PURLogEvent *> * _Nullable)query
                    queue:(PURQueue * _Nullable)completionQueue
               completion:(PURQueryCompletion)completion;

- (void)messageEventsForPredicate:(NSPredicate * _Nullable)predicate
                            queue:(PURQueue * _Nullable)completionQueue
                       completion:(PURQueryCompletion)completion;

- (void)eventIntervalsForPredicate:(NSPredicate * _Nullable)predicate
                             queue:(PURQueue * _Nullable)completionQueue
                        completion:(PURQueryCompletion)completion;

- (void)messageIntervalsForPredicate:(NSPredicate * _Nullable)predicate
                               queue:(PURQueue * _Nullable)completionQueue
                          completion:(PURQueryCompletion)completion;

- (void)resultsForQuery:(NSFetchRequest *)query
                  queue:(PURQueue * _Nullable)completionQueue
             completion:(PURQueryCompletion)completion;

#pragma mark - Deletion

- (void)deleteAllResultsForQuery:(NSFetchRequest *)query
                 matchingObjects:(void (^ _Nullable)(NSArray<__kindof NSManagedObject *> *))matchingObjects
                           queue:(PURQueue * _Nullable)completionQueue
                      completion:(PURErrorCompletion)completion;

@end

NS_ASSUME_NONNULL_END
