//
//  PURMovementClassifierProxy.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/7/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURMovementClassifier.h>

NS_ASSUME_NONNULL_BEGIN

// This class accepts any message from the `PURMovementClassifier`
// protocol and forwards it to an appropriate movement classifier.
// Responsible for selecting the correct classifier depending on
// the permissions we have. MotionActivity classifier if we have
// motion permissions, and LocationOnly classifier if not.

@interface PURMovementClassifierProxy : NSObject <PURMovementClassifier>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<PURMovementClassifierDelegate>)delegate
                           queue:(PURQueue *)queue
                         locator:(PURServiceLocator *)locator;

@end

NS_ASSUME_NONNULL_END
