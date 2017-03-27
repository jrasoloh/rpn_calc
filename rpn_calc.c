//
//  rpn_calc.c
//  
//
//  Created by Jossy Ras on 25/03/2017.
//
//

#include "rpn_calc.h"
#include <string.h>

int                 ft_rpn_calc(int_list *nb, op_list *op)
{
    int             res;
    
    res = nb->data;
    if (nb->next != NULL)
    {
        nb = nb->next;
        while (nb)
        {
            printf("%d %c %d = ", res, op->data, nb->data);
            res = ft_do_op(res, nb->data, op->data);
            printf("%d\n", res);
            nb = nb->next;
            op = op->next;
        }
    }
    return (res);
    
}
int                 main()
{
    int_list        *numbers;
    op_list         *operator;
    int             nb;
    int             op;
	char			*str;
    
	str = strdup("12 3 + 45 / 454 * 1237 / 15 * 45 %");
 /*   numbers.data = 12;
    numbers.next = NULL;
    operator.data = '+';
    operator.next = NULL;
    ft_add_nb(&numbers, 3);
    ft_add_nb(&numbers, 5);
    ft_add_nb(&numbers, 34);
    ft_add_nb(&numbers, 17);
    ft_add_op(&operator, '-');
    ft_add_op(&operator, '+');
    ft_add_op(&operator, '-');*/
	numbers = ft_make_nb_list(str);
	operator = ft_make_op_list(str);
    nb = ft_count_nb(numbers);
    op = ft_count_op(operator);
    printf("il y a %d nombres et %d operateurs\n", nb, op);
    printf("le calcul donne %d\n", ft_rpn_calc(numbers, operator));
    return (0);
}

