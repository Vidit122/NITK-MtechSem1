# elgamal
import random

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

p = int(input("Enter a prime number: "))
g = random.randint(1, p - 2) 

private = random.randint(2, p-2)
h = pow(g, private)%p

m = int(input("Enter a message: "))
k = random.randint(2, p-2)
c1 = pow(g, k)%p
c2 = (m*pow(h, k))%p
print("Encryption-------------")
print(c1, c2)

print("Decryption-------------")
s = pow(c1, private)%p
m = c2/s%p
print(m)

