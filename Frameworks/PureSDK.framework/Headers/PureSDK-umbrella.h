//
//  PureSDK-umbrella.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/14/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import Foundation;

//! Project version number for PureSDK.
FOUNDATION_EXPORT double PureSDKVersionNumber;

//! Project version string for PureSDK.
FOUNDATION_EXPORT const unsigned char PureSDKVersionString[];

#import <PureSDK/FastCoder.h>
#import <PureSDK/PURAPIClient.h>
#import <PureSDK/PURAPIRequestTemplate.h>
#import <PureSDK/PURAppleLocationTracker.h>
#import <PureSDK/PURAssertMacros.h>
#import <PureSDK/PURAsyncBlockOperation.h>
#import <PureSDK/PURBackgroundAPIClient.h>
#import <PureSDK/PURBaseDataStore.h>
#import <PureSDK/PURBlockDefinitions.h>
#import <PureSDK/PURBundles.h>
#import <PureSDK/PURClock.h>
#import <PureSDK/PURCloudConfigService.h>
#import <PureSDK/PURCocoaLumberjack.h>
#import <PureSDK/PURCommittableFlagWrapper.h>
#import <PureSDK/PURDeviceInformation.h>
#import <PureSDK/PURConnectionMonitoringService.h>
#import <PureSDK/PURConnectionDefines.h>
#import <PureSDK/PURCurrentConnectionProvider.h>
#import <PureSDK/PURDefaultsKey.h>
#import <PureSDK/PURDefaultsNotificationTracker.h>
#import <PureSDK/PURDefaultsService.h>
#import <PureSDK/PURDefaultsTokenBag.h>
#import <PureSDK/PURDeleteRequestResultsOperation.h>
#import <PureSDK/PURDeviceInformationService.h>
#import <PureSDK/Pure.h>
#import <PureSDK/NSPredicate+PURPredicates.h>
#import <PureSDK/Pure+Private.h>
#import <PureSDK/PUREventIntervalProducer.h>
#import <PureSDK/PURBackgroundIntervalUploader.h>
#import <PureSDK/PUREventLinker.h>
#import <PureSDK/PUREventLinker+Private.h>
#import <PureSDK/PUREventLinkerState.h>
#import <PureSDK/PUREventSerializer.h>
#import <PureSDK/PUREventSerializer+Private.h>
#import <PureSDK/PUREventStore.h>
#import <PureSDK/PUREventStoreQuery.h>
#import <PureSDK/PUREventThrottler.h>
#import <PureSDK/PUREventUploadingService.h>
#import <PureSDK/PURFunctions.h>
#import <PureSDK/PURGeohash.h>
#import <PureSDK/PURGeohashLocationFilter.h>
#import <PureSDK/PURGZIPRequestSerializer.h>
#import <PureSDK/PUREventDescription.h>
#import <PureSDK/PURInterruptibleTimer.h>
#import <PureSDK/PURLiveEventService.h>
#import <PureSDK/PURLocalServerLogFileFormatter.h>
#import <PureSDK/PURLocationCache.h>
#import <PureSDK/PURLocationOnlyMovementClassifier.h>
#import <PureSDK/PURLocationTracker.h>
#import <PureSDK/PURLocationTrackingService.h>
#import <PureSDK/PURLiveEventService+Private.h>
#import <PureSDK/PURLocationTrackingStateObserver.h>
#import <PureSDK/PURLog.h>
#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURLogEvent.h>
#import <PureSDK/PURLoggingService.h>
#import <PureSDK/PURLogMacros.h>
#import <PureSDK/PURMacros.h>
#import <PureSDK/PURDatedConnectionInformation.h>
#import <PureSDK/PURSessionConfigurator.h>
#import <PureSDK/PURCurrentConnectionProvider.h>
#import <PureSDK/PURConnectionEventDeduplicator.h>
#import <PureSDK/PURMessageEvent.h>
#import <PureSDK/PURWeakifyMacros.h>
#import <PureSDK/PURIntervalUploadOrchestrator.h>
#import <PureSDK/PURForegroundIntervalUploader.h>
#import <PureSDK/PURAnalyticsInterval.h>
#import <PureSDK/PURAsyncBlockOperation+PURFileManagement.h>
#import <PureSDK/PURBackgroundCloudConfigFetcher.h>
#import <PureSDK/PURBackgroundCloudConfigScheduler.h>
#import <PureSDK/PURDefaultProperty.h>
#import <PureSDK/PUREventIntervalSerializer.h>
#import <PureSDK/PURIntervalMaintenance.h>
#import <PureSDK/PURIntervalDiskMaintenance.h>
#import <PureSDK/PURIntervalFuser.h>
#import <PureSDK/PURFuseIntervalsOperation.h>
#import <PureSDK/PURUnGZIPDataOperation.h>
#import <PureSDK/PURGZIPDataOperation.h>
#import <PureSDK/PURLogMessage+PURExport.h>
#import <PureSDK/PUROngoingBackgroundCloudConfigFetches.h>
#import <PureSDK/PURServerErrorLogger.h>
#import <PureSDK/PURMovementClassifier.h>
#import <PureSDK/PURMovementClassifierProxy.h>
#import <PureSDK/PURMulticastDispatcher.h>
#import <PureSDK/PURObserver.h>
#import <PureSDK/PUROperation.h>
#import <PureSDK/PURPathProvider.h>
#import <PureSDK/PURPeriodicScanHelper.h>
#import <PureSDK/PURPlistConfiguration.h>
#import <PureSDK/PURQueue.h>
#import <PureSDK/PURRuntimeConfigurationService.h>
#import <PureSDK/PURSerializeRequestOperation.h>
#import <PureSDK/PURService.h>
#import <PureSDK/PURServiceLocator.h>
#import <PureSDK/PURSession.h>
#import <PureSDK/PURSessionController.h>
#import <PureSDK/PURSortedArray.h>
#import <PureSDK/PURSwitch.h>
#import <PureSDK/PURSystemStateService.h>
#import <PureSDK/PURTimeConverting.h>
#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURTrie.h>
#import <PureSDK/PURTTYLogger.h>
#import <PureSDK/PURURLRequestSerialization.h>
#import <PureSDK/PURURLResponseSerialization.h>
#import <PureSDK/PURURLSessionManager.h>
#import <PureSDK/PURPureIdentifierService.h>
#import <PureSDK/PURAtomicReference.h>
#import <PureSDK/PURTask.h>
#import <PureSDK/PURTaskRunner.h>
#import <PureSDK/PURLiveEventCandidatePicker.h>
#import <PureSDK/PURServiceNameLogFormatter.h>
#import <PureSDK/PURCounter.h>

#import <PureSDK/CLLocation+PURExtrapolatedMotionState.h>
#import <PureSDK/CLVisit+PURLogString.h>
#import <PureSDK/NSData+PURGZIP.h>
#import <PureSDK/NSData+PURHexString.h>
#import <PureSDK/NSDateFormatter+PUR8601ISO.h>
#import <PureSDK/NSError+PURCoreDataError.h>
#import <PureSDK/NSDictionary+PURExtension.h>
#import <PureSDK/NSManagedObject+PURAdditions.h>
#import <PureSDK/NSProcessInfo+PURProcessInfo.h>
#import <PureSDK/NSString+PURMD5.h>
#import <PureSDK/PURAPIClient+PURConfig.h>
#import <PureSDK/PURAPIClient+PUREventPost.h>
#import <PureSDK/PURAPIClient+PURUserData.h>
#import <PureSDK/NSArray+PURMultilineDescription.h>
#import <PureSDK/PURCloudConfigService+PURDefaults.h>
#import <PureSDK/PURLog+LOGV.h>
#import <PureSDK/PURServiceLocator+Services.h>
#import <PureSDK/UIDevice+PURShortcuts.h>
#import <PureSDK/UIApplication+PURApplication.h>
#import <PureSDK/NSValue+PURCoord.h>
#import <PureSDK/NSOperation+PURConvenience.h>
#import <PureSDK/CLBeaconRegion+PURIdentifier.h>

// Not to be used in the SDK! Only for use in demo app.

#import <PureSDK/PUREventUploadingService+Internal.h>
#import <PureSDK/PURBaseDataStore+Internal.h>
#import <PureSDK/PURCloudConfigService+Internal.h>
#import <PureSDK/PURConnectionMonitoringService+Internal.h>
#import <PureSDK/Pure+Internal.h>
#import <PureSDK/PUREventLinker+Internal.h>
#import <PureSDK/PUREventStore+Internal.h>
#import <PureSDK/PURGeohashLocationFilter+Internal.h>
#import <PureSDK/PURInterruptibleTimer+Internal.h>
#import <PureSDK/PURLocationCache+Internal.h>
#import <PureSDK/PURLocationOnlyMovementClassifier+Internal.h>
#import <PureSDK/PURLocationTrackingService+Internal.h>
#import <PureSDK/PURLoggingService+Internal.h>
#import <PureSDK/PURMovementClassifierProxy+Internal.h>
#import <PureSDK/PURPeriodicScanHelper+Internal.h>
#import <PureSDK/PURPlistConfiguration+Internal.h>
#import <PureSDK/PURRuntimeConfigurationService+Internal.h>
#import <PureSDK/PURServiceLocator+Internal.h>
#import <PureSDK/PURSessionController+Internal.h>
#import <PureSDK/PURSystemStateService+Internal.h>
#import <PureSDK/PURIntervalUploadOrchestrator+Internal.h>
#import <PureSDK/PURDefaultsService+Internal.h>
