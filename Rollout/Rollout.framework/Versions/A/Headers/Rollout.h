//
//  Rollout SDK version 0.14.1, Build 167
//
//  Copyright (c) 2014 Rollout.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RolloutOptions.h"

@interface Rollout : NSObject

+(void)setupWithKey:(NSString *)rolloutKey developmentDevice:(BOOL)developmentDevice options:(RolloutOptions*)options;
+(void)setupWithKey:(NSString *)rolloutKey developmentDevice: (BOOL)developmentDevice;
+(BOOL) rolloutDisabled;
+ (void)setRolloutDisabled:(BOOL)value;

@end

