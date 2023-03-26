/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/
#include "dsa.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/**
 * @brief get the string length
 *
 * @param[in] string: string
 * @param[out] len length of the string
 * @return
 *      - DSA_INVALID_ARG: in str pointers are NULL.
 *      - DSA_OK: length calculated.
 */
dsa_err_t stringg_get_length(const char *string, uint32_t *len);

/**
 * @brief copy one string to another.
 *
 * @param[in] src source string
 * @param[out] dest memory where string should be copied.
 * @param[in] len size of str to be copied
 * @return
 *      - DSA_INVALID_ARG: in str pointers are NULL.
 *      - DSA_OK: success
 */
dsa_err_t stringg_copy(const char *src, char *dest, uint32_t len);

/**
 * @brief compare two string
 *
 * @param[in] str1 string
 * @param[in] str2 string
 * @return
 *      - DSA_INVALID_ARG: in str pointers are NULL.
 *      - DSA_FAIL: string not equal.
 *      - DSA_OK: string is equal.
 */
dsa_err_t stringg_compare(const char *str1, char *str2);

/**
 * @brief concatenate two string
 *
 * @param[in] str1  fisrt string
 * @param[in] str2  second string
 * @param[out] result resulted string
 * @return
 *      - DSA_INVALID_ARG: in str pointers are NULL.
 *      - DSA_NO_MEM: failed to allocat memory for result.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_concat(const char *str1, const char *str2, char *result);

/**
 * @brief reverse the string.
 *
 * @param[in] str input string
 * @param[out] reverse reverse string
 * @return
 *      - DSA_INVALID_ARG: in str pointers are NULL.
 *      - DSA_NO_MEM: failed to allocat memory for reverse.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_reverse(const char *str, char *reverse);

/**
 * @brief count the word seperate by space.
 *
 * @param[in] str input string.
 * @param[in] count counted words
 * @return
 *      - DSA_INVALID_ARG: if pointers are NULL.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_count_word(const char *str, uint32_t *count);

/**
 * @brief count the alphabetic and numbers in string
 *
 * @param[in] str input string
 * @param[out] c_alpha num of alphabetic
 * @param[out] c_num num of number
 * @return
 *      - DSA_INVALID_ARG: if pointers are NULL.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_count_alpha_and_num(const char *str, size_t *c_alpha, size_t *c_num);

/**
 * @brief count vowel and constant in string
 *
 * @param[in] str input string
 * @param[out] c_vowel num of vowels
 * @param[out] c_consonant num of constant
 * @return
 *      - DSA_INVALID_ARG: if pointers are NULL.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_count_vow_and_cons(const char *str, size_t *c_vowel, size_t *c_consonant);

/**
 * @brief convert lower alphabetic to upper and vice-versa.
 *
 * @param[in] str input string
 * @param[out] result coverted string
 * @return
 *      - DSA_INVALID_ARG: if pointers are NULL.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_convert_lower_to_upper_and_upper_to_lower(const char *str, char *result);
/**
 * @brief get the longest sub string in two string.
 * @example
 * str1 = abcdef, str2 = zbcdf
 *      a   b   c   d   e   f
 * z    0   0   0   0   0   0
 * b    0   1   0   0   0   0
 * c    0   0   2   0   0   0
 * d    1   0   0   3   0   0
 * f    0   0   0   0   0   1
 *
 * substr = bcd
 *
 * str1 = abab, str2 = baba
 *      a   b   a   b
 * b    0   1   0   1
 * a    1   0   2   0
 * b    0   2   0   3
 * a    1   0   3   0
 *
 * substr = bab
 *
 * @param[in] str1: input string 1
 * @param[in] str2: input string 2
 * @param[out] substr: resulted substring
 *
 * @return
 *      - DSA_INVALID_ARG: if pointers are NULL.
 *      - DSA_OK: success.
 */
dsa_err_t stringg_get_longest_sub_str_in_strs(const char *str1, const char *str2, char *substr);

#ifdef __cplusplus
}
#endif
