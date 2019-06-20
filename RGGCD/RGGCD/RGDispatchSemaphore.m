//
//  RGDispatchSemaphore.m
//  RGGCD
//
//  Created by RAIN on 2019/6/19.
//  Copyright © 2019 Smartech. All rights reserved.
//

#import "RGDispatchSemaphore.h"

@interface RGDispatchSemaphore ()

@property (nonatomic, readwrite, strong) dispatch_semaphore_t semaphore;

@end

@implementation RGDispatchSemaphore

- (instancetype)init {
    if (self == [super init]) {
        self.semaphore = dispatch_semaphore_create(0);
    }
    return self;
}

- (instancetype)initWithValue:(NSInteger)value {
    if (self == [super init]) {
        self.semaphore = dispatch_semaphore_create(value);
    }
    return self;
}

- (NSInteger)waitFor:(NSInteger)timeout {
    NSInteger resValue = dispatch_semaphore_wait(self.semaphore, timeout);
    return resValue;
}

- (NSInteger)wait {
    NSInteger resValue = dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return resValue;
}

- (NSInteger)signal {
    NSInteger resValue = dispatch_semaphore_signal(self.semaphore);
    return resValue;
}

@end
