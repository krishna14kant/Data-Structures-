# Python program to demonstrate stack implementation

from queue import LifoQueue

# Initializing a stack
stack = LifoQueue(maxsize = 3)
print(stack.qsize())

stack.put('a')
stack.put('b')
stack.put('c')

print("Full: ", stack.full())
print("Size: ", stack.qsize())


print('\nElements popped from the stack')
print(stack.get())
print(stack.get())
print(stack.get())

print("\nEmpty: ", stack.empty())
