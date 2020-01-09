//
//  PURDefaultsTokenBag.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/6/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURDefaultsKey, PURDefaultsService, PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURDefaultsTokenBag : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDefaultsService:(PURDefaultsService *)defaultsService
                                  queue:(PURQueue *)queue;

- (void)addToken:(NSString *)token forDefaultKey:(PURDefaultsKey *)defaultsKey;

@end

NS_ASSUME_NONNULL_END
