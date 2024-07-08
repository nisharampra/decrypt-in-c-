//
//  main.cpp
//  decrypt
//
//  Created by Nisha Ramprasath on 21/06/24.
//

#include <iostream>
#include <string>

// Function to generate extended key for Vigenère cipher
std::string generateKey(const std::string& ciphertext, const std::string& key) {
    std::string extendedKey;
    extendedKey.reserve(ciphertext.length());

    for (size_t i = 0, j = 0; i < ciphertext.length(); ++i) {
        extendedKey += key[j];
        j = (j + 1) % key.length();
    }

    return extendedKey;
}

// Function to perform Vigenère cipher decryption
std::string decryptText(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    plaintext.reserve(ciphertext.length());

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char x = (ciphertext[i] - key[i] + 26) % 26;
        x += 'A';
        plaintext += x;
    }

    return plaintext;
}

int main() {
    std::string ciphertext;
    std::string key;

    // Get input from user
    std::cout << "Enter ciphertext: ";
    std::getline(std::cin, ciphertext);

    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    // Convert ciphertext GGand key to uppercase and remove spaces (if needed)
    for (char& c : ciphertext) {
        if (std::isalpha(c))
            c = std::toupper(c);
    }

    for (char& c : key) {
        if (std::isalpha(c))
            c = std::toupper(c);
    }

    // Generate extended key and decrypt ciphertext
    std::string extendedKey = generateKey(ciphertext, key);
    std::string plaintext = decryptText(ciphertext, extendedKey);

    // Output the results
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Extended Key: " << extendedKey << std::endl;
    std::cout << "Plaintext: " << plaintext << std::endl;

    return 0;
}
