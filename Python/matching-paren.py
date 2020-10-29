"""
Matching Parenthesis by using STACK (Python)
"""
class Stack:
    def __init__(self,list = None):
        if list == None:
            self.items = []
        else:
            self.items = list

    def push(self,i):
        self.items.append(i)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[-1]

    def isEmpty(self):
        return self.items == [] or len(self.items) == 0

    def size(self):
        return len(self.items)

def Match(op,cl):
    opens = '(['
    closes = ')]'
    return opens.index(op) == closes.index(cl)

stack = Stack()
s = input('Enter Input : ')
match = True #Set default as there are no error
i = 0
while i in range(len(s)) and match == True : #Checking parenthesis while there are no error
    for word in s:
        if word in '([':
            stack.push(word)
        elif word in ')]':
            if stack.size() > 0:
                ch = stack.pop()
                if not Match(ch,word):
                    match = False
            else:
                match = False
    i += 1
if stack.size() > 0: #Recheck if there are still open-paren left
    match = False
print('Parentheses : Matched ! ! !' if match==True else 'Parentheses : Unmatched ! ! !')