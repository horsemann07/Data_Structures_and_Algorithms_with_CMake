/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifndef _DSA_H_
#define _DSA_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/************************************
 * MACROS AND DEFINES
 ************************************/
#define DSA_OK          (1)
#define DSA_FAIL        (0)
#define DSA_NO_MEM      (-1)
#define DSA_INVALID_ARG (-2)

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

/************************************
 * TYPEDEFS
 ************************************/
typedef int8_t dsa_err_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

#ifdef __cplusplus
}
#endif

#endif /* _DSA_H_ */
