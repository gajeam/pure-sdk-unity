//
//  PURBaseDataStore.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import <PureSDK/PURBlockDefinitions.h>

@class PURQueue;
@class PURDefaultsService;
@class PUROperation;

NS_ASSUME_NONNULL_BEGIN

@interface PURBaseDataStore : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithQueue:(PURQueue *)queue
                 databaseName:(NSString *)databaseName;

// Must be called before any queries can be processed.
- (void)initializeCoreDataWithPersistentStoreType:(NSString *)persistentStoreType
                                  defaultsService:(PURDefaultsService *)defaultsService;

- (void)performBlockAndWait:(void (^)(NSManagedObjectContext *context))perform;

- (void)performBlock:(id _Nullable (^)(NSManagedObjectContext *context, NSError * __autoreleasing *errorp))perform
     completionQueue:(PURQueue * _Nullable)queue
          completion:(void (^ _Nullable)(id _Nullable performResult, NSError * _Nullable performError))completion;

- (void)saveChangesForce:(BOOL)force;

- (void)saveChangesIfNeededOnQueue:(PURQueue * _Nullable)queue
                             force:(BOOL)force
                        completion:(nullable PURErrorCompletion)completion;

- (PUROperation *)saveChangesOperationForce:(BOOL)force queue:(PURQueue *)queue;

- (void)insertObjectWithClass:(Class)managedObjectClass
                        queue:(PURQueue * _Nullable)queue
                       modify:(nullable PURModifyBlock)modifyBlock
                   completion:(nullable PURModifyBlock)completion;

- (void)insertObjectsWithClass:(Class)managedObjectClass
                         count:(NSUInteger)count
                         queue:(PURQueue *)queue
                        modify:(nullable PURModifyBlock)modifyBlock
                    completion:(nullable void (^)(NSArray *result))completion;

- (void)executeCountRequest:(NSFetchRequest *)query
            completionQueue:(PURQueue * _Nullable)queue
                 completion:(PURCountCompletion)completion
                    failure:(PURErrorCompletion)errorBlock;

- (void)executeFetchRequest:(NSFetchRequest *)query
            completionQueue:(PURQueue * _Nullable)queue
                 completion:(PURArrayResultCompletion)completion
                    failure:(PURErrorCompletion)errorBlock;

- (void)deleteObjectsMatching:(NSFetchRequest *)query
              matchingObjects:(void (^ _Nullable)(NSArray<__kindof NSManagedObject *> *))matchingObjects
              completionQueue:(PURQueue * _Nullable)queue
                   completion:(PURCompletion)completion
                      failure:(PURErrorCompletion)error;

- (void)deleteEverythingCompletionQueue:(PURQueue * _Nullable)queue
                             completion:(PURCompletion)completion;

@end

NS_ASSUME_NONNULL_END
