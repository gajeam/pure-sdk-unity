//
//  PUROperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/11/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

//
// Fully chainable operation supporting :
// 1. Inputs - Pass results of dependent operations downstream.
// 2. Errors - If any dependent operations fail, downstream operations also fail.
// 3. Results - Easy access to the result of an operation.
//
// All properties are thread-safe.
//
@interface PUROperation : NSOperation

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name queue:(PURQueue *)queue;

@property (nonatomic, readonly) PURQueue *internalQueue;

@property (readonly, nonatomic, getter=isExecuting) BOOL executing;
@property (readonly, nonatomic, getter=isFinished) BOOL finished;

@property (nonatomic, nullable) id input;

@property (nonatomic, nullable, readonly) NSError *error;
@property (nonatomic, nullable, readonly) id result;

- (void)performOperation:(void (^)(id _Nullable result))success
                   error:(void (^)(NSError *))failure;

// Called when the operation finishes.
- (void)pur_terminate;

@end

NS_ASSUME_NONNULL_END
