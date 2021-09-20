import time
memo = []

def time_it(func):
    def inner(*args,**kwargs):
        st = time.time_ns()
        func(*args,**kwargs)
        et = time.time_ns()
        print("This took : ",et-st,"ns")
    return inner


def fibRec(x,memo):
    # print(memo)
    if(memo[x] == -1):
        if(x==0 or x==1):
            memo[x] = x
            return x
        else:
            res = fib(x-1)+fib(x-2)
        memo[x] = res
        return res
    else:
        return memo[x]


def fib(x):
    memo = [-1 for i in range(x+1)]
    return fibRec(x,memo)

n = int(input("Enter the number : "))
print(fib(10))
