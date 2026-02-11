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
            for z in range(1,n):
                if pow(2,z)-1 == li[i]*li[j]:
                    print(z,"(",pow(2,z),")", " - ", li[i],li[j])
                    ans.append(z)

print("PART B ===========================")

for i in range(len(li)):
    for j in range(i+1,len(li)):
        for k in range(j+1,len(li)):
            for z in range(1,n):
                if z%2 == 0 and z>4:
                    if pow(2,z)-1 == li[i]*li[j]*li[k]:
                        print(z, " - ", li[i],li[j],li[k])
                        ans.append(z)
            

# RANGE - 300