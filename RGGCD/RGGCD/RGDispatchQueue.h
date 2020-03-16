//
//  RGDispatchQueue.h
//  RGGCD
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


#pragma mark - Initializer

- (instancetype)initWithLabel:(const char *)label
                    queueType:(DispatchQueueType)queueType;
- (instancetype)initWithQueueType:(DispatchQueueType)queueType;


#pragma mark - Performance

/**
 在主线程队列上提交一个异步执行的 block, 并且立即返回
 
 @param performance 要提交到主线程队列的 block, 此参数不能为 NULL
 */
+ (void)performInMainQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_DEFAULT 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInDefaultGlobalQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_USER_INTERACTIVE 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInteractiveGlobalQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_UTILITY 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUtilityGlobalQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_BACKGROUND 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInBackgroundGlobalQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_USER_INITIATED 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInitiatedGlobalQueue:(dispatch_block_t)performance;
/**
 在调度队列上提交一个异步执行、优先级为 QOS_CLASS_UNSPECIFIED 的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUnspecifiedGlobalQueue:(dispatch_block_t)performance;


#pragma mark - Performance Delay

/**
 *  在指定时间间隔执行的 block
 *
 *  @param seconds     指定的时间间隔
 *  @param performance 要提交的 block, 此参数不能为 NULL
 */
- (void)performDelay:(int64_t)seconds
         performance:(dispatch_block_t)performance;

/**
 在主线程队列上提交一个在指定时间间隔、异步执行的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到主线程队列的 block, 此参数不能为 NULL
 */
+ (void)performInMainQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_DEFAULT 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInDefaultGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_USER_INTERACTIVE 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUserInteractiveGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

/**
 在调度队列上提交一个在指定时间间隔、异步执行、优先级为 QOS_CLASS_UTILITY 的 block
 
 @param seconds 指定的时间间隔
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
+ (void)performInUtilityGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

+ (void)performInBackgroundGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

+ (void)performInUserInitiatedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

+ (void)performInUnspecifiedGlobalQueueDelay:(int64_t)seconds performance:(dispatch_block_t)performance;

@end


#pragma mark - Queues

@interface RGDispatchQueue (Queues)

+ (instancetype)concurrentQueue;

+ (instancetype)serialQueue;

/**
 *  返回主线程队列
 *
 *  @return 主线程队列
 */
+ (RGDispatchQueue *)mainQueue;

/**
 *  返回优先级为 QOS_CLASS_DEFAULT: DISPATCH_QUEUE_PRIORITY_DEFAULT 的队列
 *
 *  @return 优先级为 QOS_CLASS_DEFAULT 的队列
 */
+ (RGDispatchQueue *)defaultGlobalQueue;

/**
 *  返回优先级为 QOS_CLASS_USER_INTERACTIVE: DISPATCH_QUEUE_PRIORITY_HIGH 的队列
 *
 *  @return 优先级为 QOS_CLASS_USER_INTERACTIVE 的队列
 */
+ (RGDispatchQueue *)userInteractiveGlobalQueue;

/**
 *  返回优先级为 QOS_CLASS_UTILITY: DISPATCH_QUEUE_PRIORITY_LOW 的队列
 *
 *  @return 优先级为 QOS_CLASS_UTILITY 的队列
 */
+ (RGDispatchQueue *)utilityGlobalQueue;

/**
 *  返回优先级为 QOS_CLASS_BACKGROUND: DISPATCH_QUEUE_PRIORITY_BACKGROUND 的队列
 *
 *  @return 优先级为 QOS_CLASS_BACKGROUND 的队列
 */
+ (RGDispatchQueue *)backgroundGlobalQueue;

/**
 *  返回优先级为 QOS_CLASS_USER_INITIATED 的队列
 *
 *  @return 优先级为 QOS_CLASS_USER_INITIATED 的队列
 */
+ (RGDispatchQueue *)userInitiatedGlobalQueue;

/**
 *  返回优先级为 QOS_CLASS_UNSPECIFIED 的队列
 *
 *  @return 优先级为 QOS_CLASS_UNSPECIFIED 的队列
 */
+ (RGDispatchQueue *)unspecifiedGlobalQueue;

@end


#pragma mark -Performances

@interface RGDispatchQueue (Performances)

/// 在调度队列上提交一个异步执行的 block, 并且立即返回
/// @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
- (void)async:(dispatch_block_t)performance;

- (void)sync:(dispatch_block_t)performance;

@end


#pragma mark - Deprecated

@interface RGDispatchQueue (Deprecated)

/**
 在调度队列上提交一个异步执行的 block, 并且立即返回
 
 @param performance 要提交到目标调度队列的 block, 此参数不能为 NULL
 */
- (void)perform:(dispatch_block_t)performance DEPRECATED_MSG_ATTRIBUTE("Use -async: instead");

@end
