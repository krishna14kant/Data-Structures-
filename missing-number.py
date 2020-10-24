n = int(input())
arr = list(map(int,input().split()))

sum = sum(arr)
exp = (n)*(n+1)/2
print(int(exp-sum))



"""temp = 0
arr = sorted(arr)
for i in range(len(arr)):
    temp += 1
    if arr[i] != temp:
        res = temp
        break

print(res)"""
