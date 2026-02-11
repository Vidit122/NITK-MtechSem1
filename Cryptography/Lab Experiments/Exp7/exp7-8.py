# digital signature on rsa, elgamal, schnorr

# rsa


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

m = int(input("Enter a message: "))
print(e, d)
print("Digital signature is: ")
s = pow(m, d)%n
print(s)
m1 = pow(s, e)%n
if(m1==m): print("Digital signature has been successfully created!")


