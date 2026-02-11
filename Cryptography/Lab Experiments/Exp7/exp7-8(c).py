# digital signature based on schnorr

import random

PRIMENO = int(input("Enter a prime no: "))
generator = int(input("Enter a generator number "))


secretVal = random.randint(1, 97)

X = pow(generator, secretVal) % PRIMENO
y = random.randint(1, 97)
Y = pow(generator, y) % PRIMENO

print("secretVal(secret)= ", secretVal)
print("X= ", X)
print("y=", y)
print("Y=", Y)

c = random.randint(1, 97)
print("c=", c)

z = (y + c * secretVal)
print("z=", z)

val1 = pow(generator, z) % PRIMENO
val2 = (Y * (X**c)) % PRIMENO
print("val1= ", val1, end=' ')
print(" val2= ", val2)

if (val1 == val2):
    print("Proven")
else:
    print("Failure to prove")