def rev(s):

    l = 0
    r = len(s)-1
    arr = list(s)

    while True:
        print(l,r)
        if(r<l):
            break
        while(not arr[l].isalpha()):
            l = l+1

        while(not arr[r].isalpha()):
            r = r-1

        temp = arr[l]
        arr[l] = arr[r]
        arr[r] = temp
        l = l+1
        r = r-1
    return "".join(arr)

def game(arr,l,r, turn=0):
    print(l,r)
    if(r<=l):
        return arr[l]
    left = arr[l]
    right = arr[r]

    if(left>right):
        res = left + game(arr, l+1, r, 1 if turn==0 else 0)
    else:
        res = right + game(arr, l, r-1,  1 if turn==0 else 0)

    if(turn==0):
        print(res)
        return res
    else:
        print(0)
        return 0


print(rev("ab-cd"))
print(game([20,5,4,6],0,3))
