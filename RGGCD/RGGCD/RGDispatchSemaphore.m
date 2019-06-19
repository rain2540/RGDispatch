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

@end
