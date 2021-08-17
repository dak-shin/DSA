def fib(n, k=1, l=1):
    if n < 2:
        return k
    else:
        return fib(n-1, l, k+l)

print(fib(10))
