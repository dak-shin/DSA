def canSum(val, arr, memo = {}):

    if(val in memo.keys()): return memo[val]
    if(val == 0): return True
    if(val<0): return False

    for x in arr:
        rem = val - x
        if(canSum(rem,arr, memo)==True):
            memo[rem] = True
            return True

    memo[val] = False
    return False

def howSum(val, arr, memo = {}):
    if(val in memo.keys()): return memo[val]
    if(val == 0): return []
    if(val<0): return None

    for x in arr:
        rem = val - x
        temp = howSum(rem,arr, memo)
        # print("Value of temp is ",temp)
        if(temp!=None):
            temp.append(x)
            memo[rem] = temp
            return memo[rem]

    memo[val] = None
    # print(memo)
    return None

def bestSum(val, arr): # needs to be memoized 
    # if(val in memo.keys()): return memo[val]
    if(val == 0): return []
    if(val<0): return None
    short_comb = None
    for x in arr:
        rem = val-x
        res = bestSum(rem,arr)
        if(res!=None):
            res.append(x)
            if(short_comb==None or len(short_comb)>len(res)):
                short_comb = res
    # memo[val] = short_comb
    return short_comb

n = int(input("Enter the number : "))
arr = [1,5]
print("can sum : ",canSum(n,arr))
print("how sum : ",howSum(n,arr))
print("best sum : ",bestSum(n,arr))
