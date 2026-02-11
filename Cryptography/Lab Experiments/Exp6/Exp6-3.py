# playfair cipher

text = input("Enter the plaintext or message: ")
key = input("Enter the key: ")

arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def generate_key_matrix(key):
    key = key.upper().replace("J", "I") 
    matrix = []
    used = set()

    for ch in key:
        if ch not in used and ch.isalpha():
            used.add(ch)
            matrix.append(ch)

    for ch in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if ch not in used:
            used.add(ch)
            matrix.append(ch)

    return [matrix[i:i+5] for i in range(0, 25, 5)]


def find_position(matrix, ch):
    for i, row in enumerate(matrix):
        for j, val in enumerate(row):
            if val == ch:
                return i, j
    return None


def prepare_text(text, for_encryption=True):
    text = text.upper().replace("J", "I")
    result = ""
    i = 0

    while i < len(text):
        ch1 = text[i]
        if not ch1.isalpha():
            i += 1
            continue
        if i + 1 < len(text):
            ch2 = text[i+1]
            if not ch2.isalpha():
                i += 1
                continue
            if ch1 == ch2:
                result += ch1 + 'X'
                i += 1
            else:
                result += ch1 + ch2
                i += 2
        else:
            result += ch1 + 'X'
            i += 1
    return result


def playfair_encrypt(text, matrix):
    text = prepare_text(text)
    cipher = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i+1]
        r1, c1 = find_position(matrix, a)
        r2, c2 = find_position(matrix, b)

        if r1 == r2:  
            cipher += matrix[r1][(c1 + 1) % 5]
            cipher += matrix[r2][(c2 + 1) % 5]
        elif c1 == c2: 
            cipher += matrix[(r1 + 1) % 5][c1]
            cipher += matrix[(r2 + 1) % 5][c2]
        else:
            cipher += matrix[r1][c2]
            cipher += matrix[r2][c1]

    return cipher


def playfair_decrypt(cipher, matrix):
    plain = ""

    for i in range(0, len(cipher), 2):
        a, b = cipher[i], cipher[i+1]
        r1, c1 = find_position(matrix, a)
        r2, c2 = find_position(matrix, b)

        if r1 == r2: 
            plain += matrix[r1][(c1 - 1) % 5]
            plain += matrix[r2][(c2 - 1) % 5]
        elif c1 == c2: 
            plain += matrix[(r1 - 1) % 5][c1]
            plain += matrix[(r2 - 1) % 5][c2]
        else: 
            plain += matrix[r1][c2]
            plain += matrix[r2][c1]

    return plain


matrix = generate_key_matrix(key)
print("Key Matrix:")
for row in matrix:
    print(row)


print("Encryption--------------------------")
ciphertext = playfair_encrypt(text, matrix)
print("\nEncrypted:", ciphertext)

print("Decryption--------------------------")
decrypted = playfair_decrypt(ciphertext, matrix)
print("Decrypted:", decrypted)

