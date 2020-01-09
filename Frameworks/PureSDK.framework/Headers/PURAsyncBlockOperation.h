//
//  PURAsyncBlockOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/11/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PUROperation.h>

@class PURAsyncBlockOperation;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURAsyncBlockSuccess)(id _Nullable result);
typedef void(^PURAsyncBlockError)(NSError * _Nullable error);

typedef void(^PURAsyncPerformBlock)(PURAsyncBlockOperation *operation,
                                    PURAsyncBlockSuccess success,
                                    PURAsyncBlockError failure);

@interface PURAsyncBlockOperation : PUROperation

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)name:(NSString *)name
               queue:(PURQueue *)queue
             perform:(PURAsyncPerformBlock)operation
               error:(nullable PURAsyncBlockError)failure;

+ (instancetype)name:(NSString *)name
               queue:(PURQueue *)queue
          completion:(PURAsyncBlockError)completionBlock;

@end

NS_ASSUME_NONNULL_END
