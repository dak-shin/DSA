# Using tabulation
def bestSum(n, arr): # checks for the smallest combination of the values in arr that sums to n
    dp = [None for i in range(n+1)]
    dp[0] = []

    for i in range(0,len(dp)):
        if(dp[i]!=None):
            for val in arr:
                temp = dp[i].copy()
                temp.append(val)
                if(i+val<len(dp) and (dp[i+val] == None or len(dp[i+val])>len(temp))):
                    dp[i+val] = temp
    print(dp[-1])

def string_checker(st, arr): # checks if the st can be made using the values in arr

    dp = [False for x in range(len(st)+1)]
    for val in arr:
        if(len(val)<=len(st) and st[0:len(val)] == val):
            dp[0] = True
    if(dp[0]!= True):
        return False

    for i in range(len(dp)):

        if(dp[i]==True):
            for val in arr:
                if(i+len(val)<len(dp) and st[i:i+len(val)] == val):
                    dp[i+len(val)] = True

    print(dp[-1])



# n = input("Enter the string : ")
n = "abcdf"
arr = ['ab','abc','d','ef']
#bestSum(n,arr)
string_checker(n,arr)
