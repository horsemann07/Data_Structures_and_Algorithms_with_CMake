/**
 * @file stack.c
 * @author horsemann07 (raghavjha1531@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-11-2022
 *
 *
 */

#include "stack.h"
#include <string.h>

dsa_err_t stack_init(stack_t *stack, uint32_t size)
{
    DSA_CHECK_ARG(stack);

    stack->st_base = (int32_t *)calloc((size_t)size, sizeof(int32_t));
    if (!(stack->st_base))
    {
        return DSA_NO_MEM;
    }
    stack->top = 0;
    stack->size = size;
    return DSA_OK;
}

dsa_err_t stack_is_empty(stack_t *stack)
{
    DSA_CHECK_ARG(stack);

    if (stack->top == 0)
    {
        return DSA_OK;
    }
    return DSA_FAIL;
}

dsa_err_t stack_is_full(stack_t *stack)
{
    DSA_CHECK_ARG(stack && stack->st_base);

    if (stack->top < (stack->size - 1))
    {
        return DSA_FAIL;
    }
    return DSA_OK;
}

dsa_err_t stack_push(stack_t *stack, int32_t item)
{
    DSA_CHECK_ARG(stack && stack->st_base);

    if (stack->top >= (stack->size - 1))
    {
        return DSA_FAIL;
    }

    stack->st_base[(stack->top)++] = item;
    return DSA_OK;
}

dsa_err_t stack_pop(stack_t *stack, int32_t *item)
{
    DSA_CHECK_ARG(stack && stack->st_base);

    if (stack_is_empty(stack) || stack->top > (stack->size - 1))
    {
        return DSA_FAIL;
    }
    *item = stack->st_base[stack->top - 1];
    stack->st_base[stack->top--] = 0;
    return DSA_OK;
}

dsa_err_t stack_peek(stack_t *stack, int32_t *item)
{
    DSA_CHECK_ARG(stack && stack->st_base);

    if (stack_is_empty(stack) || stack->top > (stack->size - 1))
    {
        return DSA_FAIL;
    }
    *item = stack->st_base[stack->top - 1];
    return DSA_OK;
}

dsa_err_t stack_print_data(stack_t *stack)
{
    DSA_CHECK_ARG(stack);

    for (int i = 0; i < stack->top; i++)
    {
        printf("%d\t", stack->st_base[i]);
        if (i % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    return DSA_OK;
}

/*
 *  algorithm
 */

dsa_err_t stack_is_parenthes_balance(const char *expression)
{
    DSA_CHECK_ARG(expression);
    const char *exp = expression;
    stack_t stack;
    dsa_err_t ret = DSA_OK;
    ret = stack_init(&stack, (uint32_t)strlen(exp));
    if (ret != DSA_OK)
    {
        return ret;
    }

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            stack_push(&stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (stack_is_empty(&stack))
            {
                return DSA_FAIL;
            }

            char bracket;

            stack_pop(&stack, (int32_t *)bracket);
            if (!(exp[i] == ')' && bracket == '(') && !(exp[i] == '}' && bracket == '{')
                && !(exp[i] == ']' && bracket == '['))
            {
                return DSA_FAIL;
            }
        }
    }
    return DSA_OK;
}
