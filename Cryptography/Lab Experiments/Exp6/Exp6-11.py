def vignere(plaintext, key):
    ciphertext = ""
    key_index = 0
    for char in plaintext:
        if 'A' <= char <= 'Z':
            shift = ord(key[key_index % len(key)].upper()) - ord('A')
            encrypted_char = chr(((ord(char) - ord('A') + shift) % 26) + ord('A'))
            ciphertext += encrypted_char
            key_index += 1
        elif 'a' <= char <= 'z':
            shift = ord(key[key_index % len(key)].lower()) - ord('a')
            encrypted_char = chr(((ord(char) - ord('a') + shift) % 26) + ord('a'))
            ciphertext += encrypted_char
            key_index += 1
        else:
            ciphertext += char 
    return ciphertext



def find_repeated_sequences(ciphertext, min_length=3):
    repetitions = {}
    for i in range(len(ciphertext) - min_length + 1):
        sequence = ciphertext[i:i+min_length]
        for j in range(i + min_length, len(ciphertext) - min_length + 1):
            if ciphertext[j:j+min_length] == sequence:
                if sequence not in repetitions:
                    repetitions[sequence] = []
                repetitions[sequence].append(j - i)
    return repetitions


def calculate_gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def estimate_key_length_kasiski(ciphertext, min_sequence_length=3):
    repetitions = find_repeated_sequences(ciphertext, min_sequence_length)
    
    distances = []
    for seq, dists in repetitions.items():
        distances.extend(dists)

    if not distances:
        return None 
    
    current_gcd = distances[0]
    for i in range(1, len(distances)):
        current_gcd = calculate_gcd(current_gcd, distances[i])
    
    return current_gcd


long_plaintext = "THISISAMUCHLONGERTEXTTOILLUSTRATETHEKASISKIMETHODBETTER"
long_plaintext.lower()
long_key = "SECRET"
long_key.lower()
long_ciphertext = vignere(long_plaintext, long_key)
print(f"\nLong Ciphertext for Kasiski: {long_ciphertext}")

estimated_key_length = estimate_key_length_kasiski(long_ciphertext)
print(f"Estimated Key Length (Kasiski Method): {estimated_key_length}")

