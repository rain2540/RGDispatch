//
//  RGDispatchQueue.m
//  RGDispatch
//
//  Created by RAIN on 16/4/11.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import "RGDispatchQueue.h"

static RGDispatchQueue *MainQueue;
static RGDispatchQueue *GlobalQueueDefault;
static RGDispatchQueue *GlobalQueueUserInteractive;
static RGDispatchQueue *GlobalQueueUtility;
static RGDispatchQueue *GlobalQueueBackground;
static RGDispatchQueue *GlobalQueueUserInitiated;
static RGDispatchQueue *GlobalQueueUnspecified;


@interface RGDispatchQueue ()

@property (nonatomic, readwrite, strong) dispatch_queue_t dispatchQueue;

@end


#pragma mark -

@implementation RGDispatchQueue

#pragma mark Lifecycle

- (instancetype)initWithQueueType:(DispatchQueueType)queueType {
    RGDispatchQueue *queue = [[RGDispatchQueue alloc] initWithLabel:nil queueType:queueType];
    return queue;
}

- (instancetype)initWithLabel:(const char *)label
                    queueType:(DispatchQueueType)queueType
{
    self = [super init];
    if (self) {
        switch (queueType) {
            case DispatchQueueTypeSerial:
                self.dispatchQueue = dispatch_queue_create(label, DISPATCH_QUEUE_SERIAL);
                break;

            case DispatchQueueTypeConcurrent:
                self.dispatchQueue = dispatch_queue_create(label, DISPATCH_QUEUE_CONCURRENT);
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

@end


#pragma mark - Queues

@implementation RGDispatchQueue (Queues)

+ (instancetype)serialQueue {
    RGDispatchQueue *queue = [RGDispatchQueue serialQueueWithLabel:nil];
    return queue;
}

+ (instancetype)concurrentQueue {
    RGDispatchQueue *queue = [RGDispatchQueue concurrentQueueWithLabel:nil];
    return queue;
}

+ (instancetype)serialQueueWithLabel:(const char *)label {
    RGDispatchQueue *queue = [[RGDispatchQueue alloc] initWithLabel:label queueType:DispatchQueueTypeSerial];
    return queue;
}

+ (instancetype)concurrentQueueWithLabel:(const char *)label {
    RGDispatchQueue *queue = [[RGDispatchQueue alloc] initWithLabel:label queueType:DispatchQueueTypeConcurrent];
    return queue;
}

+ (instancetype)sharedSerialQueue {
    static RGDispatchQueue * sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [RGDispatchQueue serialQueueWithLabel:"RGDispatch.Queue.Shared.Serial"];
    });
    return sharedInstance;
}

+ (instancetype)sharedConcurrentQueue {
    static RGDispatchQueue * sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [RGDispatchQueue concurrentQueueWithLabel:"RGDispatch.Queue.Shared.Concurrent"];
    });
    return sharedInstance;
}

+ (instancetype)mainQueue {
    MainQueue = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    MainQueue.dispatchQueue = dispatch_get_main_queue();
    return MainQueue;
}

+ (instancetype)globalQueueUserInteractive {
    GlobalQueueUserInteractive = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueUserInteractive.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_USER_INTERACTIVE, 0);
    return GlobalQueueUserInteractive;
}

+ (instancetype)globalQueueUserInitiated {
    GlobalQueueUserInitiated = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueUserInitiated.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
    return GlobalQueueUserInitiated;
}

+ (instancetype)globalQueueDefault {
    GlobalQueueDefault = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueDefault.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_DEFAULT, 0);
    return GlobalQueueDefault;
}

+ (instancetype)globalQueueUtility {
    GlobalQueueUtility = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueUtility.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_UTILITY, 0);
    return GlobalQueueUtility;
}

+ (instancetype)globalQueueBackground {
    GlobalQueueBackground = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueBackground.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0);
    return GlobalQueueBackground;
}

+ (instancetype)globalQueueUnspecified {
    GlobalQueueUnspecified = [[RGDispatchQueue alloc] initWithQueueType:DispatchQueueTypeNone];
    GlobalQueueUnspecified.dispatchQueue = dispatch_get_global_queue(QOS_CLASS_UNSPECIFIED, 0);
    return GlobalQueueUnspecified;
}

@end


#pragma mark - Excute

@implementation RGDispatchQueue (Excute)

- (void)async:(dispatch_block_t)excute {
    dispatch_async(self.dispatchQueue, excute);
}

- (void)sync:(dispatch_block_t)excute {
    dispatch_sync(self.dispatchQueue, excute);
}

- (void)after:(double_t)delta
       excute:(dispatch_block_t)excute
{
    dispatch_time_t time = dispatch_time(DISPATCH_TIME_NOW, ((int64_t)(delta * NSEC_PER_SEC)));
    dispatch_after(time, self.dispatchQueue, excute);
}

@end


#pragma mark - Barrier

@implementation RGDispatchQueue (Barrier)

- (void)barrierSync:(dispatch_block_t)excute {
    dispatch_barrier_sync(self.dispatchQueue, excute);
}

- (void)barrierAsync:(dispatch_block_t)excute {
    dispatch_barrier_async(self.dispatchQueue, excute);
}

@end
