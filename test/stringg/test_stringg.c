

#include "stringg.h"
#include "unity.h"

void test_stringg_get_length(void)
{
    const char *str = "Hello, World!";
    uint32_t len;
    dsa_err_t ret = stringg_get_length(str, &len);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_UINT32(strlen(str), len);
}

void test_stringg_copy(void)
{
    const char *src = "Hello, World!";
    char dest[20];
    dsa_err_t ret = stringg_copy(src, dest, sizeof(dest));
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_STRING(src, dest);
}

void test_stringg_compare(void)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    dsa_err_t ret = stringg_compare(str1, str2);
    TEST_ASSERT_EQUAL(DSA_OK, ret);

    str2 = "Hello, ";
    ret = stringg_compare(str1, str2);
    TEST_ASSERT_EQUAL(DSA_FAIL, ret);
}

void test_stringg_concat(void)
{
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    char result[20];
    dsa_err_t ret = stringg_concat(str1, str2, result);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_STRING("Hello, World!", result);
}

void test_stringg_max_occurance(void)
{
    const char *str = "Hello, World!";
    char result;
    dsa_err_t ret = stringg_max_occurance(str, &result);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_CHAR('l', result);
}

void test_stringg_reverse(void)
{
    const char *str = "Hello, World!";
    char reverse[20];
    dsa_err_t ret = stringg_reverse(str, reverse);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_STRING("!dlroW ,olleH", reverse);
}

void test_stringg_count_word(void)
{
    const char *str = "Hello,\tWorld!\n";
    uint32_t count;
    dsa_err_t ret = stringg_count_word(str, &count);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_UINT32(2, count);
}

void test_stringg_count_alpha_and_num(void)
{
    const char *str = "Hello, World! 123";
    size_t c_alpha, c_num;
    dsa_err_t ret = stringg_count_alpha_and_num(str, &c_alpha, &c_num);
    TEST_ASSERT_EQUAL(DSA_OK, ret);
    TEST_ASSERT_EQUAL_UINT(c_alpha, 10);
    TEST_ASSERT_EQUAL_UINT(c_num, 3);
}

void test_stringg_count_vow_and_cons()
{
    const char *str = "Hello, world!";
    size_t c_vowel, c_consonant;

    // test with a sample input string
    dsa_err_t result = stringg_count_vow_and_cons(str, &c_vowel, &c_consonant);

    // check if the function returned success
    TEST_ASSERT_EQUAL(DSA_OK, result);

    // check the expected output
    TEST_ASSERT_EQUAL(3, c_vowel);
    TEST_ASSERT_EQUAL(8, c_consonant);
}

void test_stringg_get_longest_sub_str_in_strs()
{
    const char *str1 = "abcdef";
    const char *str2 = "zbcdf";
    char substr[6];

    // test with sample input strings
    dsa_err_t result = stringg_get_longest_sub_str_in_strs(str1, str2, substr);

    // check if the function returned success
    TEST_ASSERT_EQUAL(DSA_OK, result);

    // check the expected output
    TEST_ASSERT_EQUAL_STRING("bcd", substr);
}
