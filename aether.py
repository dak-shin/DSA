n = int(input())
print('Hello')
print("4 3 5 2 3".split())
arr = [int(x) for x in "4 3 5 2 3".split()]
print(arr )
dif = []

for i in range(1,len(arr)):
    dif.append(abs(arr[i]-arr[i-1]))

print(max(dif)-min(dif))
