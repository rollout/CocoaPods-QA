//
//  Rollout SDK version 0.14.1, Build 168
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

+(void) setupWithKey: (NSString*) rolloutKey debug: (BOOL) debug options:(RolloutOptions*)options __attribute__ ((deprecated));
+(void) setupWithKey: (NSString*) rolloutKey debug: (BOOL) debug __attribute__ ((deprecated));

@end

