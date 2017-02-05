//
//  RolloutMacros.h
//  Rollout
//
//  Created by Elad Cohen on 2/5/17.
//  Copyright © 2017 DeDoCo. All rights reserved.
//

#ifndef RolloutMacros_h
#define RolloutMacros_h

#define createFeatureFlag(name) @property (nonatomic, assign) BOOL is##name##Enabled;
#define RolloutFeatureFlags [RolloutFeatureFlagsClass sharedInstance]

#endif /* RolloutMacros_h */
