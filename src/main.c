/**
 * File: main.c
 * Author: Nurafiqah
 * Date: 27/05/2025
 * Description: Handles user input, displays menus, and calls functions from other modules.
 * Version: 1.0
 * */

#include "../include/password_generator.h"

int main() {

    //freopen("output.log", "w", stdout);
    //freopen("error.log", "w", stderr);


    // Seed randomness
    srand(time(NULL));  

    //int score = 0;
    int len = getPasswordLength();
    char password[MAX_LENGTH + 1] = {0};
    //char password[MAX_LENGTH + 1];
    char save ='n'; // Default to 'y' for saving the password

    // Initialize password array
    memset(password, 0, sizeof(password));  

    // Generate the randomized password
    generatePassword(password, len);

    // Check for repeated characters, if any, remove them and update the password
    removeDuplicates(password);

    char finalPassword[MAX_LENGTH + 1];
    strcpy(finalPassword, password);

    // Print the final password
    printf("Generated Random Password: %s\n", finalPassword);

    // Check if the password password strength  (weak, moderate, strong, very strong)
    int score = scorePasswordStrength(password);
    printf("Password Strength: %s\n", getStrengthLabel(score));

    // Saving the password to a file
    printf("Save Generated Password?: ");
    scanf(" %c", &save);

    if(save == 'y' || save == 'Y' ) {
        bool save = true;
        savePassword(save, finalPassword);

    } else {
        printf("Password not saved.\n");
    }

    //system("pause");
    return 0;
}