/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import <Foundation/Foundation.h>

#import "RTCMacros.h"
#import "RTCRtcpParameters.h"
#import "RTCRtpCodecParameters.h"
#import "RTCRtpEncodingParameters.h"
#import "RTCRtpHeaderExtension.h"

NS_ASSUME_NONNULL_BEGIN

RTC_OBJC_EXPORT
@interface RTC_OBJC_TYPE(RTCRtpParameters) : NSObject

/** A unique identifier for the last set of parameters applied. */
@property(nonatomic, copy) NSString *transactionId;

/** Parameters used for RTCP. */
@property(nonatomic, readonly, copy) RTC_OBJC_TYPE(RTCRtcpParameters) * rtcp;

/** An array containing parameters for RTP header extensions. */
@property(nonatomic, readonly, copy)
    NSArray<RTC_OBJC_TYPE(RTCRtpHeaderExtension) *> *headerExtensions;

/** The currently active encodings in the order of preference. */
@property(nonatomic, copy) NSArray<RTC_OBJC_TYPE(RTCRtpEncodingParameters) *> *encodings;

/** The negotiated set of send codecs in order of preference. */
@property(nonatomic, copy) NSArray<RTC_OBJC_TYPE(RTCRtpCodecParameters) *> *codecs;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
