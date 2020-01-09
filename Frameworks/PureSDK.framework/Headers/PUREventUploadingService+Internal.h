//
//  PUREventUploadingService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 12/11/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PUREventUploadingService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUREventUploadingService (Internal)

@property (nonatomic, class) NSString *uploadingBlobDirectory;
@property (nonatomic, class) NSString *blobBackupDirectory;

@property (nonatomic, readonly) PURIntervalUploadOrchestrator *orchestrator;

+ (PURDefaultsKey *)lastBatchDefaultKey;

@end

NS_ASSUME_NONNULL_END
