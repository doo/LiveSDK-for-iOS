//
//  LiveOperationCore.h
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

#import <Foundation/Foundation.h>
#import "LiveAuthDelegate.h"
#import "LiveOperationDelegate.h"
#import "StreamReader.h"

@class LiveConnectClientCore;
@class LiveOperation;

@interface LiveOperationCore : NSObject <StreamReaderDelegate, LiveAuthDelegate>

@property (nonatomic, readonly) NSString *path;
@property (nonatomic, readonly) NSString *method;
@property (nonatomic, strong) NSData *requestBody;
@property (nonatomic, readonly) id userState; 
@property (nonatomic, weak) id delegate;
@property (nonatomic, readonly) LiveConnectClientCore *liveClient;
@property (nonatomic, strong) NSInputStream *inputStream;
@property (weak, nonatomic, readonly) NSURL *requestUrl;
@property (nonatomic, strong) StreamReader *streamReader;
@property (nonatomic, strong) NSMutableURLRequest *request; 

@property (nonatomic) BOOL completed;
@property (nonatomic, strong) NSString *rawResult;
@property (nonatomic, strong) NSDictionary *result;
@property (nonatomic, strong) id connection;
@property (nonatomic, strong) NSMutableData *responseData;
@property (nonatomic, strong) id publicOperation;
@property (nonatomic, strong) NSHTTPURLResponse *httpResponse;
@property (nonatomic, strong) NSError *httpError;

- (id) initWithMethod:(NSString *)method
                 path:(NSString *)path
          requestBody:(NSData *)requestBody
             delegate:(id)delegate
            userState:(id)userState
           liveClient:(LiveConnectClientCore *)liveClient;

- (id) initWithMethod:(NSString *)method
                 path:(NSString *)path
          inputStream:(NSInputStream *)inputStream
             delegate:(id)delegate
            userState:(id)userState
           liveClient:(LiveConnectClientCore *)liveClient;

- (void) execute;

- (void) cancel;

- (void) dismissCurrentRequest;

- (void) setRequestContentType;

- (void) sendRequest;

- (void) operationFailed:(NSError *)error;

- (void) operationCompleted;

- (void) operationReceivedData:(NSData *)data;

@end
