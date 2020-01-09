//
//  PURService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PURServiceLocator;
@class PURDefaultsTokenBag;
@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURService : NSObject

- (instancetype)init NS_UNAVAILABLE;

// LIFECYCLE (called on queue)
// 1. initWithLocator (main thread)
// 2. initializeWithLaunchOptions (concurrent sdk)
// 3. takeOff (concurrent sdk)

// All services are created on the main thread. We use this init method to create
// essential objects on the such as CLLocationManager and CBCentralManager.
- (instancetype)initWithLocator:(PURServiceLocator *)locator;

// All other services have been created when called.
// Perform all work required to set up this service for use here.
- (void)initializeWithLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)options NS_REQUIRES_SUPER;

// All other services have received `-(void) initialize...`
// Perform initialization work that depends on other services here.
// Relies on caller to enter group before call starts, and to exit when complete.
- (void)takeOffWithCompletionGroup:(dispatch_group_t)takeOffGroup NS_REQUIRES_SUPER;

// Called when the app regains focus from any state (background, terminated, unfocused).
- (void)appDidResume NS_REQUIRES_SUPER;

- (void)applicationWillTerminateWithGroup:(dispatch_group_t)terminationGroup NS_REQUIRES_SUPER;

- (void)delayActionUntilServiceCompletesTakeOff:(void (^)(void))action;

// Default implementation returns the name of the subclass.
@property (nonatomic, class, readonly) NSString *serviceIdentifier;

@property (nonatomic, weak) PURServiceLocator *locator;

// Easy storage for tokens returned by PURDefaultsService notification API.
// All the tokens registered here will be deregistered upon dealloc.
@property (nonatomic, readonly) PURDefaultsTokenBag *tokenBag;

// Serial queue.
@property (nonatomic, readonly) PURQueue *serviceQueue;

// Used during testing.
+ (NSArray<Class> *)dependencies;

@end

NS_ASSUME_NONNULL_END
