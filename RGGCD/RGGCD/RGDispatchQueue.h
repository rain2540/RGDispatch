//
//  RGDispatchQueue.h
//  RGGCD
//
//  Created by RAIN on 16/4/11.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    Concurrent,
    Serial,
    None
} DispatchQueueType;

@interface RGDispatchQueue : NSObject

@property (readonly, strong, nonatomic) dispatch_queue_t dispatchQueue;

- (instancetype)init;
- (instancetype)initWithQueueType:(DispatchQueueType)queueType;

+ (RGDispatchQueue *)mainQueue;
+ (RGDispatchQueue *)defaultGlobalQueue;
+ (RGDispatchQueue *)userInteractiveGlobalQueue;
+ (RGDispatchQueue *)utilityGlobalQueue;
+ (RGDispatchQueue *)backgroundGlobalQueue;
+ (RGDispatchQueue *)userInitiatedGlobalQueue;
+ (RGDispatchQueue *)unspecifiedGlobalQueue;

- (void)perform:(dispatch_block_t)performance;
- (void)performDelay:(int64_t)seconds
         performance:(dispatch_block_t)performance;

+ (void)performInMainQueue:(dispatch_block_t)performance;
+ (void)performInDefaultGlobalQueue:(dispatch_block_t)performance;
+ (void)performInUserInteractiveGlobalQueue:(dispatch_block_t)performance;
+ (void)performInUtilityGlobalQueue:(dispatch_block_t)performance;
+ (void)performInBackgroundGlobalQueue:(dispatch_block_t)performance;
+ (void)performInUserInitiatedGlobalQueue:(dispatch_block_t)performance;
+ (void)performInUnspecifiedGlobalQueue:(dispatch_block_t)performance;

+ (void)performInMainQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInDefaultGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInUserInteractiveGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInUtilityGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInBackgroundGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInUserInitiatedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;
+ (void)performInUnspecifiedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

@end
