#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/time.h>

#define SEAT_COUNT 100
#define SEAT_ROWS 10
#define SEAT_COLUMNS 10

#define H_SELLERS 1
#define M_SELLERS 3
#define L_SELLERS 6

#define MAX_WAITING_DURATION 10     //If person waits for 10 mins leaves.
#define SELLING_DURATION 60     //Sell tickets for 60 mins

char seats[SEAT_ROWS][SEAT_COLUMNS]; //Matrix of the auditorium

pthread_mutex_t seatMutex;  //mutex protects the seats a (shared resource)
sem_t filledH;              //seller H waits on this
sem_t filledM;              //sellers M wait on this
sem_t filledL;              //sellers L wait on this

struct itimerval HsellersTimer;
struct itimerval MsellersTimer;
struct itimerval LsellersTimer;
time_t startTime;

void hSellsTickets() {
    char event[80];
    
}

void customerArrivesAtH(int id) {
    char event[80];
    arrivalCount++;
    
    if (waitOnH < H_SELLERS) {
        //acquire the mutex lock to protect the seats
        pthread_mutex_lock($seatMutex);
        
        //
    }
}

void *hSeller(void *param) {
    time(&startTime);
    print("H ticket seller opens");
    
    //Set timer for ticket selling duration
    HsellersTimer.it_value.tv_sec = SELLING_DURATION;
    setitimer(ITIMER_REAL, &HsellersTimer, NULL);
    
    //Sell tickets until duration is over
    do {
        hSellsTickets();
    } while (!timesUp);
    
    print("H ticket seller closes");
    
    return NULL;
}

void *mSeller(void *param) {
    time(&startTime);
    print("M ticket seller opens");
    
    //Set timer for ticket selling duration
    MsellersTimer.it_value.tv_sec = SELLING_DURATION;
    setitimer(ITIMER_REAL, &MsellersTimer, NULL);
    
    //Sell tickets until duration is over
    do {
        mSellsTickets();
    } while (!timesUp);
    
    print("M ticket seller closes");
    
    return NULL;
}

void *lSeller(void *param) {
    time(&startTime);
    print("M ticket seller opens");
    
    //Set timer for ticket selling duration
    LsellersTimer.it_value.tv_sec = SELLING_DURATION;
    setitimer(ITIMER_REAL, &LsellersTimer, NULL);
    
    //Sell tickets until duration is over
    do {
        lSellsTickets();
    } while (!timesUp);
    
    print("L ticket seller closes");
    
    return NULL;
}


int main(int argc, char *argv[]) {
    int n;
    int HsellerId = 0;
    int MsellerId = 0;
    int LsellerId = 0;
    
    //Check for only one command-line argument
    if (argc != 2) { printf("Usage: requires 1 integer argument\n"); }
    else { 
        n = atoi(argv[1]); 
        printf("%d\n", n);
    }
    
    
    return 0;
}