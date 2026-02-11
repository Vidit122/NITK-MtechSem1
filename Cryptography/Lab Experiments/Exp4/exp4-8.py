n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if(isPrime(i+1)):
        if(isPrime(i+3)):
            if(isPrime(i+7)):
                if(isPrime(i+9)):
                    if(isPrime(i+13)):
                        if(isPrime(i+15)):
                            li.append(i)
                            print(i)


# RANGE - 300