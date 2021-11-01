/***********************
auth: cszdlt@qq.com
date: 2020-03-30 15:11:43
name: VloudCapture.h
************************/

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>

#import "VloudCapture.h"

#import "RTCMacros.h"

NS_ASSUME_NONNULL_BEGIN

RTC_OBJC_EXPORT
@interface VloudCameraVideoCapturer : NSObject<VloudVideoCapture>

// Capture session that is used for capturing. Valid from initialization to dealloc.
@property(readonly, nonatomic) AVCaptureSession *captureSession;

// Returns list of available capture devices that support video capture.
+ (NSArray<AVCaptureDevice *> *)captureDevices;
// Returns list of formats that are supported by this class for this device.
+ (NSArray<AVCaptureDeviceFormat *> *)supportedFormatsForDevice:(AVCaptureDevice *)device;

- (instancetype) init;

- (void)switchCamera; 

- (void)setVideoCapturerDelegate:(id<VloudVideoCapturerDelegate> __nullable)delegate;
- (void)startCaptureWithWidth:(NSInteger)width
                       height:(NSInteger)height
                          fps:(NSInteger)fps;
- (BOOL)startCapture;

- (void)stopCapture;

- (void)sendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer changeRotation:(NSNumber *)changeRotation;
- (void)setFrontCamera:(BOOL)isFront;

@end
NS_ASSUME_NONNULL_END
