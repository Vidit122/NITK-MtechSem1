# p(p+1)+q(q+1) = r(r+1)
n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

count = 0
li = []
for i in range(2,n):
    if(isPrime(i)):
        for j in range(2,n):
            if(isPrime(j)):
                for k in range(2,n):
                    if(isPrime(k)):
                        if i*(i+1) + j*(j+1) == k*(k+1):
                            li.append((i,j,k))
                            break
print(li)

# RANGE - 300