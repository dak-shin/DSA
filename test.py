arr1 = [1,2,1,1,1,1,1,1]
arr2 = [1,1]
count =0
i=0
def func1(arr):
    i=0
    count=0
    while i<len(arr)-1:
        fac = arr[i]
        if i<len(arr)-1:
            j=i+1
        else: break
        while j<len(arr):
            if fac==arr[j]:
                count=count+1
                i=j+1
                break
            else:
                j=j+1

    return count

print(func1(arr2))

def func2():
    pass

def check(num):
    count=0;
    temp = num
    while num>1:
        print(num)
        if num%2==1: count = count+1
        num = num//2
    if num/2 ==1: count+1
    return temp+count

print(check(5))
