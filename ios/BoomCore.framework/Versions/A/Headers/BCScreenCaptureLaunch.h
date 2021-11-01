//
//  BCScreenCaptureLaunch.h
//  BoomCore
//
//  Created by zhaozhidan on 2021/2/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BCScreenCaptureLaunch : NSObject
+ (instancetype)sharedInstance;
- (void)launchWithBundleID:(NSString *)bundleID;

@end

NS_ASSUME_NONNULL_END
