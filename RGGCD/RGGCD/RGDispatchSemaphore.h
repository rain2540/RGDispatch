//
//  RGDispatchSemaphore.h
//  RGGCD
//
//  Created by RAIN on 2019/6/19.
//  Copyright © 2019 Smartech. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGDispatchSemaphore : NSObject

/// 初始化
- (instancetype)init;

- (instancetype)initWithValue:(NSInteger)value;

@end

NS_ASSUME_NONNULL_END
