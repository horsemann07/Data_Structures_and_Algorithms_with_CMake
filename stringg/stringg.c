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

dsa_err_t stringg_concat(const char *str1, const char *str2, char *result)
{
    DSA_CHECK_ARG(str1 && str2);

    size_t len = strlen(str1) + strlen(str2) + 1;

    if (result == NULL)
    {
        result = calloc(1, len);
        if (result == NULL)
        {
            return DSA_NO_MEM;
        }
    }
    size_t index = 0, count = 0;
    while (str1[index] != '\0' && count < len)
    {
        result[index] = str1[index];
        count = index;
    }

    index = 0;
    while (str2[index] != '\0' && count < len)
    {
        result[index] = str1[index];
        index++;
        count = index;
    }
    return DSA_OK;
}

dsa_err_t stringg_max_occurance(const char *str, char *result)
{
    DSA_CHECK_ARG(str && result);
    uint8_t freq[256] = { 0 };
    size_t max = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
        if (freq[str[i]] > max)
        {
            max = freq[str[i]];
            result = str[i];
        }
    }

    return DSA_OK;
}

dsa_err_t stringg_reverse(const char *str, char *reverse)
{
    DSA_CHECK_ARG(str);

    size_t len = strlen(str);

    if (reverse == NULL)
    {
        reverse = calloc(1, len + 1);
        if (reverse == NULL)
        {
            return DSA_NO_MEM;
        }
    }
    size_t j = 0;
    for (size_t i = len; i >= 0; i--)
    {
        reverse[j++] = str[i];
    }
    reverse[j] = '\0';
    return DSA_OK;
}

dsa_err_t stringg_count_word(const char *str, uint32_t *count)
{
    DSA_CHECK_ARG(str);
    (*count) = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            (*count)++;
        }
    }
    return DSA_OK;
}

dsa_err_t stringg_count_alpha_and_num(const char *str, size_t *c_alpha, size_t *c_num)
{
    DSA_CHECK_ARG(str && c_alpha && c_num);
    *c_alpha = 0;
    *c_num = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            *c_alpha++;
        }
        else if (str[i] >= '1' && str[i] <= '0')
        {
            *c_num++;
        }
    }

    return DSA_OK;
}

dsa_err_t stringg_count_vow_and_cons(const char *str, size_t *c_vowel, size_t *c_consonant)
{
    DSA_CHECK_ARG(str && c_vowel && c_consonant);
    *c_vowel = 0;
    *c_consonant = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
                || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O'
                || str[i] == 'U')
            {
                *c_vowel++;
            }
            else
            {
                *c_consonant++;
            }
        }
    }

    return DSA_OK;
}

dsa_err_t stringg_convert_lower_to_upper_and_upper_to_lower(const char *str, char *result)
{
    DSA_CHECK_ARG(str && result);
    size_t len = strlen(str);
    if (result == NULL)
    {
        result = calloc(1, len + 1);
        if (result == NULL)
        {
            return DSA_NO_MEM;
        }
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = str[i] - 32; // 'a' = 97 'A' = 65
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = str[i] + 32;
        }
        else
        {
            result[i] = str[i];
        }
    }

    return DSA_OK;
}

/*
 * str1 = abcdef, str2 = zbcdf
 *      a   b   c   d   e   f
 * z    0   0   0   0   0   0
 * b    0   1   0   0   0   0
 * c    0   0   2   0   0   0
 * d    1   0   0   3   0   0
 * f    0   0   0   0   0   1
 *
 * str1 = abab, str2 = baba
 *      a   b   a   b
 * b    0   1   0   1
 * a    1   0   2   0
 * b    0   2   0   3
 * a    1   0   3   0
 *
 * 
 */
dsa_err_t stringg_get_longest_sub_str_in_strs(const char *str1, const char *str2, char *substr)
{
    DSA_CHECK_ARG(str1 && str2);

    const char *X = str1;
    const char *Y = str2;
    size_t m = strlen(str1);
    size_t n = strlen(str2);

    // `lookup[i][j]` stores the length of LCS of substring `X[0…i-1]`, `Y[0…j-1]`
    int lookup[m + 1][n + 1];
    size_t endingIndex = m;
    size_t maxlen = 0;
    // initialize all cells of the lookup table to 0
    memset(lookup, 0, sizeof(lookup));

    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                // update the maximum length and ending index
                if (lookup[i][j] > maxlen)
                {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }
    // return longest common substring having length `maxlen`
    size_t index = endingIndex - maxlen;
    size_t i = 0;
    for (; i < maxlen; i++)
    {
        substr[i] = X[index];
    }
    substr[i] = '\0';
    return DSA_OK;
}