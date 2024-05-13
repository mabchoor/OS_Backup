#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Define variables for source and backup folders
    char *source_folder = "test";
    char *backup_folder = "test_backup";

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process executing folder_backup.sh\n");
        // Pass source_folder and backup_folder as arguments to folder_backup.sh
execl("/bin/sh", "/bin/sh", "-c", "./folder_backup.sh", source_folder, backup_folder, (char *)NULL);
    } else {
        // Parent process
        printf("Parent process waiting for child to finish\n");
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}
