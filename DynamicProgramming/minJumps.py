
def minJump(arr, n):
    MAX = 9999
    dp = [MAX for i in range(n)]
    dp[0] = 0
    for i in range(n):
        if(dp[i]!=MAX):
            for j in range(1,arr[i]+1):
                if(i+j<n):
                    temp = dp[i]+1
                    dp[i+j] = min(temp,dp[i+j])

    return dp[n-1]

def minJumpsRec(arr,n):
    # n = size
    # n-1 = destination
    res = 999

    if(n==1): return 0
    for i in range(0,n-1):
        for j in range(0,arr[i]+1):
            if(i+j>=n-1):
                temp = minJumpsRec(arr,i+1)
                res = min(res, temp+1)

    return res

# 0,1,1,1,99,2

arr = [3,1,2,1,2,1]
print(minJumpsRec(arr,len(arr)))
