# pseudorandom generation based on rsa


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

p = int(input("Enter a prime number: "))
q = int(input("Enter a prime number: "))
n = p*q
phi = (p-1)*(q-1)
print(n, phi)
e = 0


for e in range(2, phi):
    if gcd(e, phi) == 1:
        break


def modInv(e, phi):
    for d in range(2, phi):
        if((d*e)%phi == 1):
            return d
    return -1

d = modInv(e, phi)

for x in range(2, n):
    if(gcd(x, n) == 1): break

print("pseudorandom generation based on rsa are: ")
for i in range(5):
    x = pow(x, e)%n
    print(x)


# m = int(input("Enter a message: "))
# c = pow(m, e)%n
