//
//  WeChatPlugin.h
//  WeChatPlugin
//
//  Created by TK on 2017/4/19.
//  Copyright © 2017年 tk. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuickLook/QuickLook.h>
#import "TKWeChatPluginConfig.h"
#import "TKHelper.h"

FOUNDATION_EXPORT double WeChatPluginVersionNumber;
FOUNDATION_EXPORT const unsigned char WeChatPluginVersionString[];

typedef void(^CDUnknownBlockType)(void);
typedef void(^CDUnknownBlockType1)(id arg1);
typedef void(^CDUnknownBlockType2)(id arg1, id arg2);
typedef void(^CDUnknownBlockType3)(id arg1, id arg2, id arg3);

#pragma mark - 微信原始的部分类与方法

@interface MMLoginOneClickViewController : NSViewController
@property(nonatomic) NSTextField *descriptionLabel;
- (void)onLoginButtonClicked:(id)arg1;
@property(nonatomic) NSButton *loginButton;
@end

@interface AccountService : NSObject
- (id)GetLastLoginUserName;
- (id)GetLastLoginAutoAuthKey;
- (BOOL)canAutoAuth;
- (void)AutoAuth;
- (void)ManualLogin:(id)arg1 withPassword:(id)arg2;
- (void)ManualLogout;
- (void)QRCodeLoginWithUserName:(id)arg1 password:(id)arg2;
- (void)onCurrentDeviceLockStateChanged:(BOOL)arg1;
@end

@interface MMLoginViewController : NSObject
@property(retain, nonatomic) MMLoginOneClickViewController *oneClickViewController;
@end

@interface MessageService : NSObject
- (void)onRevokeMsg:(id)arg1;
- (void)OnSyncBatchAddMsgs:(NSArray *)arg1 isFirstSync:(BOOL)arg2;
- (id)SendTextMessage:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4;
- (id)GetMsgData:(id)arg1 svrId:(long)arg2;
- (void)AddLocalMsg:(id)arg1 msgData:(id)arg2;
@end

@interface SKBuiltinString_t : NSObject
@property(retain, nonatomic, setter=SetString:) NSString *string; // @synthesize string;
@end

@interface AddMsg : NSObject
@property(retain, nonatomic, setter=SetContent:) SKBuiltinString_t *content; // @synthesize content;
@property(retain, nonatomic, setter=SetFromUserName:) SKBuiltinString_t *fromUserName; // @synthesize fromUserName;
@property(nonatomic, setter=SetMsgType:) int msgType; // @synthesize msgType;
@property(retain, nonatomic, setter=SetToUserName:) SKBuiltinString_t *toUserName; // @synthesize toUserName;
@property (nonatomic, assign) unsigned int createTime;
@end

@interface MessageData : NSObject
- (id)initWithMsgType:(long long)arg1;
@property(retain, nonatomic) NSString *fromUsrName;
@property(retain, nonatomic) NSString *toUsrName;
@property(retain, nonatomic) NSString *msgContent;
@property(retain, nonatomic) NSString *msgPushContent;
@property(nonatomic) int messageType;
@property(nonatomic) int msgStatus;
@property(nonatomic) int msgCreateTime;
@property(nonatomic) int mesLocalID;
@end

@interface CUtility : NSObject
+ (BOOL)HasWechatInstance;
+ (unsigned long long)getFreeDiskSpace;
+ (void)ReloadSessionForMsgSync;
+ (id)GetCurrentUserName;
@end

@class WCContactData;
@interface MMSessionInfo : NSObject
@property(nonatomic) BOOL m_bIsTop; // @synthesize m_bIsTop;
@property(nonatomic) BOOL m_bShowUnReadAsRedDot;
@property(nonatomic) BOOL m_isMentionedUnread; // @synthesize
@property(retain, nonatomic) NSString *m_nsUserName; // @synthesize m_nsUserName;
@property(retain, nonatomic) WCContactData *m_contact;

//@property(retain, nonatomic) NSString *m_nsUsrName; // @synthesize m_nsUsrName;
@property(nonatomic) unsigned int m_uiFriendScene;  // @synthesize m_uiFriendScene;

@end


@protocol MMChatsTableCellViewDelegate <NSObject>
@optional
- (void)cellViewReloadData:(MMSessionInfo *)arg1;
@end

@interface MMChatsTableCellView : NSTableCellView
@property(nonatomic) __weak id <MMChatsTableCellViewDelegate> delegate;
@property(retain, nonatomic) MMSessionInfo *sessionInfo;
- (void)menuWillOpen:(id)arg1;
- (void)contextMenuSticky:(id)arg1;
- (void)contextMenuDelete:(id)arg1;
- (void)tableView:(NSTableView *)arg1 rowGotMouseDown:(long long)arg2;
@end

@interface MMSessionMgr : NSObject
@property(retain, nonatomic) NSMutableArray *m_arrSession;
- (id)GetSessionAtIndex:(unsigned long long)arg1;
- (void)MuteSessionByUserName:(id)arg1;
//- (void)TopSessionByUserName:(id)arg1;
- (void)UnmuteSessionByUserName:(id)arg1;
- (void)UntopSessionByUserName:(id)arg1;
- (void)deleteSessionWithoutSyncToServerWithUserName:(id)arg1;
- (void)sortSessions;
@end

@interface LogoutCGI : NSTableCellView
- (void)sendLogoutCGIWithCompletion:(id)arg1;
@end

@interface MMNotificationService : NSObject
- (id)getNotificationContentWithMsgData:(id)arg1;
- (void)userNotificationCenter:(id)arg1 didActivateNotification:(id)arg2;
@end

#pragma mark - 调用 NSSearchPathForDirectoriesInDomains 的一些方法
@interface PathUtility : NSObject
+ (id)getSysCachePath;
+ (id)getSysDocumentPath;
+ (id)getSysLibraryPath;
@end

@interface MemoryMappedKV : NSObject
+ (id)mappedKVPathWithID:(id)arg1;
@end

@interface JTStatisticManager : NSObject
@property(retain, nonatomic) NSString *statFilePath;
@end

@interface WCContactData : NSObject

@property(retain, nonatomic) NSString *m_nsRemark;
@property(retain, nonatomic) NSString *m_nsNickName;
@property(retain, nonatomic) NSString *m_nsUsrName;
@property(retain, nonatomic) NSString *m_nsHeadImgUrl;

@property(nonatomic) unsigned int m_uiFriendScene;  // @synthesize m_uiFriendScene;
- (BOOL)isBrandContact;
- (BOOL)isSelf;
@end

@interface MMContactListRow : NSObject

@end

@interface MMSidebarItem : NSObject

@property(retain, nonatomic) NSString *identifier;

@end

@interface MMContactsSidebarItem : MMSidebarItem

@property(nonatomic) int type;

@end

@interface MMContactSidebarRow : MMContactListRow

@property(retain, nonatomic) MMContactsSidebarItem *sidebar;

@end

@class MMViewController;

@interface MMContactListLogic : NSObject

- (id)getContactListDataForTableList;

@end

@interface MMView : NSView

@property(nonatomic) __weak MMViewController *viewController;

@end

@class MMTableView;

@protocol MMTableViewDelegate <NSObject>

@optional
- (void)tableView:(MMTableView *)arg1 rowGotDoubleClicked:(long long)arg2;
- (void)tableView:(MMTableView *)arg1 rowGotMouseUp:(long long)arg2;
- (void)gotMouseDownNotAtRow:(MMTableView *)arg1;
- (void)tableView:(MMTableView *)arg1 rowGotMouseDown:(long long)arg2;
@end

__attribute__((visibility("hidden")))
@interface MMTableView : NSTableView
{
    BOOL _isPerformingAutomaticScroll;
    NSObject<MMTableViewDelegate> *_mmTableviewDelegate;
}

@property BOOL isPerformingAutomaticScroll; // @synthesize isPerformingAutomaticScroll=_isPerformingAutomaticScroll;
@property(nonatomic) __weak NSObject<MMTableViewDelegate> *mmTableviewDelegate; // @synthesize mmTableviewDelegate=_mmTableviewDelegate;
//- (void).cxx_destruct;    // IMP=0x000000010007e791
- (void)mouseUp:(id)arg1;    // IMP=0x000000010007e55a
- (void)mouseDown:(id)arg1;    // IMP=0x000000010007e3a3
- (void)scrollRowAtIndexToTop:(unsigned long long)arg1 animated:(BOOL)arg2;    // IMP=0x000000010007e227
- (void)scrollToTopAnimated:(BOOL)arg1;    // IMP=0x000000010007e20f
- (void)scrollToBottomAnimated:(BOOL)arg1;    // IMP=0x000000010007df2d
- (void)setFrameSize:(struct CGSize)arg1;    // IMP=0x000000010007de4b
- (void)setFrame:(struct CGRect)arg1;    // IMP=0x000000010007dd20

@end

@interface MMTabbarItem : NSObject

- (id)initWithTitle:(id)arg1 onStateImage:(id)arg2 onStateAlternateImage:(id)arg3 offStateImage:(id)arg4 offStateAlternateImage:(id)arg5;

@end

@class MMNavigationController;

@interface MMViewController : NSViewController

@property(nonatomic) __weak MMNavigationController *navigationController;
@property(retain, nonatomic) MMViewController *detailViewController;
@property(retain, nonatomic) MMTabbarItem *tabbarItem;

@end

@interface MMNavigationController : MMViewController
{
    MMViewController *_rootViewController;
    MMViewController *_topViewController;
    NSMutableArray *_viewControllerStack;
}

@property(retain, nonatomic) NSMutableArray *viewControllerStack; // @synthesize viewControllerStack=_viewControllerStack;
@property(readonly, nonatomic) __weak MMViewController *topViewController; // @synthesize topViewController=_topViewController;
@property(readonly, nonatomic) __weak MMViewController *rootViewController; // @synthesize rootViewController=_rootViewController;
//- (void).cxx_destruct;    // IMP=0x000000010015a56f
- (id)lastViewController;    // IMP=0x000000010015a42c
- (void)removeLastViewController;    // IMP=0x000000010015a244
//- (void)popViewControllerAnimated:(BOOL)arg1 completion:(CDUnknownBlockType)arg2;    // IMP=0x00000001001592ce
- (void)popViewControllerAnimated:(BOOL)arg1;    // IMP=0x00000001001592ba
//- (void)popToRootViewControllerWithCompletion:(CDUnknownBlockType)arg1;    // IMP=0x000000010015922c
//- (void)pushViewController:(id)arg1 animated:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;    // IMP=0x00000001001582d3
- (void)pushViewController:(id)arg1 animated:(BOOL)arg2;    // IMP=0x00000001001582be
- (id)tabbarItem;    // IMP=0x000000010015826e
- (void)setTabbarItem:(id)arg1;    // IMP=0x00000001001581fc
@property(retain, nonatomic) NSArray *viewControllers;
- (id)initWithRootViewController:(id)arg1;    // IMP=0x0000000100157c3b

@end

@interface MMTabbarController : MMViewController

@property(retain, nonatomic) NSArray *viewControllers;
@property(nonatomic) unsigned long long selectedIndex;

@end

@interface MMBaseChatsViewController : MMViewController

@end

@interface MMChatsViewController : MMBaseChatsViewController
@property (nonatomic, strong) NSTableView * tableView;
@end

@interface MMChatDetailViewController : MMViewController

@end

@interface MMContactsViewController : MMViewController {
    MMContactListLogic *_logic;
}
@property __weak MMTableView *listTableView;
@property(retain, nonatomic) NSArray *listDataForTableView;

- (id)getListForItem:(id)arg1;
- (void)_setDisplayedAllRowsForTableView:(BOOL)arg1;
- (void)_showAllContacts;

@end

@interface MMContactsDetailViewController : MMViewController

@end

@interface LeftViewController : MMTabbarController

@end

@class MMTimeLineMainViewController;

@interface MMMainViewController : MMViewController

@property(nonatomic) __weak LeftViewController *leftViewController;
@property(nonatomic) __weak MMViewController *rightViewController;
@property(retain, nonatomic) MMChatsViewController *chatsViewController;
@property(retain, nonatomic) MMTimeLineMainViewController *timeLineViewController;

- (void)setupTabbarController;
- (void)showLockScreenWithType:(int)arg1 playSound:(BOOL)arg2;

@end

@interface MMWindowController : NSWindowController

@end

@interface MMMainWindowController : MMWindowController

@property(retain, nonatomic) MMLoginViewController *loginViewController;
- (void)onAuthOK;
- (void)onLogOut;

- (void)windowDidLoad;
- (void)showLoginView;
- (void)showMainView;

@end

@interface MMLoginQRCodeViewController : MMViewController

- (void)viewDidLoad;

@end
@interface MMStatusItem : NSObject
@property(retain, nonatomic) NSStatusItem *statusItem; // @synthesize statusItem=_statusItem;
@end
@interface WeChat : NSObject

@property(retain, nonatomic) MMMainWindowController *mainWindowController;
@property(retain, nonatomic) MMStatusItem *statusItem; // @synthesize statusItem=_statusItem;

+ (id)sharedInstance;
- (void)onAuthOK;
- (void)checkForUpdates;
@property(nonatomic) MMChatsViewController *chatsViewController;
@property(nonatomic) BOOL isAppTerminating;
@end

@interface MMViewerWindow : NSWindowController

- (void)closeWindowAnimated:(BOOL)arg1;

@end

@class WKWebView;

@interface MMChatMsgUrlViewerWindow : MMViewerWindow

@property(retain, nonatomic) WKWebView *webView;

- (void)openInExternalBrowser:(id)arg1;

@end

@interface MMCGIRequester : NSObject

+ (id)requestCGI:(unsigned int)arg1 Body:(id)arg2 Response:(void(^)(NSUInteger a1, id a2, id a3))arg3;
- (void)OnResponseCGI:(BOOL)arg1 sessionId:(unsigned int)arg2 cgiWrap:(id)arg3;

@end

@interface PBGeneratedMessage : NSObject
{
    int _has_bits_[3];
    int _serializedSize;
    struct PBClassInfo *_classInfo;
    NSMutableArray *_propertyNames;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x000000010028134e
- (BOOL)hasProperty:(int)arg1;    // IMP=0x00000001002816af
- (unsigned int)continueFlag;    // IMP=0x00000001002816a7
- (id)baseResponse;    // IMP=0x000000010028169f
- (id)baseRequest;    // IMP=0x0000000100281697
- (void)SetBaseRequest:(id)arg1;    // IMP=0x00000001002815f2
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x000000010028158e
- (int)serializedSize;    // IMP=0x000000010028154d
- (id)serializedData;    // IMP=0x000000010028149f
- (BOOL)isInitialized;    // IMP=0x0000000100281497
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x00000001002813ef
- (id)mergeFromData:(id)arg1;    // IMP=0x00000001002811ac

@end

@interface BaseRequest : PBGeneratedMessage
{
    unsigned int hasSessionKey:1;
    unsigned int hasUin:1;
    unsigned int hasDeviceId:1;
    unsigned int hasClientVersion:1;
    unsigned int hasDeviceType:1;
    unsigned int hasScene:1;
    unsigned int uin;
    int clientVersion;
    unsigned int scene;
    NSData *sessionKey;
    NSData *deviceId;
    NSData *deviceType;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x00000001005f256c
@property(nonatomic, setter=SetScene:) unsigned int scene; // @synthesize scene;
@property(readonly, nonatomic) BOOL hasScene; // @synthesize hasScene;
@property(retain, nonatomic, setter=SetDeviceType:) NSData *deviceType; // @synthesize deviceType;
@property(readonly, nonatomic) BOOL hasDeviceType; // @synthesize hasDeviceType;
@property(nonatomic, setter=SetClientVersion:) int clientVersion; // @synthesize clientVersion;
@property(readonly, nonatomic) BOOL hasClientVersion; // @synthesize hasClientVersion;
@property(retain, nonatomic, setter=SetDeviceId:) NSData *deviceId; // @synthesize deviceId;
@property(readonly, nonatomic) BOOL hasDeviceId; // @synthesize hasDeviceId;
@property(nonatomic, setter=SetUin:) unsigned int uin; // @synthesize uin;
@property(readonly, nonatomic) BOOL hasUin; // @synthesize hasUin;
@property(retain, nonatomic, setter=SetSessionKey:) NSData *sessionKey; // @synthesize sessionKey;
@property(readonly, nonatomic) BOOL hasSessionKey; // @synthesize hasSessionKey;
//- (void).cxx_destruct;    // IMP=0x00000001005f28eb
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x00000001005f25fb
- (int)serializedSize;    // IMP=0x00000001005f23e0
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x00000001005f2214
- (BOOL)isInitialized;    // IMP=0x00000001005f219b
- (id)init;    // IMP=0x00000001005f1f46

@end

@class SKBuiltinBuffer_t;

@interface SnsTimeLineRequest : PBGeneratedMessage
{
    unsigned int hasBaseRequest:1;
    unsigned int hasFirstPageMd5:1;
    unsigned int hasMaxId:1;
    unsigned int hasMinFilterId:1;
    unsigned int hasLastRequestTime:1;
    unsigned int hasClientLatestId:1;
    unsigned int hasSession:1;
    unsigned int lastRequestTime;
    BaseRequest *baseRequest;
    NSString *firstPageMd5;
    unsigned long long maxId;
    unsigned long long minFilterId;
    unsigned long long clientLatestId;
    SKBuiltinBuffer_t *session;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x0000000100423ed3
@property(retain, nonatomic, setter=SetSession:) SKBuiltinBuffer_t *session; // @synthesize session;
@property(readonly, nonatomic) BOOL hasSession; // @synthesize hasSession;
@property(nonatomic, setter=SetClientLatestId:) unsigned long long clientLatestId; // @synthesize clientLatestId;
@property(readonly, nonatomic) BOOL hasClientLatestId; // @synthesize hasClientLatestId;
@property(nonatomic, setter=SetLastRequestTime:) unsigned int lastRequestTime; // @synthesize lastRequestTime;
@property(readonly, nonatomic) BOOL hasLastRequestTime; // @synthesize hasLastRequestTime;
@property(nonatomic, setter=SetMinFilterId:) unsigned long long minFilterId; // @synthesize minFilterId;
@property(readonly, nonatomic) BOOL hasMinFilterId; // @synthesize hasMinFilterId;
@property(nonatomic, setter=SetMaxId:) unsigned long long maxId; // @synthesize maxId;
@property(readonly, nonatomic) BOOL hasMaxId; // @synthesize hasMaxId;
@property(retain, nonatomic, setter=SetFirstPageMd5:) NSString *firstPageMd5; // @synthesize firstPageMd5;
@property(readonly, nonatomic) BOOL hasFirstPageMd5; // @synthesize hasFirstPageMd5;
@property(retain, nonatomic, setter=SetBaseRequest:) BaseRequest *baseRequest; // @synthesize baseRequest;
@property(readonly, nonatomic) BOOL hasBaseRequest; // @synthesize hasBaseRequest;
//- (void).cxx_destruct;    // IMP=0x000000010042430c
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x0000000100423f62
- (int)serializedSize;    // IMP=0x0000000100423d11
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x0000000100423b08
- (BOOL)isInitialized;    // IMP=0x0000000100423a2c
- (id)init;    // IMP=0x0000000100423811

@end

@interface SnsTimeLineResponse : PBGeneratedMessage
{
    unsigned int hasBaseResponse:1;
    unsigned int hasFirstPageMd5:1;
    unsigned int hasObjectCount:1;
    unsigned int hasNewRequestTime:1;
    unsigned int hasObjectCountForSameMd5:1;
    unsigned int hasControlFlag:1;
    unsigned int hasServerConfig:1;
    unsigned int hasAdvertiseCount:1;
    unsigned int hasSession:1;
    unsigned int objectCount;
    unsigned int newRequestTime;
    unsigned int objectCountForSameMd5;
    unsigned int controlFlag;
    unsigned int advertiseCount;
    //    BaseResponse *baseResponse;
    NSString *firstPageMd5;
    NSMutableArray *mutableObjectListList;
    //    SnsServerConfig *serverConfig;
    NSMutableArray *mutableAdvertiseListList;
    SKBuiltinBuffer_t *session;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x00000001004253bf
@property(retain, nonatomic, setter=SetSession:) SKBuiltinBuffer_t *session; // @synthesize session;
@property(readonly, nonatomic) BOOL hasSession; // @synthesize hasSession;
@property(retain, nonatomic) NSMutableArray *mutableAdvertiseListList; // @synthesize mutableAdvertiseListList;
@property(nonatomic, setter=SetAdvertiseCount:) unsigned int advertiseCount; // @synthesize advertiseCount;
@property(readonly, nonatomic) BOOL hasAdvertiseCount; // @synthesize hasAdvertiseCount;
//@property(retain, nonatomic, setter=SetServerConfig:) SnsServerConfig *serverConfig; // @synthesize serverConfig;
@property(readonly, nonatomic) BOOL hasServerConfig; // @synthesize hasServerConfig;
@property(nonatomic, setter=SetControlFlag:) unsigned int controlFlag; // @synthesize controlFlag;
@property(readonly, nonatomic) BOOL hasControlFlag; // @synthesize hasControlFlag;
@property(nonatomic, setter=SetObjectCountForSameMd5:) unsigned int objectCountForSameMd5; // @synthesize objectCountForSameMd5;
@property(readonly, nonatomic) BOOL hasObjectCountForSameMd5; // @synthesize hasObjectCountForSameMd5;
@property(nonatomic, setter=SetNewRequestTime:) unsigned int newRequestTime; // @synthesize newRequestTime;
@property(readonly, nonatomic) BOOL hasNewRequestTime; // @synthesize hasNewRequestTime;
@property(retain, nonatomic) NSMutableArray *mutableObjectListList; // @synthesize mutableObjectListList;
@property(nonatomic, setter=SetObjectCount:) unsigned int objectCount; // @synthesize objectCount;
@property(readonly, nonatomic) BOOL hasObjectCount; // @synthesize hasObjectCount;
@property(retain, nonatomic, setter=SetFirstPageMd5:) NSString *firstPageMd5; // @synthesize firstPageMd5;
@property(readonly, nonatomic) BOOL hasFirstPageMd5; // @synthesize hasFirstPageMd5;
//@property(retain, nonatomic, setter=SetBaseResponse:) BaseResponse *baseResponse; // @synthesize baseResponse;
@property(readonly, nonatomic) BOOL hasBaseResponse; // @synthesize hasBaseResponse;
//- (void).cxx_destruct;    // IMP=0x0000000100425d52
- (void)addAdvertiseList:(id)arg1;    // IMP=0x0000000100425a8d
- (void)addAdvertiseListFromArray:(id)arg1;    // IMP=0x00000001004259ba
- (void)addObjectList:(id)arg1;    // IMP=0x00000001004258e0
- (void)addObjectListFromArray:(id)arg1;    // IMP=0x000000010042580d
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x000000010042544e
- (int)serializedSize;    // IMP=0x0000000100424f70
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x0000000100424a97
- (BOOL)isInitialized;    // IMP=0x0000000100424766
@property(retain, nonatomic) NSMutableArray *advertiseList; // @dynamic advertiseList;
- (id)advertiseListList;    // IMP=0x0000000100424675
@property(retain, nonatomic) NSMutableArray *objectList; // @dynamic objectList;
- (id)objectListList;    // IMP=0x0000000100424518
- (id)init;    // IMP=0x000000010042434e

@end

@interface SnsUserPageRequest : PBGeneratedMessage
{
    unsigned int hasBaseRequest:1;
    unsigned int hasFirstPageMd5:1;
    unsigned int hasUsername:1;
    unsigned int hasMaxId:1;
    unsigned int hasSource:1;
    unsigned int hasMinFilterId:1;
    unsigned int hasLastRequestTime:1;
    unsigned int source;
    unsigned int lastRequestTime;
    BaseRequest *baseRequest;
    NSString *firstPageMd5;
    NSString *username;
    unsigned long long maxId;
    unsigned long long minFilterId;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x00000001006b0d42
@property(nonatomic, setter=SetLastRequestTime:) unsigned int lastRequestTime; // @synthesize lastRequestTime;
@property(readonly, nonatomic) BOOL hasLastRequestTime; // @synthesize hasLastRequestTime;
@property(nonatomic, setter=SetMinFilterId:) unsigned long long minFilterId; // @synthesize minFilterId;
@property(readonly, nonatomic) BOOL hasMinFilterId; // @synthesize hasMinFilterId;
@property(nonatomic, setter=SetSource:) unsigned int source; // @synthesize source;
@property(readonly, nonatomic) BOOL hasSource; // @synthesize hasSource;
@property(nonatomic, setter=SetMaxId:) unsigned long long maxId; // @synthesize maxId;
@property(readonly, nonatomic) BOOL hasMaxId; // @synthesize hasMaxId;
@property(retain, nonatomic, setter=SetUsername:) NSString *username; // @synthesize username;
@property(readonly, nonatomic) BOOL hasUsername; // @synthesize hasUsername;
@property(retain, nonatomic, setter=SetFirstPageMd5:) NSString *firstPageMd5; // @synthesize firstPageMd5;
@property(readonly, nonatomic) BOOL hasFirstPageMd5; // @synthesize hasFirstPageMd5;
@property(retain, nonatomic, setter=SetBaseRequest:) BaseRequest *baseRequest; // @synthesize baseRequest;
@property(readonly, nonatomic) BOOL hasBaseRequest; // @synthesize hasBaseRequest;
//- (void).cxx_destruct;    // IMP=0x00000001006b10eb
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x00000001006b0dd1
- (int)serializedSize;    // IMP=0x00000001006b0b81
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x00000001006b0979
- (BOOL)isInitialized;    // IMP=0x00000001006b0900
- (id)init;    // IMP=0x00000001006b06de

@end

@interface SnsUserPageResponse : PBGeneratedMessage
{
    unsigned int hasBaseResponse:1;
    unsigned int hasFirstPageMd5:1;
    unsigned int hasObjectCount:1;
    unsigned int hasObjectTotalCount:1;
    unsigned int hasSnsUserInfo:1;
    unsigned int hasNewRequestTime:1;
    unsigned int hasObjectCountForSameMd5:1;
    unsigned int hasServerConfig:1;
    unsigned int objectCount;
    unsigned int objectTotalCount;
    unsigned int newRequestTime;
    unsigned int objectCountForSameMd5;
    //    BaseResponse *baseResponse;
    NSString *firstPageMd5;
    NSMutableArray *mutableObjectListList;
    //    SnsUserInfo *snsUserInfo;
    //    SnsServerConfig *serverConfig;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x00000001006b1d09
//@property(retain, nonatomic, setter=SetServerConfig:) SnsServerConfig *serverConfig; // @synthesize serverConfig;
@property(readonly, nonatomic) BOOL hasServerConfig; // @synthesize hasServerConfig;
@property(nonatomic, setter=SetObjectCountForSameMd5:) unsigned int objectCountForSameMd5; // @synthesize objectCountForSameMd5;
@property(readonly, nonatomic) BOOL hasObjectCountForSameMd5; // @synthesize hasObjectCountForSameMd5;
@property(nonatomic, setter=SetNewRequestTime:) unsigned int newRequestTime; // @synthesize newRequestTime;
@property(readonly, nonatomic) BOOL hasNewRequestTime; // @synthesize hasNewRequestTime;
//@property(retain, nonatomic, setter=SetSnsUserInfo:) SnsUserInfo *snsUserInfo; // @synthesize snsUserInfo;
@property(readonly, nonatomic) BOOL hasSnsUserInfo; // @synthesize hasSnsUserInfo;
@property(nonatomic, setter=SetObjectTotalCount:) unsigned int objectTotalCount; // @synthesize objectTotalCount;
@property(readonly, nonatomic) BOOL hasObjectTotalCount; // @synthesize hasObjectTotalCount;
@property(retain, nonatomic) NSMutableArray *mutableObjectListList; // @synthesize mutableObjectListList;
@property(nonatomic, setter=SetObjectCount:) unsigned int objectCount; // @synthesize objectCount;
@property(readonly, nonatomic) BOOL hasObjectCount; // @synthesize hasObjectCount;
@property(retain, nonatomic, setter=SetFirstPageMd5:) NSString *firstPageMd5; // @synthesize firstPageMd5;
@property(readonly, nonatomic) BOOL hasFirstPageMd5; // @synthesize hasFirstPageMd5;
//@property(retain, nonatomic, setter=SetBaseResponse:) BaseResponse *baseResponse; // @synthesize baseResponse;
@property(readonly, nonatomic) BOOL hasBaseResponse; // @synthesize hasBaseResponse;
//- (void).cxx_destruct;    // IMP=0x00000001006b2371
- (void)addObjectList:(id)arg1;    // IMP=0x00000001006b2112
- (void)addObjectListFromArray:(id)arg1;    // IMP=0x00000001006b203f
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x00000001006b1d98
- (int)serializedSize;    // IMP=0x00000001006b19ee
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x00000001006b166b
- (BOOL)isInitialized;    // IMP=0x00000001006b144f
@property(retain, nonatomic) NSMutableArray *objectList; // @dynamic objectList;
- (id)objectListList;    // IMP=0x00000001006b12d6
- (id)init;    // IMP=0x00000001006b112d

@end

@interface MMCGIRequestUtil : NSObject
{
}

+ (unsigned int)GetRSACertVersion;    // IMP=0x00000001007826ea
+ (id)InitBaseRequestWithScene:(unsigned int)arg1;    // IMP=0x0000000100782385

@end

@interface MMCGIWrap : NSObject
{
    BOOL _m_bFrequencyLimit;
    BOOL _m_notifyPartLen;
    unsigned int _m_functionId;
    int _m_channelType;
    int _m_retryCount;
    int _m_timeout;
    int _m_rsaVersion;
    unsigned int _m_requestDefaultHeadUin;
    int _m_responsePkgHeadRet;
    PBGeneratedMessage *_m_requestPb;
    PBGeneratedMessage *_m_responsePb;
    NSData *_m_responseServerId;
    NSData *_m_responseDecryptKey;
    NSString *_m_rsaKeye;
    NSString *_m_rsaKeyn;
    NSObject *_m_userData;
}

@property BOOL m_notifyPartLen; // @synthesize m_notifyPartLen=_m_notifyPartLen;
@property(retain) NSObject *m_userData; // @synthesize m_userData=_m_userData;
@property int m_responsePkgHeadRet; // @synthesize m_responsePkgHeadRet=_m_responsePkgHeadRet;
@property unsigned int m_requestDefaultHeadUin; // @synthesize m_requestDefaultHeadUin=_m_requestDefaultHeadUin;
@property int m_rsaVersion; // @synthesize m_rsaVersion=_m_rsaVersion;
@property(retain) NSString *m_rsaKeyn; // @synthesize m_rsaKeyn=_m_rsaKeyn;
@property(retain) NSString *m_rsaKeye; // @synthesize m_rsaKeye=_m_rsaKeye;
@property(retain) NSData *m_responseDecryptKey; // @synthesize m_responseDecryptKey=_m_responseDecryptKey;
@property BOOL m_bFrequencyLimit; // @synthesize m_bFrequencyLimit=_m_bFrequencyLimit;
@property int m_timeout; // @synthesize m_timeout=_m_timeout;
@property int m_retryCount; // @synthesize m_retryCount=_m_retryCount;
@property int m_channelType; // @synthesize m_channelType=_m_channelType;
@property(retain) NSData *m_responseServerId; // @synthesize m_responseServerId=_m_responseServerId;
@property(retain) PBGeneratedMessage *m_responsePb; // @synthesize m_responsePb=_m_responsePb;
@property(retain) PBGeneratedMessage *m_requestPb; // @synthesize m_requestPb=_m_requestPb;
@property unsigned int m_functionId; // @synthesize m_functionId=_m_functionId;
//- (void).cxx_destruct;    // IMP=0x00000001007a8282
- (void)Reuse;    // IMP=0x00000001007a8019
- (id)init;    // IMP=0x00000001007a7f12

@end

@interface MMServiceCenter : NSObject
{
    NSMutableDictionary *m_dicService;
    NSRecursiveLock *m_lock;
}

+ (id)defaultCenter;    // IMP=0x00000001005c33db
//- (void).cxx_destruct;    // IMP=0x00000001005c42c5
- (void)callClearData;    // IMP=0x00000001005c4058
- (void)callServiceMemoryWarning;    // IMP=0x00000001005c3e5a
- (void)callTerminate;    // IMP=0x00000001005c3c5c
- (void)callEnterBackground;    // IMP=0x00000001005c3a5e
- (void)callEnterForeground;    // IMP=0x00000001005c3860
- (void)removeService:(Class)arg1;    // IMP=0x00000001005c3790
- (id)getService:(Class)arg1;    // IMP=0x00000001005c346e
- (BOOL)isServiceExist:(Class)arg1;    // IMP=0x00000001005c33ec
- (void)dealloc;    // IMP=0x00000001005c327b
- (id)init;    // IMP=0x00000001005c3193

@end

@interface MMService : NSObject
{
    BOOL m_isServiceRemoved;
    BOOL m_isServicePersistent;
}

@property BOOL m_isServicePersistent; // @synthesize m_isServicePersistent;
@property BOOL m_isServiceRemoved; // @synthesize m_isServiceRemoved;
- (void)dealloc;    // IMP=0x00000001005c3120

@end

struct AutoBuffer {
    
};

struct CNetCmd {
    
};

@interface MMCGIService : MMService
{
    //    struct unordered_map<unsigned int, MMCGI *, std::__1::hash<unsigned int>, std::__1::equal_to<unsigned int>, std::__1::allocator<std::__1::pair<const unsigned int, MMCGI *>>> m_cgiMap;
    //    struct unordered_map<unsigned long, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>, std::__1::hash<unsigned long>, std::__1::equal_to<unsigned long>, std::__1::allocator<std::__1::pair<const unsigned long, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>>>> m_delegateMap;
    BOOL m_hasClearData;
    BOOL _m_isNetConnected;
    BOOL _m_isClearingCGI;
    unsigned int _m_uin;
    NSData *_m_AESSessionKey;
    NSData *_m_serverId;
    NSMutableDictionary *_m_usbCmdhandler;
    NSRecursiveLock *_m_usbCmdLock;
    NSData *_m_usbEncryptKey;
    NSLock *_m_lock;
}

+ (void)LazyRegisterExtension;    // IMP=0x00000001002e8e41
+ (id)serverIdPath;    // IMP=0x0000000100507f57
+ (id)CGIThreadQueue;    // IMP=0x000000010053dc22
@property(retain, nonatomic) NSLock *m_lock; // @synthesize m_lock=_m_lock;
@property(retain) NSData *m_usbEncryptKey; // @synthesize m_usbEncryptKey=_m_usbEncryptKey;
@property(retain, nonatomic) NSRecursiveLock *m_usbCmdLock; // @synthesize m_usbCmdLock=_m_usbCmdLock;
@property(retain, nonatomic) NSMutableDictionary *m_usbCmdhandler; // @synthesize m_usbCmdhandler=_m_usbCmdhandler;
@property BOOL m_isClearingCGI; // @synthesize m_isClearingCGI=_m_isClearingCGI;
@property BOOL m_isNetConnected; // @synthesize m_isNetConnected=_m_isNetConnected;
@property(retain) NSData *m_serverId; // @synthesize m_serverId=_m_serverId;
@property unsigned int m_uin; // @synthesize m_uin=_m_uin;
@property(retain) NSData *m_AESSessionKey; // @synthesize m_AESSessionKey=_m_AESSessionKey;
//- (id).cxx_construct;    // IMP=0x00000001002e9f5b
//- (void).cxx_destruct;    // IMP=0x00000001002e9ec8
- (void)StopCGIBySessionId:(unsigned int)arg1;    // IMP=0x00000001002e9b3a
- (void)ClearCGIByDelegate:(id)arg1;    // IMP=0x00000001002e9a82
- (unsigned int)SendOnlyCmd:(id)arg1;    // IMP=0x00000001002e9762
- (unsigned int)RequestCGI:(id)arg1 delegate:(id)arg2;    // IMP=0x00000001002e91df
- (void)onServiceClearData;    // IMP=0x00000001002e906d
- (void)onServiceInit;    // IMP=0x00000001002e8f07
- (void)dealloc;    // IMP=0x00000001002e8e14
- (id)init;    // IMP=0x00000001002e8d18
- (void)saveServerId:(id)arg1;    // IMP=0x0000000100508102
- (void)loadServerId;    // IMP=0x0000000100508059
- (void)clearData;    // IMP=0x0000000100508018
- (void)OnUserQuit;    // IMP=0x0000000100507f45
- (void)OnAuthFail;    // IMP=0x0000000100507f33
- (void)OnAuthOK:(id)arg1;    // IMP=0x0000000100507d6a
- (void)OnBeforeAuth;    // IMP=0x0000000100507d58
- (BOOL)isSessionCmd:(unsigned int)arg1;    // IMP=0x000000010053ed3c
- (BOOL)isCommonRsaEncrypt:(unsigned int)arg1;    // IMP=0x000000010053ecfd
- (BOOL)isKVCommRSAEncrypt:(unsigned int)arg1;    // IMP=0x000000010053ecc6
- (BOOL)isAuthRSAEncrypt:(unsigned int)arg1;    // IMP=0x000000010053eca6
- (BOOL)isBaseRSAEncrypt:(unsigned int)arg1;    // IMP=0x000000010053ec94
- (id)GetRsaCertInfoWithCGI:(unsigned int)arg1;    // IMP=0x000000010053e9ef
- (void)processNetDisconnect;    // IMP=0x000000010053e375
- (void)onNetStatusChange:(int)arg1;    // IMP=0x000000010053e249
- (int)OnMMNetTaskEnd:(unsigned int)arg1 errType:(int)arg2 errCode:(int)arg3 serverId:(const struct AutoBuffer *)arg4;    // IMP=0x000000010053dc30
- (int)ParseResponseData:(unsigned int)arg1 buffer:(const struct AutoBuffer *)arg2 servIdBuf:(struct AutoBuffer *)arg3;    // IMP=0x000000010053d3e0
- (BOOL)FillRequestData:(unsigned int)arg1 buffer:(struct AutoBuffer *)arg2;    // IMP=0x000000010053b891
- (void)stopMMNetTask:(unsigned int)arg1;    // IMP=0x000000010053b885
- (void)startMMNetTask:(id)arg1;    // IMP=0x000000010053b6cf
- (void)fillSendOnlyCmd:(struct CNetCmd *)arg1 withCgi:(id)arg2;    // IMP=0x000000010053b62b
- (void)fillCgiCmd:(struct CNetCmd *)arg1 withCgi:(id)arg2;    // IMP=0x000000010053b39e
- (unsigned int)GetUin;    // IMP=0x000000010053b38c
- (id)GetSessionKey;    // IMP=0x000000010053b37a
- (void)eraseSessionIdInDelegate:(id)arg1 sessionId:(unsigned int)arg2;    // IMP=0x00000001005773c4
//- (void)eraseDelegate:(id)arg1 sessionIdSet:(set_55031187 *)arg2;    // IMP=0x00000001005772ad
- (void)addDelegate:(id)arg1 sessionId:(unsigned int)arg2;    // IMP=0x0000000100576f94
- (void)eraseCGI:(unsigned int)arg1;    // IMP=0x0000000100576ee8
//- (void)getAllCGI:(vector_f672cb0f *)arg1;    // IMP=0x0000000100576de7
- (id)findCGI:(unsigned int)arg1;    // IMP=0x0000000100576cf0
- (void)addCGI:(id)arg1;    // IMP=0x00000001005769d2
- (void)closeCGI:(unsigned int)arg1;    // IMP=0x0000000100576990
- (void)recordCGIData:(id)arg1 delegate:(id)arg2;    // IMP=0x00000001005768f4

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@protocol MMCGIDelegate <NSObject>

@end

@protocol MMService <NSObject>

@end

@interface MMLogger : NSObject

+ (void)logWithMMLogLevel:(int)arg1 module:(const char *)arg2 file:(const char *)arg3 line:(int)arg4 func:(const char *)arg5 message:(id)arg6;    // IMP=0x000000010076c5af

@end

struct MMCGIItem {
    int _field1;
    int _field2;
    int _field3;
    char *_field4;
    Class _field5;
    int _field6;
    int _field7;
    int _field8;
};

@interface MMCGIConfig : NSObject

+ (const struct MMCGIItem *)findItemWithCmdID:(int)arg1;    // IMP=0x00000001003c0338
+ (const struct MMCGIItem *)findItemWithFunc:(int)arg1;    // IMP=0x00000001003c02ca
+ (id)sharedInstance;    // IMP=0x00000001003bfd50
//- (id).cxx_construct;    // IMP=0x00000001003c03d3
//- (void).cxx_destruct;    // IMP=0x00000001003c03a6
- (const struct MMCGIItem *)findItemWithCmdIDInternal:(int)arg1;    // IMP=0x00000001003c029b
- (const struct MMCGIItem *)findItemWithFuncInternal:(int)arg1;    // IMP=0x00000001003c026c
- (void)config;    // IMP=0x00000001003bfdd6

@end

@interface SKBuiltinBuffer_t : PBGeneratedMessage
{
    unsigned int hasILen:1;
    unsigned int hasBuffer:1;
    unsigned int iLen;
    NSData *buffer;
}

+ (id)parseFromData:(id)arg1;    // IMP=0x00000001005f4fb6
+ (id)skBufferWithData:(id)arg1;    // IMP=0x00000001009b611e
@property(retain, nonatomic, setter=SetBuffer:) NSData *buffer; // @synthesize buffer;
@property(readonly, nonatomic) BOOL hasBuffer; // @synthesize hasBuffer;
@property(nonatomic, setter=SetILen:) unsigned int iLen; // @synthesize iLen;
@property(readonly, nonatomic) BOOL hasILen; // @synthesize hasILen;
//- (void).cxx_destruct;    // IMP=0x00000001005f5199
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x00000001005f5045
- (int)serializedSize;    // IMP=0x00000001005f4f29
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x00000001005f4e70
- (BOOL)isInitialized;    // IMP=0x00000001005f4e55
- (id)init;    // IMP=0x00000001005f4d5f

@end

@interface SnsObject : PBGeneratedMessage
+ (id)parseFromData:(id)arg1;    // IMP=0x000000010041c5a4
@property(retain, nonatomic) NSMutableArray *mutableGroupUserList; // @synthesize mutableGroupUserList;
@property(nonatomic, setter=SetGroupUserCount:) unsigned int groupUserCount; // @synthesize groupUserCount;
@property(readonly, nonatomic) BOOL hasGroupUserCount; // @synthesize hasGroupUserCount;
@property(nonatomic, setter=SetDeleteFlag:) unsigned int deleteFlag; // @synthesize deleteFlag;
@property(readonly, nonatomic) BOOL hasDeleteFlag; // @synthesize hasDeleteFlag;
@property(retain, nonatomic) NSMutableArray *mutableBlackListList; // @synthesize mutableBlackListList;
@property(nonatomic, setter=SetBlackListCount:) unsigned int blackListCount; // @synthesize blackListCount;
@property(readonly, nonatomic) BOOL hasBlackListCount; // @synthesize hasBlackListCount;
@property(nonatomic, setter=SetReferId:) unsigned long long referId; // @synthesize referId;
@property(readonly, nonatomic) BOOL hasReferId; // @synthesize hasReferId;
@property(retain, nonatomic, setter=SetReferUsername:) NSString *referUsername; // @synthesize referUsername;
@property(readonly, nonatomic) BOOL hasReferUsername; // @synthesize hasReferUsername;
@property(nonatomic, setter=SetIsNotRichText:) unsigned int isNotRichText; // @synthesize isNotRichText;
@property(readonly, nonatomic) BOOL hasIsNotRichText; // @synthesize hasIsNotRichText;
@property(retain, nonatomic) NSMutableArray *mutableGroupListList; // @synthesize mutableGroupListList;
@property(nonatomic, setter=SetGroupCount:) unsigned int groupCount; // @synthesize groupCount;
@property(readonly, nonatomic) BOOL hasGroupCount; // @synthesize hasGroupCount;
@property(nonatomic, setter=SetNoChange:) unsigned int noChange; // @synthesize noChange;
@property(readonly, nonatomic) BOOL hasNoChange; // @synthesize hasNoChange;
@property(nonatomic, setter=SetExtFlag:) unsigned int extFlag; // @synthesize extFlag;
@property(readonly, nonatomic) BOOL hasExtFlag; // @synthesize hasExtFlag;
@property(retain, nonatomic) NSMutableArray *mutableWithUserListList; // @synthesize mutableWithUserListList;
@property(nonatomic, setter=SetWithUserListCount:) unsigned int withUserListCount; // @synthesize withUserListCount;
@property(readonly, nonatomic) BOOL hasWithUserListCount; // @synthesize hasWithUserListCount;
@property(nonatomic, setter=SetWithUserCount:) unsigned int withUserCount; // @synthesize withUserCount;
@property(readonly, nonatomic) BOOL hasWithUserCount; // @synthesize hasWithUserCount;
@property(retain, nonatomic) NSMutableArray *mutableCommentUserListList; // @synthesize mutableCommentUserListList;
@property(nonatomic, setter=SetCommentUserListCount:) unsigned int commentUserListCount; // @synthesize commentUserListCount;
@property(readonly, nonatomic) BOOL hasCommentUserListCount; // @synthesize hasCommentUserListCount;
@property(nonatomic, setter=SetCommentCount:) unsigned int commentCount; // @synthesize commentCount;
@property(readonly, nonatomic) BOOL hasCommentCount; // @synthesize hasCommentCount;
@property(retain, nonatomic) NSMutableArray *mutableLikeUserListList; // @synthesize mutableLikeUserListList;
@property(nonatomic, setter=SetLikeUserListCount:) unsigned int likeUserListCount; // @synthesize likeUserListCount;
@property(readonly, nonatomic) BOOL hasLikeUserListCount; // @synthesize hasLikeUserListCount;
@property(nonatomic, setter=SetLikeCount:) unsigned int likeCount; // @synthesize likeCount;
@property(readonly, nonatomic) BOOL hasLikeCount; // @synthesize hasLikeCount;
@property(nonatomic, setter=SetLikeFlag:) unsigned int likeFlag; // @synthesize likeFlag;
@property(readonly, nonatomic) BOOL hasLikeFlag; // @synthesize hasLikeFlag;
@property(retain, nonatomic, setter=SetObjectDesc:) SKBuiltinBuffer_t *objectDesc; // @synthesize objectDesc;
@property(readonly, nonatomic) BOOL hasObjectDesc; // @synthesize hasObjectDesc;
@property(nonatomic, setter=SetCreateTime:) unsigned int createTime; // @synthesize createTime;
@property(readonly, nonatomic) BOOL hasCreateTime; // @synthesize hasCreateTime;
@property(retain, nonatomic, setter=SetNickname:) NSString *nickname; // @synthesize nickname;
@property(readonly, nonatomic) BOOL hasNickname; // @synthesize hasNickname;
@property(retain, nonatomic, setter=SetUsername:) NSString *username; // @synthesize username;
@property(readonly, nonatomic) BOOL hasUsername; // @synthesize hasUsername;
@property(nonatomic, setter=SetId:) unsigned long long id; // @synthesize id=id_;
@property(readonly, nonatomic) BOOL hasId; // @synthesize hasId;
//- (void).cxx_destruct;    // IMP=0x000000010041dc71
- (void)addGroupUser:(id)arg1;    // IMP=0x000000010041d6ce
- (void)addGroupUserFromArray:(id)arg1;    // IMP=0x000000010041d5fb
- (void)addBlackList:(id)arg1;    // IMP=0x000000010041d521
- (void)addBlackListFromArray:(id)arg1;    // IMP=0x000000010041d44e
- (void)addGroupList:(id)arg1;    // IMP=0x000000010041d374
- (void)addGroupListFromArray:(id)arg1;    // IMP=0x000000010041d2a1
- (void)addWithUserList:(id)arg1;    // IMP=0x000000010041d1c7
- (void)addWithUserListFromArray:(id)arg1;    // IMP=0x000000010041d0f4
- (void)addCommentUserList:(id)arg1;    // IMP=0x000000010041d01a
- (void)addCommentUserListFromArray:(id)arg1;    // IMP=0x000000010041cf47
- (void)addLikeUserList:(id)arg1;    // IMP=0x000000010041ce6d
- (void)addLikeUserListFromArray:(id)arg1;    // IMP=0x000000010041cd9a
- (id)mergeFromCodedInputStream:(id)arg1;    // IMP=0x000000010041c633
- (int)serializedSize;    // IMP=0x000000010041bb32
- (void)writeToCodedOutputStream:(id)arg1;    // IMP=0x000000010041af81
- (BOOL)isInitialized;    // IMP=0x000000010041a971
@property(retain, nonatomic) NSMutableArray *groupUser; // @dynamic groupUser;
- (id)groupUserList;    // IMP=0x000000010041a8b8
@property(retain, nonatomic) NSMutableArray *blackList; // @dynamic blackList;
- (id)blackListList;    // IMP=0x000000010041a7c9
@property(retain, nonatomic) NSMutableArray *groupList; // @dynamic groupList;
- (id)groupListList;    // IMP=0x000000010041a686
@property(retain, nonatomic) NSMutableArray *withUserList; // @dynamic withUserList;
- (id)withUserListList;    // IMP=0x000000010041a57c
@property(retain, nonatomic) NSMutableArray *commentUserList; // @dynamic commentUserList;
- (id)commentUserListList;    // IMP=0x000000010041a48d
@property(retain, nonatomic) NSMutableArray *likeUserList; // @dynamic likeUserList;
- (id)likeUserListList;    // IMP=0x000000010041a39e
- (id)init;    // IMP=0x0000000100419fcf

@end

@interface ContactStorage : MMService

- (id)GetContact:(id)arg1;    // IMP=0x0000000100521b12
- (id)GetSelfContact;    // IMP=0x0000000100521af9

@end

@interface MMImageView : NSImageView

@end

@interface MMAvatarImageView : MMImageView

//@property(copy, nonatomic) CDUnknownBlockType didClickBlock;
//@property(copy, nonatomic) CDUnknownBlockType didDoubleClickBlock;

@end

@interface MMAvatarService : MMService

- (void)getAvatarImageWithUsername:(id)arg1 completion:(CDUnknownBlockType1)arg2;
- (void)getAvatarImageWithUrl:(id)arg1 completion:(CDUnknownBlockType1)arg2;
- (id)defaultAvatarImage;

@end

@interface MMURLHandler : NSObject

+ (instancetype)defaultHandler;
- (void)handleURL:(NSString *)url;

@end

@class MMPreviewPanel;

@protocol MMPreviewPanelDataSource <NSObject>
- (id)previewPanel:(MMPreviewPanel *)arg1 shareContentAtIndex:(long long)arg2;
- (id <QLPreviewItem>)previewPanel:(MMPreviewPanel *)arg1 previewItemAtIndex:(long long)arg2;
- (long long)numberOfPreviewItemsInPreviewPanel:(MMPreviewPanel *)arg1;
@end

@protocol MMPreviewPanelDelegate <NSObject>
- (void)previewPanelDidClose:(MMPreviewPanel *)arg1;
- (struct CGRect)previewPanel:(MMPreviewPanel *)arg1 sourceFrameOnScreenForPreviewItem:(id <QLPreviewItem>)arg2;
@end

@interface MMPreviewPanel : NSWindowController

@property(nonatomic) __weak id <MMPreviewPanelDataSource> dataSource;
@property(nonatomic) __weak id <MMPreviewPanelDelegate> delegate;

- (void)show;

@end

@interface MMCDNDownloadMgr : MMService

@end

@interface AppDelegate : NSObject

- (void)applicationDidFinishLaunching:(id)arg;

@end

@interface NSBundle (MacWeChatTimeLinePlugin)

+ (instancetype)pluginBundle;

@end

@interface MMExtDeviceControlCGI : NSObject

- (void)sendAppTerminatedCGIWithCompletion:(CDUnknownBlockType)arg1;

@end

@interface NewAuthResponse : PBGeneratedMessage

@property(readonly, nonatomic) BOOL hasApplyBetaUrl; // @synthesize hasApplyBetaUrl;

@end

#define kMMCGIWrapTimeLineFunctionId 211
#define kMMCGIWrapHomePageFunctionId 212

typedef NS_ENUM(NSUInteger, CBDataItemContentStyle) {
    CBDataItemContentStyleImage = 1,
    CBDataItemContentStyleLink = 3,
    CBDataItemContentStyleMusicLink = 4,
    CBDataItemContentStyleAppLink = 5
};

