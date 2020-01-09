//
//  NSDateFormatter+PUR8601ISO.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/16/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDateFormatter (PUR8601ISO)

+ (NSDateFormatter *)pur_ISO8601Formatter;

+ (NSDateFormatter *)pur_ISO8601UTCFormatter;

+ (NSDateFormatter *)pur_readableLocalDateFormatter;

+ (NSDateFormatter *)pur_dateOnlyLocalFormatter;

+ (NSDateFormatter *)pur_readableUTCDateFormatter;

+ (NSDateFormatter *)pur_dateOnlyReadableLocalFormatter;

@end

NS_ASSUME_NONNULL_END
