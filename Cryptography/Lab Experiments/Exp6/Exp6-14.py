

text = (input("Enter the text : "))
arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

k = 3

cipher = ""
for i in range(len(text)):
    value = arr[text[i]]
    a = (value + k)%26
    for key, value in arr.items():
        if value == a:
            b = key
            cipher = cipher + b

print("Encryption--------------------------")
print(cipher)


t1 = ""
t2 = ""
for i in range(len(cipher)):
    if i%2==0:
        t1 = t1 + cipher[i]
    else:
        t2 = t2 + cipher[i]


cipher2 = t1 + t2
print("Encoding-------------------")
print(cipher2)



plaintext = ""
n = len(cipher2)
n1 = ""
n2 = ""
if(n%2 !=0):
    for i in range(n):
        if(i >= int(n/2 + 1)):
            n2 = n2 + cipher2[i]
        else:
            n1 = n1 + cipher2[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext = plaintext + n1[j]
            j = j+1
        else:
            plaintext = plaintext + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext)
else:
    for i in range(n):
        if(i >= int(n/2)):
            n2 = n2 + cipher2[i]
        else:
            n1 = n1 + cipher2[i]
            
    j = 0
    k = 0
    for i in range(n):
        if(i%2 == 0):
            plaintext = plaintext + n1[j]
            j = j+1
        else:
            plaintext = plaintext + n2[k]
            k = k + 1
    print("Decoding-------------------")
    print(plaintext)



k = 3
plaintext1 = ""
for i in range(len(plaintext)):
    value = arr[plaintext[i]]
    a = (value - k)%26
    for key, value in arr.items():
        if value == a:
            b = key
            plaintext1 = plaintext1 + b
print("Decryption--------------------------")
print(plaintext1)