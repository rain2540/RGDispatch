//
//  RGDispatchQueue.m
//  RGGCD
//
//  Created by RAIN on 16/4/11.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import "RGDispatchQueue.h"

static RGDispatchQueue *mainQueue;
static RGDispatchQueue *defaultGlobalQueue;
static RGDispatchQueue *userInteractiveGlobalQueue;
static RGDispatchQueue *utilityGlobalQueue;
static RGDispatchQueue *backgroundGlobalQueue;
static RGDispatchQueue *userInitiatedGlobalQueue;
static RGDispatchQueue *unspecifiedGlobalQueue;

@interface RGDispatchQueue ()

@property (nonatomic, readwrite, strong) dispatch_queue_t dispatchQueue;

@end

#pragma mark -
@implementation RGDispatchQueue

#pragma mark Initializer

- (instancetype)initWithLabel:(const char *)label
                    queueType:(DispatchQueueType)queueType
{
    self = [super init];
    if (self) {
        switch (queueType) {
            case DispatchQueueTypeConcurrent:
                self.dispatchQueue = dispatch_queue_create(label, DISPATCH_QUEUE_CONCURRENT);
                break;
                
            case DispatchQueueTypeSerial:
                self.dispatchQueue = dispatch_queue_create(label, DISPATCH_QUEUE_SERIAL);
                break;
                
            case DispatchQueueTypeNone:
                self.dispatchQueue = nil;
                break;
                
            default:
                break;
        }
        
    }
    return self;
}

- (instancetype)initWithQueueType:(DispatchQueueType)queueType {
    return [[RGDispatchQueue alloc] initWithLabel:nil queueType:queueType];
    /*
    if (self == [super init]) {
        switch (queueType) {
            case DispatchQueueTypeConcurrent:
                self.dispatchQueue = dispatch_queue_create(nil, DISPATCH_QUEUE_CONCURRENT);
                break;
                
            case DispatchQueueTypeSerial:
                self.dispatchQueue = dispatch_queue_create(nil, DISPATCH_QUEUE_SERIAL);
                break;
                
            case DispatchQueueTypeNone:
                self.dispatchQueue = nil;
                break;
        }
    }
    return self;
    */
}


#pragma mark - Performance

+ (void)performInMainQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue mainQueue] perform:performance];
}

+ (void)performInDefaultGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue defaultGlobalQueue] perform:performance];
}

+ (void)performInUserInteractiveGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue userInteractiveGlobalQueue] perform:performance];
}

+ (void)performInUtilityGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue utilityGlobalQueue] perform:performance];
}

+ (void)performInBackgroundGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue backgroundGlobalQueue] perform:performance];
}

+ (void)performInUserInitiatedGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue userInitiatedGlobalQueue] perform:performance];
}

+ (void)performInUnspecifiedGlobalQueue:(dispatch_block_t)performance {
    [[RGDispatchQueue unspecifiedGlobalQueue] perform:performance];
}


#pragma mark - Performance Delay

- (void)performDelay:(int64_t)seconds
         performance:(dispatch_block_t)performance
{
    dispatch_time_t delayTime = dispatch_time(DISPATCH_TIME_NOW, seconds);
    dispatch_after(delayTime, self.dispatchQueue, performance);
}

+ (void)performInMainQueueDelay:(int64_t)seconds
                    performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue mainQueue] performDelay:seconds performance:performance];
}

+ (void)performInDefaultGlobalQueueDelay:(int64_t)seconds
                             performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue mainQueue] performDelay:seconds performance:performance];
}

+ (void)performInUserInteractiveGlobalQueueDelay:(int64_t)seconds
                                     performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue userInteractiveGlobalQueue] performDelay:seconds performance:performance];
}

+ (void)performInUtilityGlobalQueueDelay:(int64_t)seconds
                             performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue utilityGlobalQueue] performDelay:seconds performance:performance];
}

+ (void)performInBackgroundGlobalQueueDelay:(int64_t)seconds
                                performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue backgroundGlobalQueue] performDelay:seconds performance:performance];
}

+ (void)performInUserInitiatedGlobalQueueDelay:(int64_t)seconds
                                   performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue userInitiatedGlobalQueue] performDelay:seconds performance:performance];
}

+ (void)performInUnspecifiedGlobalQueueDelay:(int64_t)seconds
                                 performance:(dispatch_block_t)performance
{
    [[RGDispatchQueue unspecifiedGlobalQueue] performDelay:seconds performance:performance];
}

@end


#pragma mark - Queues

@implementation RGDispatchQueue (Queues)

+ (instancetype)concurrentQueue {
    return [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeConcurrent];
}

+ (instancetype)serialQueue {
    return [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeSerial];
}

+ (RGDispatchQueue *)mainQueue {
    mainQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    mainQueue.dispatchQueue = dispatch_get_main_queue();
    return mainQueue;
}

+ (RGDispatchQueue *)defaultGlobalQueue {
    defaultGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    defaultGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_DEFAULT, 0);
    return defaultGlobalQueue;
}

+ (RGDispatchQueue *)userInteractiveGlobalQueue {
    userInteractiveGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    userInteractiveGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_USER_INTERACTIVE, 0);
    return userInteractiveGlobalQueue;
}

+ (RGDispatchQueue *)utilityGlobalQueue {
    utilityGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    utilityGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_UTILITY, 0);
    return utilityGlobalQueue;
}

+ (RGDispatchQueue *)backgroundGlobalQueue {
    backgroundGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    backgroundGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0);
    return backgroundGlobalQueue;
}

+ (RGDispatchQueue *)userInitiatedGlobalQueue {
    userInitiatedGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    userInitiatedGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
    return userInitiatedGlobalQueue;
}

+ (RGDispatchQueue *)unspecifiedGlobalQueue {
    unspecifiedGlobalQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    unspecifiedGlobalQueue.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_UNSPECIFIED, 0);
    return unspecifiedGlobalQueue;
}

@end


#pragma mark - Performances

@implementation RGDispatchQueue (Performances)

- (void)async:(dispatch_block_t)performance {
    dispatch_async(self.dispatchQueue, performance);
}

@end


#pragma mark - Deprecated

@implementation RGDispatchQueue (Deprecated)

- (void)perform:(dispatch_block_t)performance {
    dispatch_async(self.dispatchQueue, performance);
}

@end
