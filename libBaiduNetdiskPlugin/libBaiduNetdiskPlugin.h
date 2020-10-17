//
//  libBaiduNetdiskPlugin.h
//  libBaiduNetdiskPlugin
//
//  Copyright © 2018 CodeTips. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//! Project version number for libBaiduNetdiskPlugin.
FOUNDATION_EXPORT double libBaiduNetdiskPluginVersionNumber;

//! Project version string for libBaiduNetdiskPlugin.
FOUNDATION_EXPORT const unsigned char libBaiduNetdiskPluginVersionString[];

@interface BandwidthManager : NSObject
@property(nonatomic) unsigned long long maxBytesPerSecond; // @synthesize maxBytesPerSecond=_maxBytesPerSecond;
- (void)request:(long long)arg1 increaseBytesTransferred:(unsigned long long)arg2;
@end

@interface BDUserPersonalInfo : NSObject
@property(nonatomic) double svipExpireTime; // @synthesize
@end

@interface BDUser : NSObject
- (BOOL)isSVip;
@end

@interface FileTransSpeedUpTrialManager : NSObject
@property(nonatomic) long long probationaryDuration;
+ (id)sharedInstance;

- (id)trialToken;
- (void)resetTrialStatus;
- (void)checkProbationary;
- (void)startTrial;
@end

@interface ALModel : NSObject
@end

@interface SpeedUpTrialModel : ALModel
@property(copy, nonatomic) NSString *token; // @synthesize token=_token;
@end

@interface AppVersionManager : NSObject
- (unsigned long long)checkUpdate;
@end
