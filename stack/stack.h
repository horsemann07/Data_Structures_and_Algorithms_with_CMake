#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dsa.h"

typedef struct
{
    int32_t *st_base;
    size_t size;
    size_t top;
} stack_t;

/**
 * @brief
 *
 * @param[out] stack
 * @param[in] size
 * @return
 *      - DSA_INVALID_ARG: pointer are null or invalid argument
 *      - DSA_FAIL:
 *      - DSA_OK:
 */
dsa_err_t stack_init(stack_t *stack, uint32_t size);

/**
 * @brief
 *
 * @param[out] stack
 * @return
 *      - DSA_INVALID_ARG: pointer are null
 *      - DSA_FAIL:
 *      - DSA_OK:
 */
dsa_err_t stack_is_empty(stack_t *stack);

/**
 * @brief
 *
 * @param[out] stack
 * @return
 *      - DSA_INVALID_ARG: pointer are null
 *      - DSA_FAIL:
 *      - DSA_OK:
 */
dsa_err_t stack_is_full(stack_t *stack);

/**
 * @brief
 *
 * @param[out] stack
 * @param[in] item
 * @return
 *      - DSA_INVALID_ARG: or invalid argument
 *      - DSA_FAIL:
 *      - DSA_OK
 */
dsa_err_t stack_push(stack_t *stack, int32_t item);

/**
 * @brief
 *
 * @param[out] stack
 * @param[out] item
 * @return
 *      - DSA_INVALID_ARG: pointer are null or invalid argument
 *      - DSA_NO_MEM:
 *      - DSA_FAIL:
 *      - DSA_OK
 */
dsa_err_t stack_pop(stack_t *stack, int32_t *item);

/**
 * @brief
 *
 * @param[out] stack
 * @param[out] item
 * @return
 *      - DSA_INVALID_ARG:
 *      - DSA_FAIL:
 *      - DSA_OK
 */
dsa_err_t stack_peek(stack_t *stack, int32_t *item);

/**
 * @brief
 *
 * @param[out] stack
 * @return
 *      - DSA_INVALID_ARG: pointer are null
 *      - DSA_FAIL:
 *      - DSA_OK
 */
dsa_err_t stack_print_data(stack_t *stack);

/**
 * @brief
 *
 * @param[out] expression
 * @return
 *      - DSA_INVALID_ARG: pointer are null
 *      - DSA_FAIL:
 *      - DSA_OK
 */
dsa_err_t stack_is_parenthes_balance(const char *expression);

#ifdef __cplusplus
}
#endif
#endif /* __STACK_H__ */
