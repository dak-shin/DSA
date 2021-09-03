
arr = [0,2,1,3,7,9]
x = 12

arr2 = []
for i in range(len(arr)):
    arr2.append([arr[i],i])
arr2.sort(reverse=True,key=(lambda x: x[0]))
print(arr2) # cost per unit length, length
cost = 0
for i in range(len(arr2)-1):
    if x == 0 or arr2[i][1]==0:
        break
    cost = cost + (arr2[i][0]*(x//arr2[i][1]))
    print(cost,"\n")
    x = x - (arr2[i][1]*(x//arr2[i][1]))

print(cost)
