#include "ft_push_swap.h"

void                ft_sort_under_5(t_push *handle)
{
    int     mid;
    int     check;

    check = 0;
    mid = ft_find_mid(handle->b, handle->sizeb);
    if (handle->sizeb >= 4)
    {
        check = 1;
        while (handle->sizeb > 3)
        {
            if (handle->sizeb % 2 == 0)
                if (handle->a[0] == mid)
                    ft_push_b(handle);
            if (handle->a[0] < mid)
                ft_push_b(handle);
            else
                ft_rotate_b(handle);
        }
    }
    if (check == 1)
        if (handle->a[0] > handle->a[1])
        {
            ft_swap_a(handle);
            ft_rotate_a(handle);
            ft_rotate_a(handle);
            handle->ign += 2;
        }
    if (!ft_is_sort(handle->b, handle->sizeb))
        ft_algo_insert_a(handle);
}