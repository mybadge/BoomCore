/***********************
auth: cszdlt@qq.com
date: 2020-03-21 18:05:16
name: VloudStream.h
************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

#import "RTCMacros.h"
#import "RTCVideoRenderer.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum VloudStreamConnectionState : NSInteger VloudStreamConnectionState;
enum VloudStreamConnectionState : NSInteger {
  VloudStreamInited,
  VloudStreamConnecting,
  VloudStreamFailed,
  VloudStreamDisconnected,
  VloudStreamConnected,
  VloudStreamClosed,
};

@class VloudStream;
@class VloudStatsReport;
@class VloudStreamConfig;
@class VloudVideoRenderer;
@protocol VloudVideoCapture;

RTC_OBJC_EXPORT
@protocol VloudStreamDelegate <NSObject>
@optional

/**
 * 当前流的视频轨准备好时，该函数被调用
 * @param vloudStream 准备好视频轨的 VloudStream
 */
- (void)vloudStreamDidAddVideoTrack:(VloudStream *)vloudStream;

/**
 * 当前流的视频轨被移除时，该函数被调用
 * @param vloudStream 被移除了视频轨的 VloudStream
 */
- (void)vloudStreamDidRemoveVideoTrack:(VloudStream *)vloudStream;

/**
 * 当前流的音频轨准备好时，该函数被调用
 * @param vloudStream 准备好音频轨的 VloudStream
 */
- (void)vloudStreamDidAddAudioTrack:(VloudStream *)vloudStream;

/**
 * 当前流的音频轨被移除时，该函数被调用
 * @param vloudStream 被移除了音频轨的 VloudStream
 */
- (void)vloudStreamDidRemoveAudioTrack:(VloudStream *)vloudStream;

/**
 * 当前流的音视频状态发生变化时，该函数被调用
 * @param vloudStream 状态发生变化的 VloudStream
 * @param enableAudio 是否启用音频
 * @param enableVideo 是否启用视频
 */
- (void)vloudStream:(VloudStream *)vloudStream
    didAudioStateChange:(BOOL)enableAudio
    didVideoStateChange:(BOOL)enableVideo;

/**
 * 当前流的连接状态变化时，该函数被调用
 * @param vloudStream 状态发生变化的 VloudStream
 * @param newState 变化后的状态
 */
- (void)vloudStream:(VloudStream *)vloudStream
    connectionChange:(VloudStreamConnectionState)newState;

/**
 * 启用 [VloudClient statisticsStatus:delay:updateInterval:]
 * 并调用 [VloudStream startReportStatus] 方法后，会定期调用该函数
 * @param vloudStream 获取信息的 VloudStream
 * @param statsReport VloudStream 流的信息
 */
- (void)vloudStream:(VloudStream *)vloudStream didStatsReport:(VloudStatsReport *)statsReport;

/**
 * 当前流的转推流状态变化时，该函数被调用
 * @param vloudStream 状态发生变化的 VloudStream
 * @param bridge 是否开启转推流
 */
- (void)vloudStream:(VloudStream *)vloudStream didBridgeStateChange:(BOOL)bridge;

@end

RTC_OBJC_EXPORT
@interface VloudStream : NSObject
+ (VloudStream *)create:(VloudStreamConfig *)config;

/// 用于接收 VloudStream 事件回调
@property(nonatomic, weak, nullable) id<VloudStreamDelegate> delegate;

/// 当前流所在的房间
@property(nonatomic, readonly) NSString *roomId;

/// 当前流所属用户
@property(nonatomic, readonly) NSString *userId;

/// 当前流的 ID
@property(nonatomic, readonly) NSString *streamId;

/// 当前流的配置信息
@property(nonatomic, copy) VloudStreamConfig *config;

/// 是否开启音频，更改该属性会设置音频状态
@property(nonatomic, assign) BOOL enableAudio;

/// 是否开启视频，更改该属性会设置视频状态
@property(nonatomic, assign) BOOL enableVideo;

/// 是否是本地流
@property(nonatomic, readonly) BOOL isLocal;

/// 当前流是否含有音频
@property(nonatomic, readonly) BOOL hasAudio;

/// 当前流是否含有视频
@property(nonatomic, readonly) BOOL hasVideo;

/// 当前流是否为推流镜像
@property(nonatomic, readonly) BOOL isMirror;

/// 当前流的转推流地址
@property(nonatomic, readonly) NSString *bridgeUrl;

- (instancetype)init NS_UNAVAILABLE;

/**
 * 设置视频源
 * @param capture 视频源
 */
- (void)setVideoCaptrue:(id<VloudVideoCapture>)capture;

/**
 * 添加当前流的渲染 View
 * @param renderer @see <VloudVideoRenderer>
 */
- (void)addRenderer:(VloudVideoRenderer *)renderer;

/**
 * 为当前流移除视频渲染 View
 * @param renderer @see <VloudVideoRenderer>
 */
- (void)removeRenderer:(VloudVideoRenderer *)renderer;

/**
 * 设置当前流的音频音量
 * @param volume 设置的音量值，范围为0~10
 */
- (void)setAudioVolume:(double)volume;

/**
 * 设置采集的音量
 * @param volume 设置的音量值，范围为0~100
 */
- (void)setRecordVolume:(int)volume;

/**
 * 读取采集音量值
 */
- (int)recordVolume;

/**
 * 开始获取当前流状态的信息，该信息会通过 [VloudStreamDelegate vloudStream:didStatsReport:] 方法回调
 */
- (void)startReportStatus;

/**
 * 停止获取流状态的信息
 */
- (void)stopReportStatus;

/**
 * 开始转推流
 * @param url 转推流地址
 * @param delay 转推流的延迟，单位是毫秒
 */
- (void)startBridge:(NSString *)url delay:(NSInteger)delay;

/**
 * 开始转推流
 * @param url 转推流地址
 * @param delay 转推流的延迟，单位是毫秒
 * @param interval 转推流的关键帧间隔，单位是毫秒
 */
- (void)startBridge:(NSString *)url delay:(NSInteger)delay interval:(NSInteger)interval;

/**
 * 推流镜像
 * @param isMirror 是否推流镜像
 */
- (void)adjustMirror:(BOOL)isMirror;

/**
 * 停止转推流
 */
- (void)stopBridge;

/**
 * 开启预览
 */
- (void)previewCapture;

/**
 * 关闭预览
 */
- (void)unPreviewCapture;

/**
 * 调用该方法的 VloudStream 是本地流时，推送本地流
 */
- (void)publish;

/**
 * 调用该方法的 VloudStream 是本地流时，停止推送本地流
 */
- (void)unPublish;

/**
 * 调用该方法的 VloudStream 是本地流时，停止推送本地流
 * @param unPreview 取消推流时是否不保留预览 
 */
- (void)unPublishWithUnPreview:(BOOL)unPreview;

/**
 * 调用该方法的 VloudStream 是远端流时，拉取远端流
 */
- (void)subscribe;

/**
 * 调用该方法的 VloudStream 是远端流时，停止拉取远端流
 */
- (void)unsubscribe;

/**
 * 切换当前流的视频流
 * @param index 视频流的索引，索引从0开始。视频流根据索引，从低分辨率到高分辨率递增。
 * 视频流的数量可通过 VloudStreamConfig.videoStreamCount 属性获取
 */
- (void)toggleVideoStream:(NSInteger)index;

/**
 * 添加图片水印
 *
 * @param logoId   水印 id，用于替换或者移除水印
 * @param image    UIImage 对象
 * @param left     水印打印位置的左坐标点
 * @param top      水印打印位置的上坐标点
 * @param alpha    水印透明度 0 ~ 1.0
 */
- (void)addImageLogoWithId:(NSString *_Nonnull)logoId
                     image:(UIImage *)image
                      left:(int)left
                       top:(int)top
                     alpha:(double)alpha;

/**
 * 添加图片水印
 *
 * @param logoId      水印 id，用于替换或者移除水印
 * @param image       UIImage 对象
 * @param left        水印打印位置的左坐标点
 * @param top         水印打印位置的上坐标点
 * @param scaleWidth  水印图片缩放的宽度
 * @param scaleHeight 水印图片缩放的高度
 * @param alpha       水印透明度 0 ~ 1.0
 */
- (void)addImageLogoWithId:(NSString *_Nonnull)logoId
                     image:(UIImage *)image
                      left:(int)left
                       top:(int)top
                scaleWidth:(int)scaleWidth
               scaleHeight:(int)scaleHeight
                     alpha:(double)alpha;


/**
 * 添加文字水印
 *
 * @param logoId    水印 id，用于替换或者移除水印
 * @param text      <p>水印文字内容，支持添加时间戳。需要添加时间戳时，文本内需带有 "${timestamp:{format}}" 字样。</p>
 *                  <p>{format} 内容请参考 strftime 函数： http://www.cplusplus.com/reference/ctime/strftime/</p>
 *                  <p>例如: ${timestamp:%Y-%m-%d %H:%M:%S} </p>
 * @param path      <p>字体文件的路径，如该参数为nil，则使用 SDK 内附带的思源开源可商用字体：
 *                  https://github.com/adobe-fonts/source-han-sans/blob/release/SubsetOTF/CN/SourceHanSansCN-Regular.otf</p>
 *                  <p>注意：如该路径的字体有问题，则可能导致崩溃!!!</p>
 * @param left      水印打印位置的左坐标点
 * @param top       水印打印位置的上坐标点
 * @param color     水印文字的颜色
 * @param size      水印文字的大小
 * @param alpha     水印文字的透明度
 */
- (void)addTextLogoWithId:(NSString *_Nonnull)logoId
                     text:(NSString *)text
                     path:(NSString *)path
                     left:(int)left
                      top:(int)top
                    color:(int)color
                     size:(int)size
                    alpha:(double)alpha;

/**
 * 删除水印
 *
 * @param id 需要删除的水印的 id
 */
- (void)removeLogoWithId:(NSString *_Nonnull)logoId;

- (void)resetAudioModule;

/**
 * 当前流是本地流时，销毁
 */
- (void)destroy;


@end

NS_ASSUME_NONNULL_END
