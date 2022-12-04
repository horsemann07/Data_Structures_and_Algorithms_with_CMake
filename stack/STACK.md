### STACK

A stack is a linear data structure in which all the insertion and deletion of data or you can say its values are done at one end only, rather than in the middle. Stacks can be implemented by using arrays of type linear.

The stack is mostly used in converting and evaluating expressions in Polish notations, i.e.:

- Infix
- Prefix
- Postfix

In case of arrays and linked lists, these two allows programmers to insert and delete elements from any place within the list, i.e., from the beginning or the end or even from the middle also. But in computer programming and development, there may arise some situations where insertion and deletion require only at one end wither at the beginning or end of the list. The stack is a linear data structure, and all the insertion and deletion of its values are done in the same end which is called the top of the stack. Let us suppose take the real-life example of a stack of plates or a pile of books etc. As the item in this form of data structure can be removed or added from the top only which means the last item to be added to the stack is the first item to be removed. So you can say that the stack follows the Last In First Out (LIFO) structure.

## STACK as Abstract Data Type

The stacks of elements of any particular type is a finite sequence of elements of that type together with the following operations:

- Initialize the stack to be empty. `init_stack()`
- Determine whether the stack is empty or not `is_empty()`
- Check whether the stack is full or not `is_full()`
- If the stack is not full, add or insert a new node at the top of the stack. This operation is termed as Push Operation `push()`
- If the stack is not empty, then retrieve the node at its top `peek()`
- If the stack is not empty, the delete the node at its top. This operation is called as Pop operation. `pop()`

