/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "stringg.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
dsa_err_t stringg_get_length(const char *string, uint32_t *len)
{
    DSA_CHECK_ARG(string && len);
    int i = 0;
    uint32_t count = 0;
    while (string[i] != '\0')
    {
        count++;
    }
    return DSA_OK;
}

dsa_err_t stringg_copy(const char *src, char *dest, uint32_t len)
{
    DSA_CHECK_ARG(src && dest);

    for (int32_t s_len = 0; s_len < len; s_len++)
    {
        dest[s_len] = src[s_len];
    }
    return DSA_OK;
}

dsa_err_t stringg_compare(const char *str1, char *str2)
{
    DSA_CHECK_ARG(str1 && str2);
    int32_t count = 0;
    while (str1[count] != '\0' && str2[count] != '\0')
    {
        if (str1[count] != str2[count])
        {
            return DSA_FAIL;
        }
    }
    return DSA_OK;
}