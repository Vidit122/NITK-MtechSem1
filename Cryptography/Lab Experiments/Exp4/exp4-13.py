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
for i in range(len(li)):
    for j in range(i+1,len(li)):
            for z in range(2,n):
                if z == li[i]*li[j]:
                    ans.append(z)

ans.sort()
print(ans)
count = 0
res = []
for i in range(len(ans)-2):
    if ans[i] + 2 == ans[i+1] + 1 == ans[i+2]:
        res.append(ans[i])
result = []
for i in range(len(ans)-3):
    if ans[i] + 3 == ans[i+1] + 2 == ans[i+2] + 1 == ans[i+3]:
        result.append(ans[i])

print(res[0: 5])
print("PART B ======================================")
print(result)
print("PART C ======================================")
con = 0
checker = False
for i in range(len(ans)):
    for j in range(len(li)):
        for k in range(j+1,len(li)):
            if ans[i] == li[j]*li[k]:
                con = con + 1
                print("Number ", ans[i], "has only 2 primes i.e ", li[j], li[k])
            if con==4:
                checker = True
                break
        if(checker): break
    if(checker): break


# RANGE - 300