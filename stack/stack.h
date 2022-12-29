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

dsa_err_t stack_init(stack_t *stack);
dsa_err_t stack_is_empty(stack_t *stack);
dsa_err_t stack_is_full(stack_t *stack);
dsa_err_t stack_push(stack_t *stack, int32_t item);
dsa_err_t stack_pop(stack_t *stack, int32_t *item);
dsa_err_t stack_peek(stack_t *stack, int32_t *item);
dsa_err_t stack_print_data(stack_t *stack);

#ifdef __cplusplus
}
#endif
#endif /* __STACK_H__ */
