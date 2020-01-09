//
//  PUROngoingBackgroundCloudConfigFetches.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/11/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURSortedArray.h>

@class PURQueue, PURServiceLocator;

NS_ASSUME_NONNULL_BEGIN

@interface PUROngoingBackgroundCloudConfigFetches : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                          queue:(PURQueue *)queue API_AVAILABLE(ios(11.0));

@property (nonatomic, readonly) PURSortedArray<NSURLSessionTask *> *sortedCurrentFetches;
@property (nonatomic, readonly) PURSortedArray<NSURLSessionTask *> *sortedLongFetches;

@end

NS_ASSUME_NONNULL_END
