#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int signal_num;
    pid_t pid;

    // Get signal number and process id from user
    printf("Enter signal number: ");
    scanf("%d", &signal_num);

    printf("Enter process id: ");
    scanf("%d", &pid);

    // Send signal to the process using kill() syscall
    if (kill(pid, signal_num) == 0) {
        printf("Signal %d sent to process %d successfully.\n", signal_num, pid);
    } else {
        perror("Error sending signal");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
