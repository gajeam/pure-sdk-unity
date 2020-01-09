//
//  PURSortedArray.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/1/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURSortedArray<__covariant ObjectType> : NSObject

- (instancetype)initWithArray:(NSArray * _Nullable)array
                        queue:(PURQueue *)queue
                   comparator:(NSComparisonResult (^)(ObjectType, ObjectType))comparator;

- (void)insertObject:(ObjectType)object;

- (void)removeObjectsMatching:(BOOL (^)(ObjectType))filter;

- (void)removeObjectsInArray:(NSArray<ObjectType> *)otherArray;

- (NSArray<ObjectType> *)immutableView;

- (void)observe:(void (^)(NSArray *internalArray))observer;

@end

NS_ASSUME_NONNULL_END
