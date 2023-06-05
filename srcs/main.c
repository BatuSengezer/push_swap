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
    head_a = stack_a;
    head_b = stack_b;
    current_a = stack_a;
    current_b = stack_b;

    // // swap_check
    // printf("before swap:\n");
    // while(current_a != NULL)
    // {
    //     printf("a value, position, sorted_pos is:%d, %d, %d\n",current_a->val, current_a->pos, current_a->sorted_pos);
    //     current_a = current_a->next;
    // }
    // swap_a(&stack_a);
    
    // printf("after swap:\n");
    // while(head_a != NULL)
    // {
    //     printf("a value, position, sorted pos  is: %d, %d, %d\n",head_a->val, head_a->pos, head_a->sorted_pos);
    //     head_a = head_a->next;
    // }
    // printf("sort_check: %d\n",sorted_check(stack_a));
    // printf("highest_val: %d\n",find_highest(stack_a));
    // printf("size is: %d\n",list_size(stack_a));

    // push_check
printf("before push:\n");
current_b = stack_b;  // Assign stack_b to current_b
while (current_a != NULL)
{
    printf("a value, position, sorted pos is: %d, %d, %d\n", current_a->val, current_a->pos, current_a->sorted_pos);
    if (current_b != NULL)  // Check if current_b is not NULL before accessing its members
        printf("aa value, position, sorted pos is: %d, %d, %d\n", current_b->val, current_b->pos, current_b->sorted_pos);
    current_a = current_a->next;
    if (current_b != NULL)
        current_b = current_b->next;
}
push_b(&stack_a, &stack_b);
head_b = stack_b;
printf("after push:\n");
while (head_a != NULL)
{
    printf("a value, position, sorted pos is: %d, %d, %d\n", head_a->val, head_a->pos,head_a->sorted_pos);
    if (head_b != NULL)  // Check if head_b is not NULL before accessing its members
        printf("b value, position, sorted pos is: %d, %d, %d\n", head_b->val, head_b->pos, head_b->sorted_pos);
    head_a = head_a->next;
    if (head_b != NULL)
        head_b = head_b->next;
}
    return (0);
}