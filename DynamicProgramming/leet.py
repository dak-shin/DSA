def wrapper(val, arr):
    res = []
    def howSum(val , arr, memo={}):
        if(val in memo.keys()):
            return memo[val]
        if(val == 0):
            return True
        if(val<0):
            return False

        for x in arr:
            rem = val - x
            if(howSum(rem, arr,memo) == True):
                memo[rem] = True
                res.append(x)
                print(res)
                return memo[rem]

        memo[val]  = False
        return memo[val]
    print(res)
    print(howSum(val, arr))


wrapper(int(input('Enter the value')),[4,2])
