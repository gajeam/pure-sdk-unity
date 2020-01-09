//
//  PURCounter.h
//  UnacastPureSDK
//
//  Created by Hakon Hanesand on 1/2/20.
//  Copyright © 2020 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURCounter : NSObject

- (instancetype)initWithValue:(int64_t)value queue:(PURQueue *)queue;

- (void)waitForCounter:(void (^)(void))completion;

@property (nonatomic) int64_t value;

- (void)increment;
- (void)decrement;

@end

NS_ASSUME_NONNULL_END
