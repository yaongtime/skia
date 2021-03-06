/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkWebpEncoder_DEFINED
#define SkWebpEncoder_DEFINED

#include "SkEncoder.h"

class SkWStream;

namespace SkWebpEncoder {

    struct Options {
        /**
         *  |fQuality| must be in [0.0f, 100.0f] where 0.0f corresponds to the lowest quality.
         */
        float fQuality = 100.0f;

        /**
         *  If the input is premultiplied, this controls the unpremultiplication behavior.
         *  The encoder can convert to linear before unpremultiplying or ignore the transfer
         *  function and unpremultiply the input as is.
         */
        SkTransferFunctionBehavior fUnpremulBehavior = SkTransferFunctionBehavior::kRespect;
    };

    /**
     *  Encode the |src| pixels to the |dst| stream.
     *  |options| may be used to control the encoding behavior.
     *
     *  Returns true on success.  Returns false on an invalid or unsupported |src|.
     */
    bool Encode(SkWStream* dst, const SkPixmap& src, const Options& options);
};

#endif
