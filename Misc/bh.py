n = int(input())
arr = []
st = input().split(' ')
arr = [int(x) for x in st]

arr.sort()

temp = []
temp.append(arr[0])
for i in range(1,n):
    temp.append(temp[i-1]^arr[i])

res = 4294967295

print(temp)

for i in range(n):
    print(res-temp[n-i-1])
