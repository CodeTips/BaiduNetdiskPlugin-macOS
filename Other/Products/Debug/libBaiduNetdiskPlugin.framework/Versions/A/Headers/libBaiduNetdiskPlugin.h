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

typedef void(^CDUnknownBlockType)(void);
typedef void(^CDUnknownBlockType1)(id arg1);
typedef void(^CDUnknownBlockType2)(id arg1, id arg2);
typedef void(^CDUnknownBlockType3)(id arg1, id arg2, id arg3);

@interface ALModel : NSObject
@end
@interface FileMetaModel : ALModel
@end
@interface FileTransmissionModel : FileMetaModel
@end
@interface FileDownloadModel : FileTransmissionModel
{
    BOOL _transcodingFile;
    NSString *_dlinkContext;
    NSString *_tempFile;
}

+ (id)uniqueKeys;
+ (id)modelCustomPropertyMapper;
+ (id)recordPropertyWhitelist;
+ (id)databaseIdentifier;
+ (id)tableName;
@property(copy) NSString *tempFile; // @synthesize tempFile=_tempFile;
@property BOOL transcodingFile; // @synthesize transcodingFile=_transcodingFile;
@property(retain) NSString *dlinkContext; // @synthesize dlinkContext=_dlinkContext;
- (BOOL)isDLinkModel;
- (id)displayedFileName;

@end

@interface HHTimer : NSObject
{
    NSObject<OS_dispatch_source> *_source;
    CDUnknownBlockType _block;
    id _internalUserInfo;
}

+ (id)scheduledTimerWithTimeInterval:(double)arg1 dispatchQueue:(id)arg2 block:(CDUnknownBlockType)arg3 userInfo:(id)arg4 repeats:(BOOL)arg5;
@property(retain, nonatomic) id internalUserInfo; // @synthesize internalUserInfo=_internalUserInfo;
@property(copy, nonatomic) CDUnknownBlockType block; // @synthesize block=_block;
- (id)userInfo;
- (BOOL)isValid;
- (void)invalidate;
- (void)fire;


@end


@interface BandwidthManager : NSObject
{
    unsigned long long _appropriateMaxBytesPerSecond;
    unsigned long long _totalBytesTransferredInLastSecond;
    unsigned long long _maxExceedBytes;
    NSMutableDictionary *_requestDict;
    NSObject<OS_dispatch_semaphore> *_throttleLock;
    HHTimer *_measurementTimer;
    unsigned long long _maxBytesPerSecond;
}

+ (id)manager;
@property(nonatomic) unsigned long long maxBytesPerSecond; // @synthesize maxBytesPerSecond=_maxBytesPerSecond;
- (void)request:(long long)arg1 increaseBytesTransferred:(unsigned long long)arg2;
- (unsigned long long)totalBytesTransferredInLastSecond;
- (long long)managedRequestCount;
- (void)updateBandwidthThrottlingForRequests;
- (void)adjustBandwidthUsage;
- (void)performThrottling;
- (void)notifyThrottling;
- (void)removeRequestWithId:(long long)arg1;
- (void)manageRequest:(id)arg1 withId:(long long)arg2;
- (id)init;

@end




@interface FileTransSpeedUpTrialManager : NSObject
{
    long long _probationaryStatus;
    long long _probationaryDuration;
    long long _probationaryTag;
    NSMutableArray *_beforeProbationSpeedArray;
    NSMutableArray *_probationSpeedArray;
    double _probationaryIncrease;
    double _preTime;
    double _timestamp;
    NSObject<OS_dispatch_queue> *_speedCalculateQueue;
}
+ (id)sharedInstance;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *speedCalculateQueue; // @synthesize speedCalculateQueue=_speedCalculateQueue;
@property(nonatomic) double timestamp; // @synthesize timestamp=_timestamp;
@property(nonatomic) double preTime; // @synthesize preTime=_preTime;
@property(nonatomic) double probationaryIncrease; // @synthesize probationaryIncrease=_probationaryIncrease;
@property(retain, nonatomic) NSMutableArray *probationSpeedArray; // @synthesize probationSpeedArray=_probationSpeedArray;
@property(retain, nonatomic) NSMutableArray *beforeProbationSpeedArray; // @synthesize beforeProbationSpeedArray=_beforeProbationSpeedArray;
@property long long probationaryTag; // @synthesize probationaryTag=_probationaryTag;
@property(nonatomic) long long probationaryDuration; // @synthesize probationaryDuration=_probationaryDuration;
@property long long probationaryStatus; // @synthesize probationaryStatus=_probationaryStatus;
- (id)getProbationSubmitTitle;
- (id)getProbationTitleWithIncrease:(double)arg1;
- (id)getProbationJumpUrl:(long long)arg1;
- (long long)probationDuration;
- (void)checkProbationary;
- (void)setupTimer;
- (void)stopTimer;
- (void)handleProbationaryTimer;
- (void)calculateProbationIncrease;
- (long long)calculateAverageSpeed:(id)arg1;
- (id)trialToken;
- (long long)trialTimeStamp;
- (void)downloadTaskNone;
- (void)notifyProbationChange;
- (void)resetTrialStatus;
- (void)cancelTrialImmediately:(BOOL)arg1;
- (void)stopProbationTask;
- (void)startTrial;
- (void)handleVipInfoChanged:(id)arg1;
- (void)handleLogout:(id)arg1;
- (void)handleProgressChanged:(id)arg1;
- (void)bandwidthSpeed:(long long)arg1;
- (void)addNotification;

@end

@interface BDUserPersonalInfo : NSObject
{
    long long _userRank;
    unsigned long long _totalSpace;
    unsigned long long _currentSpace;
    double _vipExpireTime;
    double _svipExpireTime;
    double _expVipExpireTime;
}

@property(nonatomic) double expVipExpireTime; // @synthesize expVipExpireTime=_expVipExpireTime;
@property(nonatomic) double svipExpireTime; // @synthesize svipExpireTime=_svipExpireTime;
@property(nonatomic) double vipExpireTime; // @synthesize vipExpireTime=_vipExpireTime;
@property(nonatomic) unsigned long long currentSpace; // @synthesize currentSpace=_currentSpace;
@property(nonatomic) unsigned long long totalSpace; // @synthesize totalSpace=_totalSpace;
@property(nonatomic) long long userRank; // @synthesize userRank=_userRank;
- (id)initWithCoder:(id)arg1;
- (id)dataByDESDecryptData:(id)arg1 key:(id)arg2;
- (id)decodeWithKey:(id)arg1 coder:(id)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)getPersonInfoKey;

@end

@interface BDUser : NSObject
{
    NSString *_cachePath;
    NSString *_secUid;
    NSString *_userSignKey;
    NSString *_userName;
    NSString *_displayName;
    NSString *_bduss;
    NSString *_userId;
    NSString *_ptoken;
    NSString *_stoken;
    long long _oauthType;
    NSString *_oauthAvatarUrl;
    NSString *_panAvatarUrl;
    NSString *_panNickName;
    NSString *_userUK;
}

@property(copy, nonatomic) NSString *userUK; // @synthesize userUK=_userUK;
@property(copy, nonatomic) NSString *panNickName; // @synthesize panNickName=_panNickName;
@property(copy, nonatomic) NSString *panAvatarUrl; // @synthesize panAvatarUrl=_panAvatarUrl;
@property(copy, nonatomic) NSString *oauthAvatarUrl; // @synthesize oauthAvatarUrl=_oauthAvatarUrl;
@property(nonatomic) long long oauthType; // @synthesize oauthType=_oauthType;
@property(copy, nonatomic) NSString *stoken; // @synthesize stoken=_stoken;
@property(copy, nonatomic) NSString *ptoken; // @synthesize ptoken=_ptoken;
@property(copy, nonatomic) NSString *userId; // @synthesize userId=_userId;
@property(copy, nonatomic) NSString *bduss; // @synthesize bduss=_bduss;
@property(copy, nonatomic) NSString *displayName; // @synthesize displayName=_displayName;
@property(copy, nonatomic) NSString *userName; // @synthesize userName=_userName;
@property(copy, nonatomic) NSString *userSignKey; // @synthesize userSignKey=_userSignKey;
- (id)decodeSignKey:(id)arg1;
- (id)avatar;
@property(readonly, nonatomic) NSString *secUid;
@property(readonly, nonatomic) NSString *cachePath;
- (id)initWithLoginModel:(id)arg1;
- (long long)userRank;
- (BOOL)isNormalVip;
- (BOOL)isSVip;
- (BOOL)isVip;
@property(retain, nonatomic) BDUserPersonalInfo *personalInfo;

@end

