/*
 The MIT License
 Copyright (c) 2011 lyo.kato@gmail.com
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

//
//  PURGeohash.h
//  PureSDK
//  https://github.com/lyokato/objc-geohash/blob/master/Classes/ARC/cgeohash.h
//

#pragma once

@import Foundation;

static int const GEOHASH_STANDARD_PRECISION = 8;

#include <stdbool.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct {
    double max;
    double min;
} GEOHASH_range;

extern bool GEOHASH_verify_hash(const char *hash);
extern char * _Nullable GEOHASH_encode(double latitude, double longitude, unsigned int hash_length);

NS_ASSUME_NONNULL_END
