num = 3
my_eff = 20
my_ben = 0
eff = [10,10,10,10]
ben = [10,11,12,15]
# eff = [10,20,10]
# ben = [10,20,11]
temp = []
for i in range(len(eff)):
    temp.append([eff[i],ben[i]])

temp.sort(key=(lambda x: x[1]),reverse=True)
print(temp)
for j in range(len(temp)):
    temp1, temp2 = my_eff,0
    for i in range(j,len(temp)):
        if(temp1 == 0):
            break
        if(temp[i][0]<=temp1):
            temp1 -= temp[i][0]
            temp2 += temp[i][1]
    # print(temp2)
    my_ben = max(my_ben,temp2)

print(my_ben)
