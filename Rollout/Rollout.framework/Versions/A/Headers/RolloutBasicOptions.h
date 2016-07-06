//
//  RolloutBasicOptions.h
//  Rollout
//
//  Created by Hezi Cohen on 6/26/16.
//  Copyright © 2016 DeDoCo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

FOUNDATION_EXPORT char** RolloutBasicOptions_blockedInJSClasses;
FOUNDATION_EXPORT NSUInteger RolloutBasicOptions_blockedInJSClasses_count;

FOUNDATION_EXPORT char** RolloutBasicOptions_patchingDisabledClasses;
FOUNDATION_EXPORT NSUInteger RolloutBasicOptions_patchingDisabledClasses_count;

void Rollout_setupDisabledClassesList(NSArray *classes);
void Rollout_setupBlockedClassesList(NSArray *classes);

bool Rollout_shouldPatchClass(Class clazz);
bool Rollout_shouldAllowBoxing(Class clazz);
