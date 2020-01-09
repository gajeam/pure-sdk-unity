//
//  PURServiceLocator.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PURService;

NS_ASSUME_NONNULL_BEGIN

@interface PURServiceLocator : NSObject

@property (nonatomic, readonly) NSString *name;

- (instancetype)initWithName:(NSString *)name;

- (void)registerServices:(NSArray<PURService *> *)newServices;

- (nullable __kindof PURService *)serviceForClass:(Class)class;
- (nullable __kindof PURService *)serviceForClassIfExists:(Class)class;

- (void)initializeServicesWithLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)options
                                 completion:(void (^ _Nullable)(void))completion;

- (void)initializeServicesWithLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)options
                     initializationComplete:(void (^ _Nullable)(void))initializationComplete
                            takeOffComplete:(void (^ _Nullable)(void))takeOffComplete;

- (void)appDidResume;

- (void)applicationWillTerminate;

@end

NS_ASSUME_NONNULL_END
