/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifdef WEBRTC_H264_SIMULCAST
#import <Foundation/Foundation.h>

#import "RTCMacros.h"
#import "RTCVideoEncoder.h"
#import "base/RTCVideoCodecInfo.h"

RTC_OBJC_EXPORT
@interface RTC_OBJC_TYPE(RTCVideoEncoderH264Software) : NSObject

/* This returns a VP8 encoder that can be returned from a RTCVideoEncoderFactory injected into
 * RTCPeerConnectionFactory. Even though it implements the RTCVideoEncoder protocol, it can not be
 * used independently from the RTCPeerConnectionFactory.
 */
+ (id<RTC_OBJC_TYPE(RTCVideoEncoder)>)h264Encoder:(RTC_OBJC_TYPE(RTCVideoCodecInfo) *)info;

@end
#endif