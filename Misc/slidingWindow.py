def frag(n):
    st = str(n)
    dig = len(str(n))
    count = 0
    for i in range(2,dig+1):
        for j in range(0,dig):
            temp = int(st[j:j+i])
            if len(str(temp))<i:continue
            if(temp%11 == 0):
                count +=1
                print(temp)

    return count

def check(st):
    if(len(st)==1): return True
    j = len(st)-1
    for i in range(0,len(st)//2+1):
        if(i>=j):
            return True
        if(st[i] != st[j]):
            return False
        j -= 1
    return True

def palindrome(st):

    n = len(st)
    res = ""

    for i in range(1,len(st)):
        # print(st[i:len(st)])
        if check(st[i:len(st)]):
            res = st[0:i]
            break
    print(res[::-1])


# print(check("55555"))
palindrome(input("Enter the string : "))
#print(frag(1215598))











































#
