//
//  RGDispatchSemaphore.h
//  RGDispatch
//
//  Created by RAIN on 2019/6/19.
//  Copyright © 2019 Smartech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RGDispatchSemaphore : NSObject

#pragma mark Initializer

/// 创建一个初始值为 0 的、重新计数的信号量。
///
/// @discussion
/// 当两个线程需要协调特定事件的完成时，将值传递为零非常有用。
///
/// @result
/// 新创建的信号量，如果失败，则为NULL。
- (instancetype)init;

/// 创建一个具有初始值的、重新计数的信号量。
///
/// @discussion
/// 当两个线程需要协调特定事件的完成时，将值传递为零非常有用。
/// 传递大于零的值对于管理有限的资源池（池的大小等于该值）很有用。
///
/// @param value
/// 信号量的起始值。传递小于零的值将导致返回NULL。
///
/// @result
/// 新创建的信号量，如果失败，则为NULL。
- (instancetype)initWithValue:(NSInteger)value;


#pragma mark - Public

/// 等待（递减）信号量。
///
/// @discussion
/// 减少计数信号量。如果结果值小于零，则此函数在返回之前等待信号发生。 
///
/// @param timeout
/// 何时超时。为方便起见，有 DISPATCH_TIME_NOW 和 DISPATCH_TIME_FOREVER 常量。
///
/// @result
/// 如果成功，则返回零；如果发生超时，则返回非零。
- (NSInteger)waitFor:(NSInteger)timeout;

/// 等待（递减）信号量。timeout 设置为 DISPATCH_TIME_FOREVER
///
/// @discussion
/// 减少计数信号量。如果结果值小于零，则此函数在返回之前等待信号发生。
///
/// @result
/// 如果成功，则返回零；如果发生超时，则返回非零。
- (NSInteger)wait;

/// 发信号（增加）信号量。
///
/// @discussion
/// 增加计数信号量。如果先前的值小于零，则此函数在返回之前唤醒等待的线程。
///
/// @result
/// 如果线程被唤醒，此函数将返回非零值。否则，返回零。
- (NSInteger)signal;

@end
