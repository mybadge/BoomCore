//
//  ScreenCaptureKeys.h
//  BRTC-i
//
//  Created by DeskMac on 2020/12/29.
//  Copyright © 2020 BJY. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const DidSuccessCallbackIDKey;

FOUNDATION_EXPORT NSString *const UserIdKey;
FOUNDATION_EXPORT NSString *const RoomIdKey;
FOUNDATION_EXPORT NSString *const AppIdKey;
FOUNDATION_EXPORT NSString *const SignKey;

FOUNDATION_EXPORT NSString *const BandWidthKey;
FOUNDATION_EXPORT NSString *const WidthKey;
FOUNDATION_EXPORT NSString *const HeightKey;
FOUNDATION_EXPORT NSString *const FpsKey;
FOUNDATION_EXPORT NSString *const AdapterTypeKey;

FOUNDATION_EXPORT NSString *const AdapterType_Vloud_Value;
FOUNDATION_EXPORT NSString *const AdapterType_Trtx_Value;

FOUNDATION_EXPORT NSString *const IsLandScapeKey;


// 主App 发送
FOUNDATION_EXPORT NSString *const ScreenStartFromContainKey;
FOUNDATION_EXPORT NSString *const ScreenStopFromContainKey;

FOUNDATION_EXPORT NSString *const ScreenAdjustDirectionFromContainKey; // 控制设备方向


// 扩展App 回复
FOUNDATION_EXPORT NSString *const ScreenStartFromExtensionCallBackKey;
FOUNDATION_EXPORT NSString *const ScreenStopFromExtensionCallBackKey;


// 主App 回复
FOUNDATION_EXPORT NSString *const ScreenStartFromContainCallBackKey;
FOUNDATION_EXPORT NSString *const ScreenStopFromContainCallBackKey;

// 扩展App 发送
FOUNDATION_EXPORT NSString *const ScreenStartFromExtensionKey;
FOUNDATION_EXPORT NSString *const ScreenStopFromExtensionKey;
