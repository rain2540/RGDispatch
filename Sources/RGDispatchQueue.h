//
//  RGDispatchQueue.h
//  RGDispatch
//
//  Created by RAIN on 16/4/11.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 队列类型
 
 - DispatchQueueTypeConcurrent: 并行队列
 - DispatchQueueTypeSerial: 串行队列
 - DispatchQueueTypeNone: 不指定类型
 */
typedef NS_ENUM(NSUInteger, DispatchQueueType) {
    /// 并行队列
    DispatchQueueTypeConcurrent,
    /// 串行队列
    DispatchQueueTypeSerial,
    /// 不指定队列类型
    DispatchQueueTypeNone,
};


#pragma mark -

@interface RGDispatchQueue : NSObject

@property (nonatomic, readonly, strong) dispatch_queue_t dispatchQueue;


#pragma mark - Lifecycle

- (instancetype)initWithLabel:(const char *)label
                    queueType:(DispatchQueueType)queueType;
- (instancetype)initWithQueueType:(DispatchQueueType)queueType;

@end


#pragma mark - Queues

@interface RGDispatchQueue (Queues)

+ (instancetype)concurrentQueue;

+ (instancetype)serialQueue;

+ (instancetype)sharedConcurrentQueue;

+ (instancetype)sharedSerialQueue;

/// 返回主线程队列
+ (instancetype)mainQueue;

/// 返回优先级为 QOS_CLASS_USER_INTERACTIVE: DISPATCH_QUEUE_PRIORITY_HIGH 的队列
+ (instancetype)globalQueueUserInteractive;

/// 返回优先级为 QOS_CLASS_USER_INITIATED 的队列
+ (instancetype)globalQueueUserInitiated;

/// 返回优先级为 QOS_CLASS_DEFAULT: DISPATCH_QUEUE_PRIORITY_DEFAULT 的队列
+ (instancetype)globalQueueDefault;

/// 返回优先级为 QOS_CLASS_UTILITY: DISPATCH_QUEUE_PRIORITY_LOW 的队列
+ (instancetype)globalQueueUtility;

/// 返回优先级为 QOS_CLASS_BACKGROUND: DISPATCH_QUEUE_PRIORITY_BACKGROUND 的队列
+ (instancetype)globalQueueBackground;

/// 返回优先级为 QOS_CLASS_UNSPECIFIED 的队列
+ (instancetype)globalQueueUnspecified;

@end


#pragma mark - Excute

@interface RGDispatchQueue (Excute)

/// 在调度队列上提交一个异步执行的 block, 并且立即返回
/// @param excute 要提交到目标调度队列的 block, 此参数不能为 NULL
- (void)async:(dispatch_block_t)excute;

/// 在调度队列上提交一个同步执行的 block, 并且立即返回
/// @param excute 要提交到目标调度队列的 block, 此参数不能为 NULL
- (void)sync:(dispatch_block_t)excute;

/// 在指定时间间隔执行的 block
/// @param delta 指定的时间间隔
/// @param excute 要提交的 block, 此参数不能为 NULL
- (void)after:(int64_t)delta
       excute:(dispatch_block_t)excute;

@end


#pragma mark - Deprecated

@interface RGDispatchQueue (Deprecated)

#pragma mark Queues

/**
 *  返回优先级为 QOS_CLASS_DEFAULT: DISPATCH_QUEUE_PRIORITY_DEFAULT 的队列
 *
 *  @return 优先级为 QOS_CLASS_DEFAULT 的队列
 */
+ (instancetype)defaultGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueDefault instead");

/**
 *  返回优先级为 QOS_CLASS_USER_INTERACTIVE: DISPATCH_QUEUE_PRIORITY_HIGH 的队列
 *
 *  @return 优先级为 QOS_CLASS_USER_INTERACTIVE 的队列
 */
+ (instancetype)userInteractiveGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueUserInteractive instead");

/**
 *  返回优先级为 QOS_CLASS_UTILITY: DISPATCH_QUEUE_PRIORITY_LOW 的队列
 *
 *  @return 优先级为 QOS_CLASS_UTILITY 的队列
 */
+ (instancetype)utilityGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueUtility instead");

/**
 *  返回优先级为 QOS_CLASS_BACKGROUND: DISPATCH_QUEUE_PRIORITY_BACKGROUND 的队列
 *
 *  @return 优先级为 QOS_CLASS_BACKGROUND 的队列
 */
+ (instancetype)backgroundGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueBackground instead");

/**
 *  返回优先级为 QOS_CLASS_USER_INITIATED 的队列
 *
 *  @return 优先级为 QOS_CLASS_USER_INITIATED 的队列
 */
+ (instancetype)userInitiatedGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueUserInitiated instead");

/**
 *  返回优先级为 QOS_CLASS_UNSPECIFIED 的队列
 *
 *  @return 优先级为 QOS_CLASS_UNSPECIFIED 的队列
 */
+ (instancetype)unspecifiedGlobalQueue DEPRECATED_MSG_ATTRIBUTE("Use +globalQueueUnspecified instead");


#pragma mark - Performance

/**
 在调度队列上提交一个异步执行的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
- (void)perform:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use -async: instead");

/**
 在主线程队列上提交一个异步执行的 block, 并且立即返回
 
 @param performance 要提交到主线程队列的 block, 此参数不能为 NULL
 */
+ (void)performInMainQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue mainQueue] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_DEFAULT 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInDefaultGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueDefault] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_USER_INTERACTIVE 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInteractiveGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUserInteractive] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_UTILITY 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUtilityGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUtility] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_BACKGROUND 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInBackgroundGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueBackground] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_USER_INITIATED 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInitiatedGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUserInitiated] async:]");
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_UNSPECIFIED 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUnspecifiedGlobalQueue:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUnspecified] async:]");


#pragma mark - Performance Delay

/**
 *  在指定时间间隔执行的 block
 *
 *  @param seconds     指定的时间间隔
 *  @param performance 要提交的 block, 此参数不能为 NULL
 */
- (void)performDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use -after:perform: instead");

/**
 在主线程队列上提交一个在指定时间间隔、异步执行的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到主线程队列的 block, 此参数不能为 NULL
 */
+ (void)performInMainQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue mainQueue] after: perform:] instead");

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_DEFAULT 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInDefaultGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueDefault] after: perform:] instead");

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_USER_INTERACTIVE 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInteractiveGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUserInteractive] after: perform:] instead");

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_UTILITY 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUtilityGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUtility] after: perform:] instead");

+ (void)performInBackgroundGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueBackground] after: perform:] instead");

+ (void)performInUserInitiatedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUserInitiated] after: perform:] instead");

+ (void)performInUnspecifiedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use [[RGDispatchQueue globalQueueUnspecified] after: perform:] instead");

@end
