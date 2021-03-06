/******************************************************************************
 * Copyright © 2014-2017 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#include "strutil.h"

#include <string.h>
#include <ctype.h>

char *strtrim(char *str)
{
    char *s = str;
    while (isspace ((unsigned char) *s)) {
        s++;
    }
    char *p = s + strlen(s);
    while ((p > s) && isspace ((unsigned char) p[-1])) {
        p--;
    }
    *p = '\0';
    if (s > str) {
        size_t slen = strlen(s);
        memmove(str, s, slen);
        str[slen] = '\0';
    }
    return str;
}

ssize_t strstartswith(const char *s, const char *prefix)
{
    size_t len = strlen(prefix);
    if ((len <= strlen(s)) && (memcmp(s, prefix, len) == 0)) {
        return (ssize_t) len;
    } else {
        return (ssize_t) -1;
    }
}
