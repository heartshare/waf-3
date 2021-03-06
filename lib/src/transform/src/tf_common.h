/* 
 * Internal Header
 * Copyright (c) LubinLew
 *
*/
#ifndef __TF_COMMON_H__
#define __TF_COMMON_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "tf_debug.h"


/* provide the compiler with branch prediction information */
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

/* function return */
typedef enum {
	TS_FALSE,
	TS_TRUE
} bool_t;

/* decode to space */
#define _SP (uint8_t)(0x20)
/* decode failed */
#define _NG (uint8_t)(0xFF)


/* fast short-string compare */
#define _2cmp(_d1, _d2) *((uint16_t*)(_d1)) == *((uint16_t*)(_d2))
#define _4cmp(_d1, _d2) *((uint32_t*)(_d1)) == *((uint32_t*)(_d2))

/* internal string copy, copy range [_start, _end) */
#define _copy(_start, _end, _dst) while (_start < _end) {*(_dst++) = *(_start++);}


#ifndef __EXCLUDE_EXTERN_TBL
	extern uint8_t g_hex_charset[];
	extern uint8_t g_dec_charset[];
	extern uint8_t g_url_charset[];
	extern uint8_t g_ascii_charset[];
	extern uint8_t g_base64_charset[];
	extern uint8_t g_base64url_charset[];
#endif /* __EXCLUDE_EXTERN_TBL */

#define _chr(_ch) g_url_charset[_ch]
#define _hex(_ch) g_hex_charset[_ch]
#define _num(_ch) g_dec_charset[_ch]


/* decode Percent-Encoding data */
#define _HEX2VAL(_val1, _val2) ((uint8_t)((uint8_t)((_val1 << 4) + (_val2))))
#define _DEC2VAL(_val1, _val2) ((uint8_t)((uint8_t)((_val1 * 10) + (_val2))))
#define _HEXCHR2VAL(_val1, _val2) _HEX2VAL(_hex(_val1), _hex(_val2))



#endif /* __TF_COMMON_H__ */

