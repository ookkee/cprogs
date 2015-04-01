#include<stdio.h>
#include<signal.h>

void bomb(int);
void refuel(int);
void killer(int);

int main() {
    
    int fuel = 100;
    int counter = 0;
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    signal(SIGUSR1, bomb);
    signal(SIGUSR2, refuel);
    //signal(ppid, killer);

    printf("\nLaunched plane %d\n", pid);

    while(1) {
        counter++;
        //reduce fuel by 5 every second
        sleep(1);
        fuel -= 5;
        //inform about fuel every 3 seconds
        if(counter == 3) {
            counter = 0;
            printf("\nFuel status %d: %d", pid, fuel);
            if(fuel < 30) printf(" BINGO FUEL!");
            printf("\n");
        }
        //if fuel <= 0 send SIGUSR2 to parent (getppid) and die
        if(fuel <= 0) {
            kill(getppid(), SIGUSR2);
            break;
        }
    }

    return 0;
}

void bomb(int signal) {
    printf("\nPlane %d dropped bombs!\n", getpid());
}

void refuel(int signal) {
    //*fuel = 100;
    //printf("Plane %d refueled!\n", getpid());
    printf("\nPlane %d How do I access my fuel from outside the scope?!\n", getpid());
}

//void killer(int signal) {
//    raise(ppid, SIGUSR2);
//    exit(SIGUSR2);
//}
