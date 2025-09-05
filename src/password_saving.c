/**
 * File: main.c
 * Author: Nurafiqah
 * Date: 27/05/2025
 * Description: Handles user input, displays menus, and calls functions from other modules.
 * Version: 1.0
 * 
 *  ------------------------------------------------------------------------------------------------
 *  |    Date    | Time  | Service |   Generated Password   | Length | Password Strength | Remarks |
 *  |------------|-------|---------|------------------------|--------|-------------------|---------|
 *  | 28/05/2025 | 15:00 |  gmail  |  Zj3#X6G&!Kh@Q~`u9/tx  |   24   |    Very Strong    | remarks |
 * */

#include "../include/password_generator.h"
#include <fcntl.h>     // for open()
#include <sys/stat.h>  // for S_IRUSR, S_IWUSR

// Data Array
char date[11];             // "dd/mm/yyyy" + null terminator
char timeStr[6];           // "HH:MM" + null terminator
char service[100] = "";    // Service name
char generatedPassword[MAX_LENGTH + 1] = "";
int length;
char passwordStrength[20] = "";
char remarks[200] = "";

//int score = 0; // Global score variable for password strength
// Function to get current date and time
void getCurrentDateTime(char *dateStr, char *timeStr) {
    time_t now = time(NULL);
    struct tm t;
    localtime_r(&now, &t);

    strftime(dateStr, 11, "%d/%m/%Y", &t);
    strftime(timeStr, 6, "%H:%M", &t);
}


// Save password and metadata to a file
void savePassword(bool choice, const char *generatedPassword) {
    if (!choice) {
        printf("Save dialog was canceled or not requested.\n");
        //return false;
    }

    char fileName[MAX_PATH] = "";
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "CSV Files\0*.csv\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "csv";

    if (GetSaveFileName(&ofn)) {
        int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // 0600
        FILE *fp = (fd != -1) ? fdopen(fd, "w") : NULL;
        if (fp != NULL) {
            // Get current date and time
            getCurrentDateTime(date, timeStr);

            // Get the service name
            printf("Enter Service Name: ");
            scanf(" %[^\n]", service);

            // Get the generated password, password length and strength
            length = strlen(generatedPassword);
            int score = scorePasswordStrength(generatedPassword);
            strcpy(passwordStrength, getStrengthLabel(score));

            // Encryption
            //printf("Do You Want to Encrypt the Password?: ");
            //scanf(" %c", &encryptChoice);
            //encryptPassword(generatedPassword, encryptChoice);

            // Get remarks
            printf("Enter Remarks: ");
            scanf(" %[^\n]", remarks);

            printf("Saving....\n");

            // Header and content
            fprintf(fp, "Date,Time,Service,Generated Password,Length,Password Strength,Remarks\n");
            fprintf(fp, "%s,%s,%s,%s,%d,%s,%s\n",
                    date, timeStr, service, generatedPassword, length, passwordStrength, remarks);

            fclose(fp);
            printf("File saved to: %s\n", fileName);
            //return true;
        } else {
            perror("Failed to open file");
            //return false;
        }
    } else {
        printf("User cancelled the save dialog or error occurred.\n");
        //return false;
    }
}