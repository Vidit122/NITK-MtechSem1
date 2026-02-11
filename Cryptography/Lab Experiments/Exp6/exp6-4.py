# hill cipher

import numpy as np

plaintext = (input("Enter the text : "))

def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def encrypt_hill_cipher(plaintext, key_matrix):
    n = key_matrix.shape[0]
    if len(plaintext) % n != 0:
        plaintext += 'X' * (n - (len(plaintext) % n)) 

    ciphertext = ""
    for i in range(0, len(plaintext), n):
        block = plaintext[i : i + n]
        message_vector = np.array([ord(char) - ord('A') for char in block]).reshape(n, 1)
        
        cipher_vector = np.dot(key_matrix, message_vector) % 26
        
        ciphertext += "".join(chr(int(val) + ord('A')) for val in cipher_vector)
    return ciphertext


def decrypt_hill_cipher(ciphertext, key_matrix):
    n = key_matrix.shape[0]
    det = int(round(np.linalg.det(key_matrix)))
    det_mod_26 = det % 26
    det_inv = mod_inverse(det_mod_26, 26)
    
    if det_inv is None:
        print("Key matrix is not invertible modulo 26. Cannot decrypt.")
    
    adjugate_matrix = np.round(det * np.linalg.inv(key_matrix)).astype(int) % 26
    inverse_key_matrix = (det_inv * adjugate_matrix) % 26
    
    decrypted_text = ""
    
    for i in range(0, len(ciphertext), n):
        block = ciphertext[i : i + n]
        cipher_vector = np.array([ord(char) - ord('A') for char in block]).reshape(n, 1)
        
        message_vector = np.dot(inverse_key_matrix, cipher_vector) % 26
        
        decrypted_text += "".join(chr(int(val) + ord('A')) for val in message_vector)
    return decrypted_text



key_matrix_2x2 = np.array([[3, 5], [4, 7]])


encrypted_text = encrypt_hill_cipher(plaintext.upper(), key_matrix_2x2)
print(f"Plaintext: {plaintext}")
print("Encryption--------------------------")
print(f"Encrypted Text: {encrypted_text}")

print("Decryption--------------------------")
decrypted_text = decrypt_hill_cipher(encrypted_text, key_matrix_2x2)
print(f"Decrypted Text: {decrypted_text}")