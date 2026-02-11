n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if(isPrime(i)):
        li.append(i)
count = 0
for i in range(1,n):
    for j in range(i,n):
        ans = pow(i,4)+pow(j,4)
        for k in range(len(li)):
            if li[k] == ans:
                count= count + 1
                print(ans, "i & j are", i, j)
            if(count == 5): break
        if(count == 5): break
    if(count == 5): break

# RANGE - 100