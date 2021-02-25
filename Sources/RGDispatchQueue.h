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
 
 - DispatchQueueTypeConcurrent: 并发队列
 - DispatchQueueTypeSerial: 串行队列
 - DispatchQueueTypeNone: 不指定类型
 */
typedef NS_ENUM(NSUInteger, DispatchQueueType) {
    /// 并发队列
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

/// 按给定标识、类型，初始化队列
/// @param label 队列标识
/// @param queueType 队列类型
- (instancetype)initWithLabel:(const char *)label
                    queueType:(DispatchQueueType)queueType;

/// 按给定类型，初始化队列
/// @param queueType 队列类型
- (instancetype)initWithQueueType:(DispatchQueueType)queueType;

@end


#pragma mark - Queues

@interface RGDispatchQueue (Queues)

/// 标识为 nil 的并发队列
+ (instancetype)concurrentQueue;

/// 标识为 nil 的串行队列
+ (instancetype)serialQueue;

/// 共享并发队列
+ (instancetype)sharedConcurrentQueue;

/// 共享串行队列
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
- (void)after:(double_t)delta
       excute:(dispatch_block_t)excute;

@end


#pragma mark - Barrier

@interface RGDispatchQueue (Barrier)



@end
