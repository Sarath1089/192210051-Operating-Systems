#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    if (fork() == 0) {
        printf("Enter data: ");
        scanf("%s", str);
        printf("Child process wrote in memory: %s\n", str);
        shmdt(str);
    } else {
        wait(NULL);
        printf("Parent reads from memory: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

