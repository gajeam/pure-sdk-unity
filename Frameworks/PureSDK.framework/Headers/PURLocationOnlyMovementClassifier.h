//
//  PURLocationOnlyMovementClassifier.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/7/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURMovementClassifier.h>

NS_ASSUME_NONNULL_BEGIN

@class PURServiceLocator, PURQueue;

// This classifier is used when only location data is available.
@interface PURLocationOnlyMovementClassifier : NSObject <PURMovementClassifier>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<PURMovementClassifierDelegate>)delegate
                         locator:(PURServiceLocator *)locator
                           queue:(PURQueue *)queue NS_DESIGNATED_INITIALIZER;

// Copy existing settings from another classifier.
- (instancetype)initWithClassifier:(id<PURMovementClassifier>)classifier;

@end

NS_ASSUME_NONNULL_END
