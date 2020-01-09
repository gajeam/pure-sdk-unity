//
//  PURSessionController.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PURSession, PURQueue, PURTask;

NS_ASSUME_NONNULL_BEGIN

@interface PURSessionController : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly) PURSession *session;

@property (nonatomic, class, readonly) PURSessionController *shared;

- (void)configureSessionWithLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)options;

- (void)delayExecutionUntilSessionFinishesTakeOff:(void (^)(void))delayExecution
                                            queue:(PURQueue *)queue;

- (void)delayExecutionUntilSessionFinishesInitialization:(void (^)(void))delayExecution
                                                   queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
