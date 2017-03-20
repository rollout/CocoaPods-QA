//
//  RolloutMacros.h
//  Rollout
//
//  Created by Elad Cohen on 2/5/17.
//  Copyright © 2017 DeDoCo. All rights reserved.
//

#define createFeatureFlag(name) @property (nonatomic, assign) RolloutFeature* is##name##Enabled;
#define RolloutFeatureFlags [RolloutFeatureFlagsClass sharedInstance]
