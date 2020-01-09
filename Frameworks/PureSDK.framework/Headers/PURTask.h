//
//  PURTask.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/28/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURTask : NSObject

+ (instancetype)on:(PURQueue *)queue task:(void (^)(void))task;

- (void)run;

@end

@interface PURTokenTask : NSObject

+ (instancetype)on:(PURQueue *)queue block:(void (^)(id _Nullable value, NSString *token))block;

- (void)runWithToken:(NSString *)token value:(id)value;

@end

NS_ASSUME_NONNULL_END
