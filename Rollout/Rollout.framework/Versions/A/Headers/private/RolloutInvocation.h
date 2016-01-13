//
// Created by Sergey Ilyevsky on 6/25/15.
// Copyright (c) 2015 DeDoCo. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RolloutTypeWrapper;
@class RolloutConfiguration;
@class RolloutInvocationsListFactory;
@class RolloutTweakId;
@class RolloutDeviceProperties;
@class RolloutInvocationContext;


@interface RolloutInvocation : NSObject
- (instancetype)initWithConfiguration:(RolloutConfiguration *)configuration listsFactory:(RolloutInvocationsListFactory *)listsFactory deviceProperties:(RolloutDeviceProperties *)deviceProperties;

- (RolloutTypeWrapper *)invokeWithContext:(RolloutInvocationContext *)context originalMethodWrapper:(RolloutTypeWrapper *(^)(NSArray *))originalMethodWrapper;

@property (nonatomic) BOOL rolloutDisabled;

@end
