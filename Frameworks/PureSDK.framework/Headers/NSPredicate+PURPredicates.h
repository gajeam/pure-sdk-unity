//
//  NSPredicate+PURPredicates.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/19/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSPredicate (PURPredicates)

+ (instancetype)filterExcludingKey:(NSString *)key olderThanDays:(NSUInteger)days;

@end

NS_ASSUME_NONNULL_END
