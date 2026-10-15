
# RSA Algorithm Implementation

# Function to find GCD
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to find modular inverse
def mod_inverse(e, phi):
    for d in range(1, phi):
        if (e * d) % phi == 1:
            return d
    return None

# Step 1: Choose two prime numbers
p = 61
q = 53

# Step 2: Calculate n and phi
n = p * q
phi = (p - 1) * (q - 1)

# Step 3: Choose public exponent e
e = 17

# Step 4: Calculate private exponent d
d = mod_inverse(e, phi)

# Step 5: Display keys
print("Public Key:", (e, n))
print("Private Key:", (d, n))

# Step 6: Input message
message = int(input("Enter a number to encrypt (less than n): "))

if 0 <= message < n:
    # Encryption: C = M^e mod n
    cipher = pow(message, e, n)
    print("Encrypted Message:", cipher)

    # Decryption: M = C^d mod n
    decrypted = pow(cipher, d, n)
    print("Decrypted Message:", decrypted)
else:
    print("Error: Message must be between 0 and", n - 1)
