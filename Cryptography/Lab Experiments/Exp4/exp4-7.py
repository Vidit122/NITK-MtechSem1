n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []

for i in range(2,n):
    if(isPrime(i)):
        for j in range(2,n):
            if(i==j): continue
            if(isPrime(j)):
                for k in range(2,n):
                    if(i==k or j==k): continue
                    if(isPrime(k)):
                        if (j*(j+1) - i*(i+1)) == (k*(k+1) - j*(j+1)):
                            li.append((i,j,k))
                            break
print(li)
print(len(li))


# RANGE - 600