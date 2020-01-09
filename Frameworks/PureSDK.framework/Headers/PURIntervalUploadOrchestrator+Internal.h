//
//  PURIntervalUploadOrchestrator+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 8/22/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURIntervalUploadOrchestrator.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURIntervalUploadOrchestrator (Internal)

@property (nonatomic) PUREventIntervalProducer *intervalProducer;
@property (nonatomic) PUREventIntervalSerializer *intervalSerializer;
@property (nonatomic) PURBackgroundIntervalUploader *intervalUploader;
@property (nonatomic) PURIntervalFuser *intervalFuser;
@property (nonatomic) PURIntervalMaintenance *intervalMaintenance;
@property (nonatomic) PURForegroundIntervalUploader *foregroundUploader;
@property (nonatomic) PURIntervalDiskMaintenance *diskMaintenance;

@property (nonatomic) PURQueue *queue;
@property (nonatomic) PURQueue *concurrent;

@end

NS_ASSUME_NONNULL_END
