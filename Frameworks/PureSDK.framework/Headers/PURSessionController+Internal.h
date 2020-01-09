//
//  PURSessionController+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 6/19/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURSessionController.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURSessionController (Internal)

@property (nonatomic) PURSession *session;

- (void)runTasksDelayedUntilAfterInitialization;
- (void)runTasksDelayedUntilAfterTakeOff;

@end

NS_ASSUME_NONNULL_END
