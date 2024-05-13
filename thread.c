#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define variables for source and backup folders
char *source_folder = "test";
char *backup_folder = "test_backup";

void *backup_thread(void *arg) {
    printf("Thread executing folder_backup.sh\n");
    // Pass source_folder and backup_folder as arguments to folder_backup.sh using execl
    execl("/bin/sh", "/bin/sh", "-c", "./folder_backup.sh", source_folder, backup_folder, (char *)NULL);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    printf("Parent process creating thread\n");
    pthread_create(&thread, NULL, backup_thread, NULL);
    pthread_join(thread, NULL);
    printf("Thread finished\n");
    return 0;
}
