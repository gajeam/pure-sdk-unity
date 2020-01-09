//
//  PURTimeConverting.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSTimeInterval pur_seconds(double magnitude);
extern NSTimeInterval pur_minutes(double magnitude);
extern NSTimeInterval pur_hours(double magnitude);
extern NSTimeInterval pur_days(const double magnitude);

NS_ASSUME_NONNULL_END
