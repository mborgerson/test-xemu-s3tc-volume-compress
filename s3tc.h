/*
 * QEMU texture decompression routines
 *
 * Copyright (c) 2020 Wilhelm Kovatch
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef S3TC_H
#define S3TC_H

#ifdef STANDALONE
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define g_malloc malloc
typedef int GLint;
enum {
GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
};
#else
#include "qemu/osdep.h"
#include "gl/gloffscreen.h"
#endif

uint8_t *decompress_3d_texture_data(GLint color_format,
                                    const uint8_t *data,
                                    unsigned int width,
                                    unsigned int height,
                                    unsigned int depth);
#endif
