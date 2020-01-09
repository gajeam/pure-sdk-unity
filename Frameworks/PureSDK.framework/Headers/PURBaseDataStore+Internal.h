//
//  PURBaseDataStore+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 6/7/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PureSDK-umbrella.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURBaseDataStore (Internal)

@property (nonatomic, readonly) NSManagedObjectContext *primaryContext;
@property (nonatomic, readonly) NSManagedObjectContext *publicContext;

@end

NS_ASSUME_NONNULL_END
