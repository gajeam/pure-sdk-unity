//
//  PUREventStore+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/24/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PUREventStore.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUREventStore (Internal)

@property (nonatomic) PURBaseDataStore *dataStore;

- (void)deleteOldEventIntervalsAndEvents:(nullable void (^)(void))completion
                                failure:(nullable void (^)(NSError *))failure;

- (void)deleteEverythingCompletionQueue:(PURQueue * _Nullable)queue
                             completion:(PURCompletion  _Nullable)completion;

// Doesn't tell observers about the insert.
- (void)sneakilyInsertObjectWithClass:(Class)objectClass
                                queue:(PURQueue * _Nullable)queue
                               modify:(void (^ _Nullable)(__kindof NSManagedObject *))modifyBlock
                           completion:(void (^ _Nullable)(__kindof NSManagedObject *))completion;

@end

NS_ASSUME_NONNULL_END
