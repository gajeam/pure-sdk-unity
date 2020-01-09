//
//  PURBundles.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/20/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// This class must be in the same bundle as our assets!
@interface PURBundles : NSObject

// Contains (among other things) this class.
@property (nonatomic, class, readonly) NSBundle *frameworkBundle;

// Contains prerecorded routes and activity logs used for testing and configuration and datamodel assets.
@property (nonatomic, class, readonly) NSBundle *dataBundle;

@end

NS_ASSUME_NONNULL_END
