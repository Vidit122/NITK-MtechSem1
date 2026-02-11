n = int(input("Enter a number: "))
def isPrime(n):
    for i in range(2,n):
        if n%i == 0: return False
    return True

li = []
for i in range(2,n):
    if(isPrime(i)):
        li.append(i)
print(li)

ans = []
count = 0
for i in range(len(li)):
    for j in range(i+1,len(li)):
        for k in range(j+1,len(li)):
            for z in range(1,n):
                if z*z - 1 == li[i]*li[j]*li[k]:
                    count = count + 1
                    print(z, " - ", li[i],li[j],li[k])
                    ans.append(z)
                if(count == 5): break
            if(count == 5): break
        if(count == 5): break
    if(count == 5): break

print(ans)

# RANGE - 100