# row transposition cipher


text = (input("Enter the text : "))
k = (input("Enter the key as per no.of columns required: "))

arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

a = []
for i in range(len(k)):
    temp = []
    temp.append(arr[k[i]])
    temp.append(i)
    a.append(temp)
print(a)
count = 0
cip = []
while(True):
    if count >= len(text): break
    temp = []
    for i in range(len(k)):
        if count >= len(text):
            count = count + 1
            temp.append('x')
        else: 
            temp.append(text[count])
            count = count + 1
    cip.append(temp)

print(cip)

    
a.sort()
print(a)

cipher = ""

count = 0
k = 0
while(True):
    if(count == len(cip)*len(cip[0])): break
    for i in range(len(cip)):
        cipher = cipher + cip[i][a[k][1]]
        count = count + 1
    k = k+1
print("Encryption-----------------------")    
print(cipher)


plain = []
for i in range(int(len(cipher)/len(a))):
    temp = []
    for j in range(len(a)):
        temp.append(0)
    plain.append(temp)
        
plaintext = ""        
count = 0
k = 0
for i in range(len(a)):
    m = a[i][1]
    for j in range(int(len(cipher)/len(a))):
        plain[j][m] = cipher[count]
        count = count + 1
        
        
print("Decryption-----------------------")    
print(plain)
for i in range(len(plain)):
    for j in range(len(plain[0])):
        plaintext = plaintext + plain[i][j]
print(plaintext)
