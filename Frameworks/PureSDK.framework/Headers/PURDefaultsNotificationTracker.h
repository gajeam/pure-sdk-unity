//
//  PURDefaultsNotificationTracker.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/5/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDefaultsKey.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURDefaultChangeNotificationBlockWithToken)(NSString *token, id value);

@interface PURDefaultsNotificationTracker : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDefaultsKey:(PURDefaultsKey *)defaultsKey
                         parentLock:(NSLock *)lock;

// Must be holding parentLock when you call this method.
- (nullable NSString *)locked_addListener:(PURDefaultChangeNotificationBlockWithToken)block
                                           onQueue:(PURQueue *)queue;

- (void)removeListenerForToken:(NSString *)token;

- (void)unlocked_defaultValueDidChangeTo:(id)value;

@end

NS_ASSUME_NONNULL_END
