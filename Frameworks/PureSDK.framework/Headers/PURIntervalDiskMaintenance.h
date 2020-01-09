//
//  PURIntervalDiskMaintenance.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/7/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURIntervalProtocol.h>

@import CoreData;

@class PURServiceLocator, PURQueue;

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString *, PURIntervalObject *> * IntervalsByReference;

@interface PURIntervalDiskMaintenance : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                 frameworkQueue:(PURQueue *)queue
                concurrentQueue:(PURQueue *)concurrent
                  intervalClass:(Class)intervalClass
         queueDataDirectoryName:(NSString *)queuedDirectory
   queueDataBackupDirectoryName:(NSString *)queuedBackupDirectory
                      logPrefix:(NSString *)logPrefix;

- (void)ensureConsistencyBetweenFilesAndReferences:(dispatch_group_t)dispatchGroup;

@end

NS_ASSUME_NONNULL_END
