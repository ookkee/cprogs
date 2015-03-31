#include<stdio.h>
#include<signal.h>

int main() {
    
    //fuel = 100
    int fuel = 100;
    int counter = 0;
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    signal(SIGUSR1, bomb);
    signal(SIGUSR2, refuel);
    signal(SIGKILL, killer);

    printf("Launched plane %d\n", pid);

    while(1) {
        counter++;
        //reduce fuel by 5 every second
        sleep(1);
        fuel -= 5;
        //inform about fuel every 3 seconds
        if(counter == 3) {
            counter = 0;
            printf("Fuel status: %d %d", pid, fuel);
            if(fuel < 30) printf(" BINGO FUEL!");
            printf("\n");
        }
        //if fuel <= 0 send SIGUSR2 to parent (getppid) and die
        if(fuel <= 0) {
            kill();
        }
    }

    return 0;
}

void bomb(int signal) {
    printf("Plane nr. %d dropped bombs!\n", pid);
}

void refuel(int signal) {
    fuel = 100;
    printf("Plane nr. %d refueled!\n", pid);
}

void killer(int signal) {
    raise(ppid, SIGUSR2);
    exit(SIGUSR2);
}
