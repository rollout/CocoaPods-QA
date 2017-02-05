//
//  RolloutFeatureFlagsClass.m
//  Rollout
//
//  Created by Elad Cohen on 2/5/17.
//  Copyright © 2017 DeDoCo. All rights reserved.
//

#ifndef RolloutFeatureFlagsClass_impl
#define RolloutFeatureFlagsClass_impl 1
#import <Foundation/Foundation.h>

@implementation RolloutFeatureFlagsClass

+(instancetype)sharedInstance {
    static RolloutFeatureFlagsClass *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[RolloutFeatureFlagsClass alloc] init];
    });
    return sharedInstance;
}

@end
#endif
