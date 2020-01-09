//
//  PURServiceLocator+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 6/19/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURServiceLocator.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURServiceLocator (Internal)

@property (nonatomic, readonly) NSDictionary<NSString *, PURService *> *services;

- (PURService *)removeService:(Class)klass;
- (void)registerService:(PURService *)service;

- (void)pur_initializeServices:(NSArray<PURService *> *)services
             withLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)options
                    completion:(void (^ _Nullable)(void))completion;

- (void)pur_runInitialize:(NSArray<PURService *> *)services
         initializerQueue:(PURQueue *)initializerQueue
         initializerGroup:(dispatch_group_t)initializerTrackingGroup
            launchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)options;

- (void)pur_runTakeOff:(NSArray<PURService *> *)services
      initializerQueue:(PURQueue *)initializerQueue
      initializerGroup:(dispatch_group_t)initializerTrackingGroup;

@end

NS_ASSUME_NONNULL_END
