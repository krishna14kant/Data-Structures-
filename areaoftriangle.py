a = float(input('1 side: '))  
b = float(input('2 side: '))  
c = float(input('3 side: '))  
  
s = (a + b + c) / 2  
area = (s*(s-a)*(s-b)*(s-c)) ** 0.5  
print('The area of the triangle is %0.4f' %area)   
