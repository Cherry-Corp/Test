#include <windows.h>
#include <commdlg.h>
#include <stdio.h>

int main() {
    char fileName[MAX_PATH] = "";

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "CSV Files\0*.csv\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "csv";  // Enforces .csv extension

    if (GetSaveFileName(&ofn)) {
        FILE *fp = fopen(fileName, "w");
        if (fp != NULL) {
            fprintf(fp, "Username,Password\n"); // Header row
            fprintf(fp, "user1,YourGeneratedPassword123!\n"); // Example
            fclose(fp);
            printf("File saved to: %s\n", fileName);
        } else {
            perror("Failed to open file");
        }
    } else {
        printf("Save dialog was canceled or failed.\n");
    }

    return 0;
}
