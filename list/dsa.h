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
#define DSA_OK          (0)
#define DSA_FAIL        (-1)
#define DSA_NO_MEM      (-2)
#define DSA_INVALID_ARG (-3)

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
