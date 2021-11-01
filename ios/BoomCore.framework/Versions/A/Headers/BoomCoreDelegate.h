//
//  BoomCoreDelegate.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/14.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import "Constants.h"

NS_ASSUME_NONNULL_BEGIN

@class BCRoomInfo;
@class BCStream;
@class BCUser;
@class BCMessageInfo;
@class BCStatsReport;
@class BCVolumeInfo;

@protocol BoomCoreDelegate <NSObject>
@optional


#pragma --mark room callback
/// 加入房间成功
/// @param roomId 加入房间的ID
/// @param user 本地用户的
/// @param roomInfo 房间信息
// TODO:扩展性考虑，回掉都是object
- (void)didJoinedRoom:(NSString *)roomId user:(BCUser *)user roomInfo:(BCRoomInfo *_Nullable)roomInfo;


/// 其他用户加入房间的回调
/// @param roomId 加入房间的ID
/// @param users 房间内的用户列表
- (void)didUserJoined:(NSString *)roomId users:(NSArray<BCUser *> *)users;


/// 用户离开房间的回调
/// @param roomId 房间的ID
/// @param users 新离开房间的用户的列表
- (void)didUserLeaved:(NSString *)roomId users:(NSArray<BCUser *> *)users;

/// 用户踢人的回调.
- (void)didEvictedForRoomId:(NSString *)roomId userId:(NSString *)userId;

/// 当前用户在其他地方加入了当前房间时，会回调此方法（当前用户被顶掉了）
- (void)didUserReJoined:(NSString *)roomId user:(BCUser *)user;

/// 当前房间关闭时，会调用此方法
/// @param roomId 关闭的房间
- (void)didRoomClosedForRoomId:(NSString *)roomId;

/// 本地用户推流的回调
/// @param roomId 房间 id
/// @param stream 流信息
- (void)didLocalStreamPublished:(NSString *)roomId stream:(BCStream *)stream;


/// 其他用户推流的回调
/// @param roomId 房间 id
/// @param streams 新推流的流列表
- (void)didRemoteStreamPublished:(NSString *)roomId streams:(NSArray<BCStream *> *)streams;


/// 其他用户取消推流的回调
/// @param roomId 房间 id
/// @param stream 新取消推流
- (void)didRemoteStreamUnpublished:(NSString *)roomId stream:(BCStream *)stream;


/// 流状态改变之后  stream如果为空表示为本地流  audioStatusChange
- (void)didStreamStateChange:(BCStream *)stream enableAudio:(BOOL)enableAudio enableVideo:(BOOL)enableVideo;

/// 流连接状态改变了.  可以监听到流是否拉到了.
- (void)didRemoteStream:(BCStream *)stream connectionChange:(BCStreamConnectionState)newState;

/// 流信息状态.
- (void)didStream:(BCStream *)stream didStatsReport:(BCStatsReport *)statsReport;


/// 错误回掉
/// @param errorCode 回掉的错误码
/// @param message 错误的内容
- (void)onError:(int)errorCode message:(NSString *)message;

/// 用户掉线了
/// @param uid 用户id
/// @param reason 掉线的原因
- (void)didOfflineOfUid:(NSUInteger)uid reason:(BCUserOfflineReason)reason;

/// 连接状态发生改变
/// @param state 此时的网络状态
/// @param reason 状态发生变化的原因
- (void)connectionChangedToState:(BCConnectionStateType)state reason:(BCConnectionChangedReason)reason;


/// 用户丢失连接了
- (void)rtConnectionDidLost;


/// token即将过期
/// @param token 用户token
- (void)tokenPrivilegeWillExpire:(NSString *)token;


/// token已经过期，需要重新请求token
- (void)rtcRequestToken;




#pragma --mark room delegate
/// 收到房间广播
- (void)onMessageForRoomId:(NSString *)roomId info:(BCMessageInfo *)info;

/// 调用 [VloudClient getMessageListForStartSeq:endSeq:] 完成后，会调用一次此方法
/// @param roomId 当前房间的 ID
/// @param infos 消息列表的信息
- (void)onMessageListForRoomId:(NSString *)roomId infos:(NSArray<BCMessageInfo *> *)infos;

/// 收到房间信息改变的通知
- (void)onStatsChangeForRoomId:(NSString *)roomId roomState:(BCRoomInfo *)roomInfo;

/// 收到用户信息改变的通知
- (void)onUpdateUserForUserId:(NSString *)userId user:(BCUser *)user;

/// 主持人改变了的通知
- (void)onMasterChangeForRoomId:(NSString *)roomId masterId:(NSString *)masterId;


- (void)roomDidReConnect;
- (void)roomDidReConnectFailed;

- (void)roomDidConnect;

- (void)roomDidConnectFailed:(NSInteger)code message:(NSString *)msg;

- (void)roomDidDisConnect;


/**
 * 用于提示音量大小的回调,包括每个 userId 的音量和远端总音量
 *
 * 您可以通过调用 BRTC 中的 enableAudioVolumeEvaluation 接口来开关这个回调或者设置它的触发间隔。
 * 需要注意的是，调用 enableAudioVolumeEvaluation 开启音量回调后，无论频道内是否有人说话，都会按设置的时间间隔调用这个回调;
 * 如果没有人说话，则 userVolumes 为空，totalVolume 为0。
 *
 * @param userVolumes 所有正在说话的房间成员的音量，取值范围0 - 100。
 * @param totalVolume 所有远端成员的总音量, 取值范围0 - 100。
 * @note userId 为 nil 时表示自己的音量，userVolumes 内仅包含正在说话（音量不为0）的用户音量信息。
 */
- (void)onUserVoiceVolume:(NSArray<BCVolumeInfo *> *)userVolumes totalVolume:(NSInteger)totalVolume;


#pragma mark - 屏幕分享相关
/**
 * 当屏幕分享开始时，SDK 会通过此回调通知
 */
- (void)onScreenCaptureStarted;

/**
 * 当屏幕分享暂停时，SDK 会通过此回调通知
 *
 * @param reason 原因，0：用户主动暂停；1：屏幕窗口不可见暂停
 */
- (void)onScreenCapturePaused:(int)reason;

/**
 * 当屏幕分享恢复时，SDK 会通过此回调通知
 *
 * @param reason 恢复原因，0：用户主动恢复；1：屏幕窗口恢复可见从而恢复分享
 */
- (void)onScreenCaptureResumed:(int)reason;

/**
 * 当屏幕分享停止时，SDK 会通过此回调通知
 *
 * @param reason 停止原因，0：用户主动停止；1：屏幕窗口关闭导致停止  2: 其他异常原因
 */
- (void)onScreenCaptureStoped:(int)reason;

@end

NS_ASSUME_NONNULL_END
