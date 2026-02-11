a = []
n = int(input("Enter number of values to enter: "))
print("Enter the values: ")

for i in range(n):
    b = int(input())
    a.append(b)

def gcd(n1, n2):
    if n2 == 0:
        return n1
    else:
        return gcd(n2, n1%n2)
    
d = gcd(a[0], a[1])
for i in range(2, n):
    d = gcd(d, a[i])
print("GCD IS ==========================")
print(d)