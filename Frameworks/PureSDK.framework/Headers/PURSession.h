//
//  PURSession.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURServiceLocator;

NS_ASSUME_NONNULL_BEGIN

@interface PURSession : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithServiceLocator:(PURServiceLocator *)services;

@property (nonatomic, readonly) PURServiceLocator *services;

@end

NS_ASSUME_NONNULL_END
