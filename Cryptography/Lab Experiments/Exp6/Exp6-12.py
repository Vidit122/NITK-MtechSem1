# 2 substitutions


text = (input("Enter the text : "))
k2 = (input("Enter the key of same size: "))
arr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}

k1 = 3
cipher = ""
for i in range(len(text)):
    value = arr[text[i]]
    a = (value + k1)%26
    for key, value in arr.items():
        if value == a:
            b = key
            cipher = cipher + b

print("Encryption--------------------------")
print(cipher)

cipher2 = ""
for i in range(len(cipher)):
    value1 = arr[cipher[i]]
    value2 = arr[k2[i]]
    a = (value1^value2)%26
    for key, value in arr.items():
        if value == a:
            b = key
            cipher2 = cipher2 + b
        
print("Encoding------------------")
print(cipher2)


plaintext = ""
for i in range(len(cipher2)):
    value1 = arr[cipher2[i]]
    value2 = arr[k2[i]]
    a = (value1^value2)%26
    for key, value in arr.items():
        if value == a:
            b = key
            plaintext = plaintext + b
        
print("Decoding------------------")
print(plaintext)



plaintext1 = ""
for i in range(len(plaintext)):
    value = arr[plaintext[i]]
    a = (value - k1)%26
    for key, value in arr.items():
        if value == a:
            b = key
            plaintext1 = plaintext1 + b
print("Decryption--------------------------")
print(plaintext1)