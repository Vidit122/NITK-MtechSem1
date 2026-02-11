
# elgamal


import random

def gcd(a, b):
    if b==0:
        return a
    else: return gcd(b, a%b)

def generate_keys(q):
    g = random.randint(2, q - 1) 
    x_a = random.randint(2, q - 2)
    y_a = pow(g, x_a, q)
    return (q, g, y_a), x_a 

def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def sign_message(message_hash, public_key, private_key):
    q, g, y_a = public_key
    x_a = private_key
    while True:
        k = random.randint(2, q - 2)
        if gcd(k, q - 1) == 1:
            break
    r = pow(g, k, q)
    k_inv = mod_inverse(k, q - 1)
    s = (message_hash - x_a * r) * k_inv % (q - 1)
    return (r, s)

def verify_signature(message_hash, signature, public_key):
    q, g, y_a = public_key
    r, s = signature
    if not (0 < r < q and 0 <= s < q - 1):
        return False
    v1 = (pow(y_a, r, q) * pow(r, s, q)) % q
    v2 = pow(g, message_hash, q)
    return v1 == v2


q = int(input("Enter a prime no: "))
public_key, private_key = generate_keys(q)
print(f"Public Key (q, g, y_a): {public_key}")
print(f"Private Key (x_a): {private_key}")
original_message_hash = int(input("Enter a number b/w 1 and prime-2: "))


signature = sign_message(original_message_hash, public_key, private_key)
print(f"Signature (r, s): {signature}")
is_valid = verify_signature(original_message_hash, signature, public_key)
print(f"Signature is valid: {is_valid}")