//
//  PURTaskRunner.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/28/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURTaskRunner : NSObject

- (instancetype)initWithQueue:(PURQueue *)queue;

- (void)addTask:(void (^)(void))task;

- (void)runAllTasks;

@property (nonatomic) BOOL executeImmediately;

@end

NS_ASSUME_NONNULL_END
