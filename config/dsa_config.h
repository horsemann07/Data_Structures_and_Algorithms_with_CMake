#ifndef __DSA_CONFIG__
#define __DSA_CONFIG__

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef int8_t dsa_err_t;

#define DSA_OK          (1)
#define DSA_FAIL        (0)
#define DSA_INVALID_ARG (-1)
#define DSA_NO_MEM      (-2)

#define DSA_CHECK_ARG(arg)                                                                         \
    {                                                                                              \
        dsa_err_t __ = arg;                                                                        \
        if (!(__))                                                                                 \
            return DSA_INVALID_ARG;                                                                \
    }

#define DSA_RETURN_ON_ERR(arg)                                                                     \
    {                                                                                              \
        dsa_err_t __ = arg;                                                                        \
        if (__ != DSA_OK)                                                                          \
            return __;                                                                             \
    }

#define DSA_CDEBUG_ON_ERR(arg)                                                                     \
    {                                                                                              \
        dsa_err_t __ = arg;                                                                        \
        if (__ != DSA_OK)                                                                          \
            printf("%s: %d error <%d>\n", __func__, __LINE__, __);                                 \
        return __;                                                                                 \
    }

#endif /* __DSA_CONFIG__ */
