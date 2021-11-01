//
//  BCStatistics.h
//  BoomCore
//
//  Created by zhaozhidan on 2020/12/10.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


@interface BCStatsBandWidth : NSObject
@property(nonatomic, assign) long long upload;
@property(nonatomic, assign) long long download;

- (NSString *)description;
@end


@interface BCStatsBitrateData : NSObject
@property(nonatomic, assign) double upload;
@property(nonatomic, assign) double download;

- (NSString *)description;
@end


@interface BCStatsBitrate : NSObject
@property(nonatomic, strong) BCStatsBitrateData *total;
@property(nonatomic, strong) BCStatsBitrateData *audio;
@property(nonatomic, strong) BCStatsBitrateData *video;

- (NSString *)description;
@end


@interface BCStatsPacketLoss : NSObject
@property(nonatomic, assign) double total;
@property(nonatomic, assign) double audioUpload;
@property(nonatomic, assign) double audioDownload;
@property(nonatomic, assign) double videoUpload;
@property(nonatomic, assign) double videoDownload;

- (NSString *)description;
@end


@interface BCStatsResolution : NSObject
@property(nonatomic, assign) long long width;
@property(nonatomic, assign) long long height;

- (NSString *)description;
@end


@interface BCStatsTransport : NSObject
@property(nonatomic, copy) NSString *localAddress;
@property(nonatomic, copy) NSString *remoteAddress;
@property(nonatomic, copy) NSString *transportType;
@property(nonatomic, copy) NSString *localCandidateType;
@property(nonatomic, copy) NSString *remoteCandidateType;
@property(nonatomic, copy) NSString *networkType;
@property(nonatomic, assign) long long RTT;

- (NSString *)description;
@end


@interface BCStatsQualityData : NSObject
@property(nonatomic, copy) NSString *codec;
@property(nonatomic, assign) long long ssrc;
@property(nonatomic, assign) int nacks;
@property(nonatomic, assign) int plis;
@property(nonatomic, assign) int firs;
@property(nonatomic, assign) int delay;
@property(nonatomic, assign) long long jitter;

- (NSString *)description;
@end


@interface BCStatsQuality : NSObject
@property(nonatomic, strong) BCStatsQualityData *audio;
@property(nonatomic, strong) BCStatsQualityData *video;

- (NSString *)description;
@end


@interface BCStatsStatisticsData : NSObject
@property(nonatomic, assign) long long bytesReceived;
@property(nonatomic, assign) long long bytesSent;
@property(nonatomic, assign) long long packetsReceived;
@property(nonatomic, assign) long long packetsSent;

- (NSString *)description;
@end


@interface BCStatsStatistics : NSObject
@property(nonatomic, strong) BCStatsStatisticsData *audio;
@property(nonatomic, strong) BCStatsStatisticsData *video;

- (NSString *)description;
@end


@interface BCStatsReport : NSObject

@property(nonatomic, strong) BCStatsBandWidth *bandwidth;
@property(nonatomic, strong) BCStatsBitrate *bitrate;
@property(nonatomic, strong) BCStatsPacketLoss *packetLoss;
@property(nonatomic, strong) BCStatsResolution *resolution;
@property(nonatomic, strong) BCStatsQuality *quality;
@property(nonatomic, assign) long long framerate;
@property(nonatomic, assign) double avgAudioLevel;
@property(nonatomic, assign) double audioLevel;
/**
 * BCStatsTransport 数组
 */
@property(nonatomic, strong) NSArray<BCStatsTransport *> *transports;
@property(nonatomic, strong) BCStatsStatistics *statistics;
- (NSArray *)streamDebugInfo:(BCStatsReport *)report nickname:(NSString *)nickname streamId:(NSString *)streamId isLocal:(BOOL)isLocal;
- (NSString *)description;

@end

NS_ASSUME_NONNULL_END

