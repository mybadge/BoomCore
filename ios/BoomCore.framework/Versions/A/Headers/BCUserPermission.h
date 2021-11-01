//
//  BCUserPermission.h
//  BoomCore
//
//  Created by zhaozhidan on 2020/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 默认权限
#define BCUserPermissionDefault @"RWPSAV"

/**
 * R read
 * W write
 * P publish
 * S subscribe
 * A audio
 * V video
 * M manage
 * O own
 */
@interface BCUserPermission : NSObject

@property(nonatomic, assign) BOOL hasRead;

@property(nonatomic, assign) BOOL hasWrite;

@property(nonatomic, assign) BOOL hasPublish;

@property(nonatomic, assign) BOOL hasSubscribe;

@property(nonatomic, assign) BOOL hasManage;

@property(nonatomic, assign) BOOL hasAudio;

@property(nonatomic, assign) BOOL hasVideo;

@property(nonatomic, assign) BOOL hasOwn;

@property(nonatomic, copy) NSString *permissionStr;

- (instancetype)initWithString:(NSString *)permissionStr;

- (instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
