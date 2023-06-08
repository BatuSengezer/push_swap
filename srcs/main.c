#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	*stack_a;
    t_stack *stack_b;
    t_stack	*current_a;
    t_stack	*current_b;    
    t_stack	*head_a;
    t_stack	*head_b;
    t_stack	*tmp_a;
    t_stack	*tmp_b;

    stack_a = fill_stack_a(ac, av);
    stack_b = NULL;
    current_a = stack_a;
    current_b = stack_b;

    // // swap_test
    // printf("before swap:\n");
    // while(current_a != NULL)
    // {
    //     printf("a value, position, sorted_pos is:%d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    // }
    // push_b(&stack_a, &stack_b);
    // push_b(&stack_a, &stack_b);
    // swap_ab(&stack_a, &stack_b);
    // current_a = stack_a;
    // current_b = stack_b;
    // printf("after swap:\n");
    // while(current_a != NULL)
    // {
    //     printf("A value, position, sorted pos  is: %d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    // }
    // while(current_b != NULL)
    // {
    //     printf("B value, position, sorted pos  is: %d, %d, %d\n",current_b->val, current_b->pos, current_b->sorted_pos);
    //     current_b = current_b->next;
    // }
    // printf("sort_check: %d\n",sorted_check(stack_a));
    // printf("highest_val: %d\n",find_highest(stack_a));
    // printf("size is: %d\n",list_size(stack_a));

    // // push_test
    // printf("highest is: %d \n", find_highest(stack_a));
    // printf("before push:\n");
    // while (current_a != NULL)
    // {
    //     printf("A value, position, sorted pos is: %d, %d, %d\n", current_a->val, current_a->pos, current_a->sorted_pos);
    //     if (current_b != NULL)  // Check if current_b is not NULL before accessing its members
    //         printf("B value, position, sorted pos is: %d, %d, %d\n", current_b->val, current_b->pos, current_b->sorted_pos);
    //     current_a = current_a->next;
    //     if (current_b != NULL)
    //         current_b = current_b->next;
    // }
    // push_b(&stack_a, &stack_b);
    // push_b(&stack_a, &stack_b);
    // push_a(&stack_a, &stack_b);
    // current_a = stack_a;  // Reset current_a to the beginning of stack_a
    // current_b = stack_b; 
    // printf("after push:\n");
    // while (current_a != NULL) 
    // {
    //     printf("A value, position, sorted pos is: %d, %d, %d\n", current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    // }
    // printf("---------------\n");
    // while (current_b != NULL) 
    // {
    //     printf("B value, position, sorted pos is: %d, %d, %d\n", current_b->val, current_b->pos, current_b->sorted_pos);
    //     current_b = current_b->next;
    // }

    // // rotate_test
    // printf("before rotate:\n");
    // while(current_a)
    // {
    //     printf("A value, position, sorted_pos is:%d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    //     if (current_b)
    //     {
    //         printf("B value, position, sorted_pos is:%d, %d, %d\n",current_b->val, current_b->pos, current_b->sorted_pos);
    //         current_b = current_b->next;
    //     }
    // }
    // // //rotate_b(&stack_a);
    // push_b(&stack_a, &stack_b);
    // push_b(&stack_a, &stack_b);
    // push_b(&stack_a, &stack_b);
    // reverse_rotate_ab(&stack_a,&stack_b);
    // current_a = stack_a;
    // current_b = stack_b; 
    // printf("after rotate: \n");
    // while(current_a != NULL)
    // {
    //     printf("A value, position, sorted pos  is: %d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    // }
    //  while(current_b != NULL)
    // {
    //     printf("B value, position, sorted pos  is: %d, %d, %d\n",current_b->val, current_b->pos, current_b->sorted_pos);
    //     current_b = current_b->next;
    // }

    // sort_three test
    printf("before sort_three:\n");
    while(current_a)
    {
        printf("A value, position, sorted_pos is:%d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
        current_a = current_a->next;
        if (current_b)
        {
            printf("B value, position, sorted_pos is:%d, %d, %d\n",current_b->val, current_b->pos, current_b->sorted_pos);
            current_b = current_b->next;
        }
    }
    // //rotate_b(&stack_a);
    sort_three(&stack_a);
    // swap_a(&stack_a);
    current_a = stack_a;
    printf("after sort_three: \n");
    while(current_a != NULL)
    {
        printf("A value, position, sorted pos  is: %d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
        current_a = current_a->next;
    }
     while(current_b != NULL)
    {
        printf("B value, position, sorted pos  is: %d, %d, %d\n",current_b->val, current_b->pos, current_b->sorted_pos);
        current_b = current_b->next;
    }



    return (0);
}