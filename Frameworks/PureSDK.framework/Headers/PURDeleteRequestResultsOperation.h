//
//  PURQueryResultDeletionOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/11/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>

@class PUREventStore;

#import <PureSDK/PUROperation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURDeleteRequestResultsOperation : PUROperation

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithEventStore:(PUREventStore *)eventStore
                              deleteRequest:(NSFetchRequest *)deleteRequest
                                      queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
