//
//  PUREventLinker+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 1/13/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import CoreMotion;

#import <PureSDK/PUREventLinker.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUREventLinker (Internal)

@property (nonatomic) PUREventSerializer *eventSerializer;
@property (nonatomic) PURMutableEventLinkerState *mutableEventState;

@end

NS_ASSUME_NONNULL_END
