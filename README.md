# Hill Cipher with Custom Hash Function
## Description
This project implements a **cryptographic system** that combines a classical encryption cipher (**Hill Cipher**) with a **custom hashing function** to ensure both **data confidentiality and integrity**.

- Encryption is achieved using the Hill Cipher (key: 3×3 matrix)  
- Integrity is verified using a custom hash function  

## Methodology

The system ensures secure communication using two layers:

### 1. Encryption Layer (Hill Cipher)
- Protects the message from unauthorized access by converting plaintext into ciphertext.

### 2. Integrity Layer (Hash Function)
- Ensures that the message has not been altered during transmission.

The hash of the original message is appended to the plaintext before encryption.  
After decryption, the hash is recomputed and compared to verify authenticity.

## Cipher Used: Hill Cipher

The Hill Cipher is a classical **polygraphic substitution cipher** based on **matrix multiplication**.

- Operates on blocks of letters (block size = key size)  
- Using a **3×3 key matrix**  
- Converts letters into numbers (A = 0 to Z = 25)
- Encrypts text in fixed-size blocks using a key matrix
- Encryption: Multiply message vector with key matrix (mod 26)
- Decryption: Uses inverse of the key matrix (mod 26)

## Hash Function
### Working Principle
The hash function combines two techniques:

1. **Multiplicative Hashing**
   
         h = (h × 31 + c) mod m
   where:
      h = Current value of the hash
      c = Numeric value of the current character
      m = modulus
3. **Bitwise Mixing (Shift + XOR)**
   
         hash = hash ⊕ (hash << m)
         hash = hash ⊕ (hash >> n)
- Bitwise shift and XOR operations are applied to improve randomness and reduce collisions.
- The function returns a **32-bit unsigned integer hash value**.
- The hash is later converted into **alphabetic format (A–Z)** for compatibility with the Hill Cipher.

## Workflow of Authentication System

The complete process is:

Plaintext  ->    Hash Generation   ->   Convert Hash to Alphabet   ->   Append Hash to Message   ->   Encryption    ->   Decryption   ->   Remove Padding   ->   Split Message & Hash   ->   Recompute Hash   ->   Compare Hashes   ->   Integrity Verified / Failed

## Instructions to run the code
This project consists of:
 - `hill.cpp`
 - `hill.h`
 - `hash.h`

g++ hill.cpp -o out

./out
