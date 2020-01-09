//
//  PURClock.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/21/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURClock : NSObject

@property (class, nonatomic, readonly) NSTimeInterval now;
@property (class, nonatomic, readonly) NSDate *date;

+ (void)setSpoofedTimeTo:(NSTimeInterval)date;
+ (void)stopSpoofingTime;

@end

NS_ASSUME_NONNULL_END
