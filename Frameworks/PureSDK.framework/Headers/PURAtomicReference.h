//
//  PURAtomicReference.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/30/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAtomicReference<ObjectType> : NSObject

@property (nonatomic, readonly) ObjectType value;

- (ObjectType)take;
- (BOOL)storeIfNil:(ObjectType)value;
- (ObjectType)exchange:(ObjectType)value;

- (instancetype)initWithObject:(nullable ObjectType)object;

@end

NS_ASSUME_NONNULL_END
