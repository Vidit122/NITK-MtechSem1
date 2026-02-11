n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if(isPrime(i)):
        li.append(i)
ans = []
for i in range(len(li)-1):
    for j in range(i+1,len(li)):
        if(li[j] - li[i] !=2):
            ans.append((li[i],li[j]))
print(ans)
print(len(ans))


# RANGE - 100