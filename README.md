# push_swap
A sorting algorithm that uses two stacks and given operations to sort the stack with least amount of operations.

## Rules: 
We have 2 stacks named a and b.\
• At the beginning: \
$~~~~~$◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.\
$~~~~~$◦ The stack b is empty.\
• The goal is to sort in ascending order numbers into stack a. To do so we have the following operations at our disposal: \
$~~~~~$◦ sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. \
$~~~~~$◦ sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
$~~~~~$◦ ss : sa and sb at the same time.\
$~~~~~$◦ pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.\
$~~~~~$◦ pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.\
$~~~~~$◦ ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.\
$~~~~~$◦ rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.\
$~~~~~$◦ rr : ra and rb at the same time.\
$~~~~~$◦ rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.\
$~~~~~$◦ rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.\
$~~~~~$◦ rrr : rra and rrb at the same time.

### You can run it as:
```zsh
# terminal
make && ./push_swap 2 1 3 6 5 8
```
The program prints operations done in order and sorts given numbers in ascending order.
