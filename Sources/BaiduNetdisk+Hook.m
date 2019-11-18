#import "BaiduNetdisk+Hook.h"
#import "libBaiduNetdiskPlugin.h"
#import "CTSwizzledHelper.h"

@implementation NSObject (BaiduNetdisk)

+ (void)hookBaiduNetdisk
{
    ct_hookMethod(objc_getClass("BandwidthManager"), @selector(request:increaseBytesTransferred:), [self class], @selector(hook_request:increaseBytesTransferred:));
    ct_hookMethod(objc_getClass("BandwidthManager"), @selector(setMaxBytesPerSecond:), [self class], @selector(hook_setMaxBytesPerSecond:));
    
    ct_hookMethod(objc_getClass("BDUser"), @selector(isSVip), [self class], @selector(hook_isSVip));
    ct_hookMethod(objc_getClass("BDUserPersonalInfo"), @selector(setSvipExpireTime:), [self class], @selector(hook_setSvipExpireTime:));
    
    [[objc_getClass("FileTransSpeedUpTrialManager") sharedInstance] resetTrialStatus];
    [[objc_getClass("FileTransSpeedUpTrialManager") sharedInstance] checkProbationary];
    [[objc_getClass("FileTransSpeedUpTrialManager") sharedInstance] startTrial];

    ct_hookMethod(objc_getClass("FileTransSpeedUpTrialManager"), @selector(setProbationaryDuration:), [self class], @selector(hook_setProbationaryDuration:));
    ct_hookMethod(objc_getClass("FileTransSpeedUpTrialManager"), @selector(trialToken), [self class], @selector(hook_trialToken));
    
    ct_hookMethod(objc_getClass("SpeedUpTrialModel"), @selector(setToken:), [self class], @selector(hook_setToken:));
    
    ct_hookMethod(objc_getClass("AppVersionManager"), @selector(checkUpdate), [self class], @selector(hook_checkUpdate));
}

- (void)hook_request:(long long)arg1 increaseBytesTransferred:(unsigned long long)arg2;
{
    [self hook_request:MAXFLOAT increaseBytesTransferred:MAXFLOAT];
}

- (void)hook_setMaxBytesPerSecond:(unsigned long long)arg1
{
    [self hook_setMaxBytesPerSecond:MAXFLOAT];
}

- (BOOL)hook_isSVip
{
    return YES;
}

- (void)hook_setSvipExpireTime:(double)arg1
{
    NSTimeInterval expireTime = [[NSDate dateWithTimeIntervalSinceNow:10 * 365 * 24 * 60 * 60] timeIntervalSince1970];
    [self hook_setSvipExpireTime:expireTime];
}

- (void)hook_setProbationaryDuration:(long long)probationaryDuration
{
    [self hook_setProbationaryDuration:MAXFRAG];
}

- (id)hook_trialToken
{
    id token = [self hook_trialToken];
    NSLog(@"trialtoken = %@",token);
//    if (!token) {
//        token = [[NSUserDefaults standardUserDefaults] objectForKey:@"token"];
//        NSLog(@"localtrialtoken = %@",token);
//    }
    return token;
}

- (void)hook_setToken:(NSString*)token
{
    if (token.length) {
        [[NSUserDefaults standardUserDefaults] setObject:token forKey:@"token"];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
    NSLog(@"token = %@",token);
    [self hook_setToken:token];
}

- (unsigned long long)hook_checkUpdate
{
    return NO;
}

@end
