/**
 * File: password_generator.h
 * Author: Nurafiqah
 * Date: 27/05/2025
 * Description: Contains the header for generating passwords
 * Version: 1.0
 * */

#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <commdlg.h>
#include <stdio.h>

//#ifdef _WIN32
//#include <windows.h>
//#else
#include <fcntl.h>
#include <unistd.h>
//#endif

#define MAX_LENGTH 64   // Max possible characters
#define MIN_LENGTH 24   // Min possible characters

// Global score variable
//extern int score;

// Password Generator
void generatePassword(char *password, int length);
int getPasswordLength();
char getRandomUppercase();
char getRandomLowercase();
char getRandomDigit();
char getRandomSymbol();
void removeDuplicates(char *str);

// Password Strength Checker
int scorePasswordStrength(const char *password);
const char* getStrengthLabel(int score);

// Password Saving
void savePassword(bool choice, const char *generatedPassword);
void getCurrentDateTime(char *dateStr, char *timeStr);

// Cryptography

#endif