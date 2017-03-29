
#import <Foundation/Foundation.h>
#import <Rollout/Rollout.h>

#define RolloutFeatureFlags [RolloutFeatureFlagsClass sharedInstance]

// This class will hold your Rollout's feature flags
@interface RolloutFeatureFlagsClass : NSObject

+(instancetype)sharedInstance;

/*
 * Put your feature flags here: 
 
 e.g. 
 Define here:
     @property (nonatomic, assign) RolloutFeature* myFeatureName;
 
 Use:
    [RolloutFeatureFlags.myFeatureName enabled:^{
        // enabled code here
    }];
 */

@end


