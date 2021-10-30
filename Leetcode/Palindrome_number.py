# Palindrome Number
x=int(input())
x=str(x)
if x==x[::-1]:
    return True #Palindrome
else:
    return False #Not Palindrome