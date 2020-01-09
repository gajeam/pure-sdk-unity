//
//  PUREventStoreQuery.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUREventStoreQuery : NSObject

#pragma mark - Default Fetches

+ (nullable NSFetchRequest *)fetchRequestOn:(Class)klass
                                 filteredBy:(nullable NSPredicate *)predicate
                                  orderedBy:(nullable NSArray<NSSortDescriptor *> *)sorts
                                      limit:(NSUInteger)limit;

+ (nullable NSFetchRequest *)fetchRequestOn:(Class)klass
                                 filteredBy:(nullable NSPredicate *)predicate
                                  orderedBy:(nullable NSArray<NSSortDescriptor *> *)sorts;

+ (nullable NSFetchRequest *)fetchRequestOn:(Class)klass
                                 filteredBy:(nullable NSPredicate *)predicate;

+ (NSFetchRequest * _Nullable)waypointsInDay:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
