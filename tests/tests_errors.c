/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "errors.h"
#include "macros.h"

void redirect_all_std(void);

Test(int_errors, errors, .init=redirect_all_std)
{
    cr_assert_eq(error("abc"), ERR);
    cr_assert_eq(error_close("abc", 4536), ERR);
}

Test(print_errors, errors, .init=redirect_all_std)
{
    cr_assert_eq(error_print("abc"), ERR);
    cr_assert_eq(error_print_ptr("abc"), NULL);
}

Test(ptr_errors, errors, .init=redirect_all_std)
{
    cr_assert_eq(error_ptr("abc"), NULL);
    cr_assert_eq(error_close_ptr("abc", 4532), NULL);
}