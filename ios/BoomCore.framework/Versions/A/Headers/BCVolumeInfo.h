//
//  BCVolumeInfo.h
//  BoomCore
//
//  Created by zhaozhidan on 2021/2/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 音量大小
 *
 * 表示语音音量的评估大小，通过这个数值，您可以在 UI 界面上用图标表征 userId 是否有在说话
 */
@interface BCVolumeInfo : NSObject <NSCopying>
/// 说话者的 userId, nil 为自己
@property (strong, nonatomic, nullable) NSString *userId;
@property (strong, nonatomic, nullable) NSString *streamId;
/// 说话者的音量, 取值范围0 - 100
@property (assign, nonatomic) NSUInteger volume;

@end

NS_ASSUME_NONNULL_END
