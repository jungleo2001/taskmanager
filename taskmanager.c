#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/select.h>

#define MAX_PATH_LEN 1024
#define REFRESH_INTERVAL 2

void display_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LEN];

    printf("\033[2J\033[H"); // Clear the screen
    printf("PID    |    Process Name\n");
    printf("-------------------------\n");

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            snprintf(path, MAX_PATH_LEN, "/proc/%s/comm", entry->d_name);
            FILE *file = fopen(path, "r");
            if (file != NULL) {
                char process_name[MAX_PATH_LEN];
                fgets(process_name, MAX_PATH_LEN, file);
                fclose(file);
                process_name[strcspn(process_name, "\n")] = '\0'; // Remove trailing newline
                printf("%-6s |    %s\n", entry->d_name, process_name);
            }
        }
    }

    closedir(dir);
}

void kill_process() {
    char pid_str[10];
    printf("Enter the PID of the process to kill (0 to cancel): ");
    scanf("%9s", pid_str);
    int pid = atoi(pid_str);
    if (pid == 0) {
        return; // Cancel killing process
    }
    if (kill(pid, SIGKILL) == 0) {
        printf("Process with PID %d killed successfully.\n", pid);
    } else {
        perror("Error killing process");
    }
}

int main() {
    while (1) {
        display_processes();

        // Check if there is any input from the user
        struct timeval tv = {0, 0};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

        if (FD_ISSET(STDIN_FILENO, &fds)) {
            kill_process();
        }

        sleep(REFRESH_INTERVAL);
    }

    return 0;
}
