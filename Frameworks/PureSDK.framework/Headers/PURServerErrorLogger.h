//
//  PURServerErrorLogger.h
//  PureSDK
//
//  Created by Hakon Hanesand on 8/29/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURCocoaLumberjack.h>

@class PURServiceLocator, PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURServerErrorLogger : PURAbstractLogger

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithLocator:(PURServiceLocator *)locator queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
