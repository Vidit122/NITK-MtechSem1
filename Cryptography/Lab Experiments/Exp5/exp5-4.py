n = int(input("Enter the value of n: "))
no = int(pow(n, 0.5))
# print(no)
def isPrime(n, no):
    for i in range(2,no):
        if n%i == 0: return False
    return True
check = isPrime(n, no)
print(check)
