# p^2 + 1 = q^2 + r^2    p,q,r are primes
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
                        if i*i + 1 == j*j + k*k:
                            count = count+1
                            # print(i,j,k)
                            li.append((i,j,k))
                    if(count==6): break
            if(count==6): break
    if(count==6): break
print(li)
