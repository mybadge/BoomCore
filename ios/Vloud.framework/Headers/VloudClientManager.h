/***********************
auth: cszdlt@qq.com
date: 2020-03-27 15:36:35
name: VloudClientManager.h
************************/
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "RTCMacros.h"

#import "VloudClient.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * logging 等级
 */
typedef NS_ENUM(NSInteger, VloudLoggingLevel) {
  /// 最低级别的log，将会打印大量信息
  VloudLoggingLevelVerbose,
  /// debug 等级
  VloudLoggingLevelInfo,
  /// 警告信息
  VloudLoggingLevelWarning,
  /// 错误信息
  VloudLoggingLevelError,
  /// 不打印 log
  VloudLoggingLevelNone,
};

/**
 * 带宽不足时降低视频码率的策略
 */
typedef NS_ENUM(NSInteger, VloudVideoLowQualityType) {
  /// 带宽不足时，降低QP
  VloudVideoLowQualityTypeDisable,
  /// 带宽不足时，保持帧率不变，可能会降低分辨率及QP
  VloudVideoLowQualityTypeFrameRate,
  /// 带宽不足时，保持分辨率不变，可能会降低帧率及QP
  VloudVideoLowQualityTypeResolution,
  /// 带宽不足时，权衡帧率及分辨率，适当降低
  VloudVideoLowQualityTypeBalanced,
};

RTC_OBJC_EXPORT
@interface VloudClientManager : NSObject

+ (VloudClientManager *)instance;

+ (instancetype)alloc __attribute__((unavailable("call instance instead")));
+ (instancetype)new __attribute__((unavailable("call instance instead")));
- (instancetype)copy __attribute__((unavailable("call instance instead")));
- (instancetype)mutableCopy __attribute__((unavailable("call instance instead")));

/**
 * 设置 SDK 的 log 等级
 * @param level log 等级 @see <VloudLoggingLevel>
 */
- (void)setLoggingLevel:(VloudLoggingLevel) level;

/**
 * 设置带宽不足时降低视频码率的策略
 * @param type 降低视频码率选用的策略 @see <VloudVideoLowQualityType>
 */
- (void)setDefaultVideoAdapter:(VloudVideoLowQualityType) type;

/**
 * 初始化 SDK
 */
- (void)initGlobals;

/**
 * 释放 SDK 使用的资源
 */
- (void)uninitGlobals;

/**
 * 初始化 Client 相关资源，不初始化音视频资源
 */
- (void)initClient;

/**
 * 对应 initClient，释放 initClient 相关的资源
 */
- (void)uninitClient;

/**
 * 创建 VloudClient 的实例
 * @param url 需要连接的服务器 url
 * @param delegate VloudClient 的相关回调的委托
 * @return VloudCLient 的实例
 */
- (VloudClient *)create:(NSString *)url delegate:(__weak id<VloudClientDelegate>)delegate;

/**
 * 释放单例
 */
- (void)destroy;

/**
 * 销毁创建的 VloudClient 实例
 * @param client 需要被销毁的 VloudClient 的实例
 */
- (void)destroy:(VloudClient *)client;

/**
 * 音频通道切换
 * @param isMedia YES:媒体音量 NO:通话音量
 */
- (void)switch2MediaTransport:(BOOL)isMedia;

/**
 * 音频路由切换
 * 注意:该接口仅在通话音量模式下有效
 * @param portOverride 音频输出路由端口
 */
- (BOOL)setAudioRoute:(AVAudioSessionPortOverride)portOverride;

@end

NS_ASSUME_NONNULL_END
