#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char folder_name[2];
    int i;

    for (i = 0; i < 26; i++) {
        folder_name[0] = 'A' + i;
        folder_name[1] = '\0';

        struct stat st = {0};
        if (stat(folder_name, &st) == -1) {
            mkdir(folder_name, 0700);
            printf("Folder %s created.\n", folder_name);
        }
        else {
            printf("Folder %s already exists.\n", folder_name);
        }
    }

    return 0;
}