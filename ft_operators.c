//
//  ft_operators.c
//  
//
//  Created by Jossy Ras on 26/03/2017.
//
//

#include "rpn_calc.h"

void                ft_add_op(op_list *begin_list, char element)
{
    op_list         *follower;
    
    follower = NULL;
    follower = malloc(sizeof(op_list) * 1);
    follower->data = element;
    follower->next = NULL;
    if (begin_list->next == NULL)
        begin_list-> next = follower;
    else
    {
        while (begin_list->next != NULL)
            begin_list = begin_list->next;
        begin_list->next = follower;
    }
}

int                 ft_count_op(op_list *begin_list)
{
    int             i;
    
    i = 0;
    while (begin_list != NULL)
    {
        i++;
        begin_list = begin_list->next;
    }
    return (i);
}
