/*-
 * Copyright (c) 2011 Daemotron <mail@daemotron.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef __SYNCTORY_TEST_HELPERS_
#define __SYNCTORY_TEST_HELPERS_

#include <stdio.h>

#define HLP_CHUNK_SIZE  512


typedef struct
{
    unsigned char character;
    unsigned int width;
    FILE *stream;
} hlp_progress_t;


#define hlp_progress_init(ctx) {        \
    (ctx)->char = '\0';                 \
    (ctx)->width = 0;                   \
    (ctx)->stream = NULL;               \
}


typedef struct
{
    unsigned char separator;
    unsigned char cwd;
} hlp_path_ctx_t;


#define hlp_path_ctx_init(ctx) {        \
    (ctx)->separator = '\0';            \
    (ctx)->cwd = '\0';                  \
}


void    hlp_path_abs(const char *source, char *dest, size_t len);
void    hlp_path_join(const hlp_path_ctx_t *ctx, char *path1, const char *path2, void *buffer, size_t size);
void    hlp_path_normalize(char *path, const hlp_path_ctx_t *ctx);
int     hlp_file_bytecopy(const char *source, const char *destination, size_t size, hlp_progress_t *pctx);
void    hlp_report_error(int error_no);

#endif /* __SYNCTORY_TEST_HELPERS_ */
