arr = [1,2,3,4,5,7,9]
res = 1
for i in arr:
    res = res*i
print(res)
op = -1
for i in arr:
    if res%(i**i) == 0 and op<i:
        op = i

print( op )
