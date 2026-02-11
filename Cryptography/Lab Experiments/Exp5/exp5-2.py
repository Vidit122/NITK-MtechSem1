m = int(input("Enter the value of m: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,2000):
    if(isPrime(i)):
        li.append(i)

ans = []
count = 0
for i in li:
    for j in range(1, 2000):
        if j*j + 1 == i:
            count = count + 1
            ans.append((j, i))
            if(count == m): break
    if(count == m): break

print(ans)
