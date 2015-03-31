#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

void sos(int);
void oops(int);

int main() {

    signal(SIGUSR2, sos);
    signal(SIGUSR1, oops);

    int cpid[50] = {0};
    int planes, i;
    char cmd[10];
    char *token;
    char delim[] = " \n";
    planes = 0;

    char *args[2];
    args[0] = "not";
    args[1] = "important";

    while(1) {
        //wait for command
        printf(" > ");
        fgets(cmd, sizeof(cmd), stdin);
        //printf("%s\n", cmd);
        token = strtok(cmd, delim);

        if(!strcmp(token, "quit")) {
            break;
        }
        //"launch" forks new process (execvp new "codebase")
        else if (!strcmp(token, "launch")) {
            cpid[planes] = fork();
            if(cpid[planes] == 0) {
                execvp("./plane", args);
            }
            else {
                planes += 1;
            }
        }
        //"status" lists all planes (i.e. their pid's)
        else if (!strcmp(token, "status")) {
            for(i=0; i<50; i++) {
                if(cpid[i] != 0) printf("%d\n", cpid[i]);
            }
        }
        //"bomb N" sends SIGUSR1 to process N
        else if (!strcmp(token, "bomb")) {
            token = strtok(NULL, delim);
            if(token != NULL)
                kill(atoi(token), SIGUSR1);
            //printf("bomb\n");
        }
        //
        //"refuel N" sends SIGUSR2 to process N
        else if (!strcmp(token, "refuel")) {
            token = strtok(NULL, delim);
            if(token != NULL)
                kill(atoi(token), SIGUSR2);
        }
        //
        //this process receiving SIGUSR2 prints distress message
        else {}
    }

    return 0;
}

void sos(int signal) {
    printf("SOS! A plane has crashed\n");
}

void oops(int signal) {
    printf("You went to the toilet!\n");
}
