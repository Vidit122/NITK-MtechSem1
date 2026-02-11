# RSA 

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

arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

text = (input("Enter the text : "))

t1 = ""
t2 = ""
for i in range(len(text)):
    if i%2==0:
        t1 = t1 + text[i]
    else:
        t2 = t2 + text[i]


cipher = t1 + t2
print("Encoding-------------------")
print(cipher)
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
print("Encryption------------------")
c = pow(m, e)%n
print(c)
print("Decryption------------------")
m = pow(c, d)%n
print(m)
