/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <Parse/PFConstants.h>

PF_WATCH_UNAVAILABLE_WARNING

@class ParseReachability;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, ParseReachabilityState) {
    ParseReachabilityStateNotReachable,
    ParseReachabilityStateReachableViaWiFi,
    ParseReachabilityStateReachableViaCell,
};

@protocol ParseReachabilityListener <NSObject>

- (void)reachability:(ParseReachability *)reachability didChangeReachabilityState:(ParseReachabilityState)state;

@end

PF_WATCH_UNAVAILABLE @interface ParseReachability : NSObject

@property (nonatomic, assign, readonly) ParseReachabilityState currentState;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithURL:(NSURL *)url NS_DESIGNATED_INITIALIZER;

/*
 Returns a shared singleton instance,
 that could be used to check if Parse is reachable
 */
+ (instancetype)sharedParseReachability;

/*
 Adds a weak reference to the listener,
 callbacks are executed on the main thread when status or flags change.
 */
- (void)addListener:(id<ParseReachabilityListener>)listener;

/*
 Removes weak reference to the listener.
 */
- (void)removeListener:(id<ParseReachabilityListener>)listener;

/*
 Removes all references to all listener objects.
 */
- (void)removeAllListeners;

@end

NS_ASSUME_NONNULL_END
