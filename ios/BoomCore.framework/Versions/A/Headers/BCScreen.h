//
//  BCScreen.h
//  BoomCore
//
//  Created by zhaozhidan on 2021/2/24.
//

#import <Foundation/Foundation.h>
#import "BoomCore.h"
@class BCConfig;
@class BCJoinConfig;
@class BCPublishConfig;
#import "Constants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BCScreenDelegate <NSObject>
@optional
- (void)screenRemoteStreamAdded;
- (void)screenRemoteStreamRemoved;
- (void)screenRemoteLeave;
- (void)screenError:(int)code message:(NSString *)message;
- (void)screenChannelConnected;
- (void)screenChannelConnectFailed:(int)code message:(NSString *)message;
- (void)screenChannelDisconnected:(BOOL)manual_close;
- (void)screenChannelReconnectComplete:(BOOL)has_change;
- (void)screenChannelReconnectFailed;
- (void)screenIceConnectionChanged:(BCStreamConnectionState)state;
@end


@interface BCScreen : NSObject

- (instancetype)initWithDelegate:(id<BoomCoreDelegate>)delegate screenDelegate:(id<BCScreenDelegate>)screenDelegate appGroupIndentifier:(NSString *)appGroupIndentifier launchBundleID:(NSString *)launchBundleID;

- (void)joinChannel:(NSString *)uri joinConfig:(BCJoinConfig *)joinConfig publishConfig:(BCPublishConfig *)publishConfig;

- (void)publishAudioEnable:(BOOL)enable;
- (int)stopScreenCapture;

- (void)leaveChannel;
@end

NS_ASSUME_NONNULL_END
