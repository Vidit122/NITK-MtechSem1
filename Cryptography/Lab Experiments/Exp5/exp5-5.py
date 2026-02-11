
def gcd(n1, n2):
    if n2 == 0:
        return n1
    else:
        return gcd(n2, n1%n2)
    
a = int(input("Enter the 1st no: "))
b = int(input("Enter the 1st no: "))

d = gcd(a, b)
print("GCD OF 2 NOS = ", d)