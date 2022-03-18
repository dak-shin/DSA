# ip = input()
# res = []
# if (ip[0]=='a' or ip[0]=='e' or ip[0]=='i' or ip[0]=='o' or ip[0]=='u'):
#     res.append('V')
# else:
#     res.append('C')
#

# for i in range(1,len(ip)):
#     if (ip[i]=='a' or ip[i]=='e' or ip[i]=='i' or ip[i]=='o' or ip[i]=='u') and res[-1]=='C':
#         res.append("V")
#     elif not(ip[i]=='a' or ip[i]=='e' or ip[i]=='i' or ip[i]=='o' or ip[i]=='u') and res[-1]=='V':
#         res.append("C")
#
# print("".join(res))

def func(m,n):
    res = 0
    for i in range(2,m):
        temp = n%i
        if(temp >= res):
            res = temp

    return res

print(func(11,25))
