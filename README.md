# hill_cipher
## 📌 Description
This project implements a **cryptographic system** that combines a classical encryption cipher (**Hill Cipher**) with a **custom hashing function** to ensure both **data confidentiality and integrity**.

- Encryption is achieved using the Hill Cipher (key: 3×3 matrix)  
- Integrity is verified using a custom hash function  

## ⚙️ Working Principle of the Project

The system ensures secure communication using two layers:

### 1. Encryption Layer (Hill Cipher)
- Protects the message from unauthorized access by converting plaintext into ciphertext.

### 2. Integrity Layer (Hash Function)
- Ensures that the message has not been altered during transmission.

The hash of the original message is appended to the plaintext before encryption.  
After decryption, the hash is recomputed and compared to verify authenticity.

## Cipher Used: Hill Cipher
  `
The Hill Cipher is a classical **polygraphic substitution cipher** based on **matrix multiplication**.

- Operates on blocks of letters (size = 3)  
- Uses a **3×3 key matrix**  
- All operations are performed **modulo 26**  
