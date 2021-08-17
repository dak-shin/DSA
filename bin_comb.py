def print_all():
    n = int(input("Enter the value of n : "))
    temp = []
    temp2 = ['0','1']
    res = ['0','1']
    for i in range(1,n+1):
        res = temp2.copy() if i>1 else ['0','1']
        temp2 =[]
        for j in range(2):
            temp = list(map(lambda x: ['0','1'][j]+x,res))
            temp2.extend(temp)
    print(res)
    print("Num of binary combiations are :",len(res))
print_all()
