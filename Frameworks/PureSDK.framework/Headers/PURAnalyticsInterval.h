//
//  PURAnalyticsInterval.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/17/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>

#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURIntervalProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAnalyticsInterval : NSManagedObject <PURExportableEvent, PURIntervalProtocol>

@end

NS_ASSUME_NONNULL_END
