/**
 * File: password_generator.c
 * Author: Nurafiqah
 * Date: 27/05/2025
 * Description: password strength checker
 * Version: 1.0
 * */

#include "../include/password_generator.h"

int scorePasswordStrength(const char *password) {
    int score = 0;
    int len = strlen(password);
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSymbol = false;
    bool hasRepeated = false;
    bool dictonary = false;      //rdefault password is randomize 

    for (int i = 0; i < len; i++) {
        if (islower(password[i])) hasLower = true;
        else if (isupper(password[i])) hasUpper = true;
        else if (isdigit(password[i])) hasDigit = true;
        else hasSymbol = true;
    }

    // Criteria scoring
    if (len >= 8) score++;
    if (len >= 12) score++;  // Bonus for long passwords
    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSymbol) score++;
    if (!hasRepeated) score++;
    if (!dictonary) score++;  // If not a dictionary word, add bonus

    return score;
}

const char* getStrengthLabel(int score) {
    if (score <= 2) return "Very Weak"; //won't happen with this program
    else if (score <= 3) return "Weak";
    else if (score <= 4) return "Moderate";
    else if (score == 5) return "Strong";
    else if (score > 6) return "Very Strong";
    else return "Very Weak";            // Default case, should not happen
}