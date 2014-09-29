//
//  LiveOperation.m
//  Live SDK for iOS
//
//  Copyright 2014 Microsoft Corporation
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "LiveOperationInternal.h"

@implementation LiveOperation

@synthesize liveOpCore;

- (id) initWithOpCore:(LiveOperationCore *)opCore
{
    self = [super init];
    if (self) 
    {
        liveOpCore = opCore;
        liveOpCore.publicOperation = self;
    }
    
    return self;
}

- (void)dealloc 
{
    liveOpCore.publicOperation = nil;
}

- (NSString *)path
{
    return liveOpCore.path;
}

- (NSString *)method
{
    return liveOpCore.method;
}

- (NSString *)rawResult
{
    return liveOpCore.rawResult;
}

- (NSDictionary *)result
{
    return liveOpCore.result;
}

- (id) userState
{
    return liveOpCore.userState;
}

- (id<LiveOperationDelegate>) delegate
{
    return liveOpCore.delegate;
}

- (void) setDelegate:(id<LiveOperationDelegate>)delegate
{
    liveOpCore.delegate = delegate;
}

- (void) cancel
{
    [liveOpCore cancel];
}
@end
