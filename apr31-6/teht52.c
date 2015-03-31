#include<stdio.h>
#include<signal.h>
#include<string.h>

int main() {

    signal(SIGUSR2, sos);
    int cpid[50] = 0;
    int planes = 0;
    char cmd[10];

    while(1) {
        //wait for command
        printf(" > ");
        fgets(cmd, sizeof(cmd), stdin);

        if(!strcmp(cmd, "quit")) {
            break;
        }
        else if (!strcmp(cmd, "launch")) {
            cpid[planes++] = fork();
            if(cpid[planes - 1] == 0) execvp("./plane", "");
        }
        //"launch" forks new process (execvp new "codebase")
        //
        //"status" lists all planes (i.e. their pid's)
        //
        //"bomb N" sends SIGUSR1 to process N
        //
        //"refuel N" sends SIGUSR2 to process N
        //
        //this process receiving SIGUSR2 prints distress message
    }

    return 0;
}

void sos(int signal) {
    printf("SOS! A plane has crashed\n");
}
