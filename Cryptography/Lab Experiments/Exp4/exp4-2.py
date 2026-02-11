n = int(input("Enter a number(>6): "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

def gcd_recursive(a,b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)

li = []
for i in range(2,n):
    if(isPrime(i)):
        li.append(i)

for i in range(len(li)-1):
    num = gcd_recursive(n-li[i],n-li[i+2])
    print(num, "p and q are: ", li[i], li[i+2])
