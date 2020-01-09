//
//  PURTrie.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/13/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// A simple trie implementation.
// https://en.wikipedia.org/wiki/Trie
@interface PURTrie : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithStrings:(NSArray<NSString *> * _Nullable)strings;

// The number of valid words in the tree, not the number of nodes.
@property (nonatomic, readonly) NSUInteger count;

// Returns the node that has the longest prefix of `matching`.
// If the trie contains [dj, dk, dkj, dkji] and matching = `dkjikp`, this would return dkji.
- (NSString * _Nullable)findLongestMatchingNode:(NSString *)matching;

@end

NS_ASSUME_NONNULL_END
