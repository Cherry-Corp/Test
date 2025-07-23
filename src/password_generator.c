/**
 * File: password_generator.c
 * Author: Nurafiqah
 * Date: 27/05/2025
 * Description: Contains the core functionality for generating passwords
 * Version: 1.0
 * */

#include "../include/password_generator.h"

// Allowable Character sets for password generation
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()-_=+[]{};:'\",.<>/?\\|~`";

// Generate a random password length between 24 - 64 characters
int getPasswordLength() {
    int length = 0; // Initialize password length
    length = (rand() % (MAX_LENGTH - MIN_LENGTH + 1)) + MIN_LENGTH;    
    return length; // Return the generated length
}

// Generate a random uppercase letter
char getRandomUppercase() {
    return uppercase[rand() % (sizeof(uppercase) - 1)]; // Exclude null terminator
}

// Generate a random lowercase letter
char getRandomLowercase() {
    return lowercase[rand() % (sizeof(lowercase) - 1)]; // Exclude null terminator  
}

// Generate a random digit character
char getRandomDigit() {
    return '0' + (rand() % 10);  // Returns a char from '0' to '9'
}

// Generate a random symbols character
char getRandomSymbol() {
    return symbols[rand() % (sizeof(symbols) - 1)]; // Exclude null terminator  
}

void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len < 2) return;  // No duplicates possible if length < 2

    int tail = 1; // Points to the end of the unique part

    for (int i = 1; i < len; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (str[i] == str[j]) {
                break; // Duplicate found
            }
        }
        if (j == tail) { // No duplicate found
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0'; // Null terminate after unique chars

    int length = len - (len - tail); // Calculate new length

    //validate new length
    if (length < MIN_LENGTH) {
        length = MIN_LENGTH; // Ensure minimum length
        //add random characters to meet minimum length
    } else if (length > MAX_LENGTH) {
        length = MAX_LENGTH; // Ensure maximum length
    }

    printf("Generated Random Password Length: %d\n", length); //Print new length after removing duplicates

}

//Generate a random password
void generatePassword(char *password, int len) {
    int index = 0;

    // Guarantee one char from each category
    password[index++] = getRandomUppercase();
    password[index++] = getRandomLowercase();
    password[index++] = getRandomDigit();
    password[index++] = getRandomSymbol();

    index = 0;  // Reset index to fill the rest of the password

    // Fill the rest with random choices from all types
    while (index < len) {
        char pwd;  // Temporary variable to hold the generated character

        // The first four characters are guaranteed to be one from each category
        if (index == 0) pwd = getRandomUppercase();
        else if (index == 1) pwd = getRandomLowercase();
        else if (index == 2) pwd = getRandomDigit();
        else if (index == 3) pwd = getRandomSymbol();
        else {

            // Randomly choose a character type
            switch (rand() % 4) {
                case 0: 
                    pwd = getRandomUppercase(); 
                    //printf("Password[%d]: %c\n", index, getRandomUppercase());
                    break;
                case 1: 
                    pwd = getRandomLowercase(); 
                    //printf("Password[%d]: %c\n", index, getRandomLowercase());
                    break;
                case 2: 
                    pwd = getRandomDigit(); 
                    //printf("Password[%d]: %d\n", index, getRandomDigit());
                    break;
                case 3:
                    pwd = getRandomSymbol(); 
                    //printf("Password[%d]: %c\n", index, getRandomSymbol());
                    break;
                default:
                    break;
            }
        }

        // Store the generated character in the password array
        password[index] = pwd;
        //printf("Password[%d]: %c\n", index, pwd);
        index++;

    }//while loop

    password[index] = '\0';  // Null-terminate
  
}//generatePassword()