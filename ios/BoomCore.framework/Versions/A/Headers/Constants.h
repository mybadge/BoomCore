//
//  Constants.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/15.
//  Copyright © 2020 boommeeting. All rights reserved.
//

typedef NS_ENUM(NSInteger, BCBusLocationType) {
    BCBusLocationTypeChina = 1, // 国内用户
    BCBusLocationTypeForeign = 2, // 国外用户
};

/** Video display mode. */
typedef NS_ENUM(NSUInteger, BCVideoRenderMode) {
    BCVideoRenderModeFit = 0,
    BCVideoRenderModeFill = 1,
};

/** Video mirror mode. */
typedef NS_ENUM(NSUInteger, BCVideoMirrorMode) {
    BCVideoMirrorModeEnabled = 0,
    BCVideoMirrorModeDisabled = 1,
};

/** User Offline Reason. */
typedef NS_ENUM(NSUInteger, BCUserOfflineReason) {
    BCUserOfflineReasonQuit = 0,
    BCUserOfflineReasonDropped = 1,
};

/** Connection State Type. */
typedef NS_ENUM(NSUInteger, BCConnectionStateType) {
    BCConnectionStateDisconnected = 0,
    BCConnectionStateConnecting = 1,
    BCConnectionStateConnected = 2,
    BCConnectionStateReconnecting = 3,
    BCConnectionStateFailed = 4,
};

/** The Reason Of State Changed. */
typedef NS_ENUM(NSUInteger, BCConnectionChangedReason) {
    BCConnectionChangedConnecting = 0,
    BCConnectionChangedJoinSuccess = 1,
    BCConnectionChangedInterrupted = 2,
    BCConnectionChangedBannedByServer = 3,
    BCConnectionChangedJoinFailed = 4,
    BCConnectionChangedInvalidAppId = 5,
    BCConnectionChangedInvalidRoom = 6,
    BCConnectionChangedInvalidToken = 7,
    BCConnectionChangedTokenExpired = 8,
    BCConnectionChangedRejectedByServer = 9,
    BCConnectionChangedRenewToken = 10,
    BCConnectionChangedClientIpAddressChanged = 11,
    BCConnectionChangedKeepAliveTimeout = 12,
};

typedef NS_ENUM(NSUInteger, BCStreamConnectionState) {
    BCStreamConnectionStateInited,
    BCStreamConnectionStateConnecting,
    BCStreamConnectionStateFailed,
    BCStreamConnectionStateDisconnected,
    BCStreamConnectionStateConnected,
    BCStreamConnectionStateClosed,
};

/**
 * 视频宽高比模式
 *
 * - 横屏分辨率：BRTCVideoResolution_640_360 + BRTCVideoResolutionModeLandscape = 640 × 360
 * - 竖屏分辨率：BRTCVideoResolution_640_360 + BRTCVideoResolutionModePortrait  = 360 × 640
 */
typedef NS_ENUM(NSInteger, BCVideoResolutionMode) {
    BRTCVideoResolutionModePortrait  = 0,  ///< 竖屏分辨率
    BRTCVideoResolutionModeLandscape = 1,  ///< 横屏分辨率
};

/**
 * FPS 等级
 */
typedef NS_ENUM(NSInteger, BCVideoFPS) {
    BRTCVideoFPS_7                  = 0,
    BRTCVideoFPS_10                 = 1,
    BRTCVideoFPS_15                 = 2,
    BRTCVideoFPS_30                 = 3,
};



// local error check
#define BC_ERROR_INVALID_DELEGATE                           3000    // 业务上返回对应的NUmber
#define BC_ERROR_INVALID_RTC                                3001    // 业务上返回对应的NUmber
#define BC_ERROR_INVALID_APPID                              3002
#define BC_ERROR_INVALID_URI_TYPE                           3003
#define BC_ERROR_INVALID_USER_TOKEN                         3004
#define BC_ERROR_INVALID_ROOMID                             3005
#define BC_ERROR_INVALID_USER                               3006
#define BC_ERROR_INVALID_USERID                             3007
#define BC_ERROR_INVALID_USERNAME                           3008
#define BC_ERROR_INVALID_PUBLISH_STREAMID                   3009
#define BC_ERROR_INVALID_UNPUBLISH_STREAMID                 3010
#define BC_ERROR_INVALID_SUBSCRIBE_STREAMID                 3011
#define BC_ERROR_INVALID_UNSUBSCRIBE_STREAMID               3012
#define BC_ERROR_INVALID_ADD_STREAM_CANVAS_STREAMID         3013
#define BC_ERROR_INVALID_ADD_STREAM_CANVAS_CANVAS           3014
#define BC_ERROR_INVALID_REMOVE_STREAM_CANVAS_STREAMID      3015
#define BC_ERROR_INVALID_REMOVE_STREAM_CANVAS_CANVAS        3016
#define BC_ERROR_INVALID_MUTE_AUDIO_STREAMID                3017
#define BC_ERROR_INVALID_MUTE_AUDIO_MUTE                    3018
#define BC_ERROR_INVALID_MUTE_VIDEO_STREAMID                3019
#define BC_ERROR_INVALID_MUTE_VIDEO_MUTE                    3020
#define BC_ERROR_INVALID_GET_USERINFO_USERID                3021
#define BC_ERROR_INVALID_GET_USERSTREAMS_USERID             3022
#define BC_ERROR_INVALID_GET_STREAMINFO_STREAMID            3023
#define BC_ERROR_INVALID_RENEW_TOKEN                        3024

// remote error code
#define BC_ERROR_UNKNOWN                                    2000
#define BC_ERROR_PERMISSION_DENIED                          2001
#define BC_ERROR_INVALID_URI                                2002
#define BC_ERROR_SOCKET_NOT_READY                           2003
#define BC_ERROR_SOCKET_CONNECT_FAILED                      2004
#define BC_ERROR_PEERCONNECTION                             2005
#define BC_ERROR_ICE_FAILED                                 2006
#define BC_ERROR_PEERCONNECTION_NOT_FOUNT                   2007
#define BC_ERROR_STREAM_MEDIA                               2008
#define BC_ERROR_RESET_STREAM                               2009
#define BC_ERROR_ADD_LOCAL_STREAM                           2010
#define BC_ERROR_SERVER_NOT_RESPONDING                      2011
#define BC_ERROR_SESSION_CLOSE                              2012

