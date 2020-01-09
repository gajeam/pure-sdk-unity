//
//  PURMulticastDispatcher.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/28/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURMulticastDispatcher<ObjectType> : NSObject

- (instancetype)initWithQueue:(PURQueue *)queue;

- (NSString *)registerOn:(PURQueue *)queue perform:(void (^)(ObjectType _Nullable value, NSString *token))block;

- (void)notifyWith:(ObjectType)value;

- (void)deregisterObserverWithToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
