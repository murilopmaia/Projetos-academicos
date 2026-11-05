def fib(n: int):
    f_2: int = 0
    f_1: int = 1
    f: int = 1

    for i in range(1, n):
        f = f_1 + f_2

        f_2 = f_1
        f_1 = f
    
    return f

def fib2(n: int):
    if n == 1 or n == 0:
        return n
    else:
        return fib2(n-1) + fib2(n-2)



if __name__ == "__main__":
    print(fib2(6))