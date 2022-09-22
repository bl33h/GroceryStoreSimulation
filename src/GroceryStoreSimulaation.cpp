/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: GroceryStoreSimulation
@version: I
Creation: 22/09/2022
Last modification: 22/09/2022
------------------------------------------------------------------------------*/
// Imports
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <math.h>
#include <errno.h>
#include <sys/wait.h>
#include <cstdint>
#include <sstream>
#include <fstream>

// Namespace
using namespace std;

// --- Mutex lock ---
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Counter
int counter;

// Cash register schedules
string openingHours[6] = {"3:00pm", "4:00pm", "5:00pm", "6:00pm", "7:00pm", "8:00pm"};
string closingHours[6] = {"4:00pm", "5:00pm", "6:00pm", "7:00pm", "8:00pm", "9:00pm"};

// --- Structure for the cash register control ---
struct cashRegisters{
    int clientsPerCashRegister = 0;
    int clientsByCashRegister = 0;
    int clientsNumb = 0;
};

// --- First cash register method ---
void *cashRegister1(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 1 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Second cash register method ---
void *cashRegister2(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 2 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Third cash register method ---
void *cashRegister3(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 3 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Fourth cash register method ---
void *cashRegister4(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 4 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Fifth cash register method ---
void *cashRegister5(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 4 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Sixth cash register method ---
void *cashRegister6(void *clientsNumb)
{
    cashRegisters *cashRegistersStructure = (cashRegisters*) clientsNumb; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Cash register No. 4 has served 1 client."<<endl;
    cashRegistersStructure->clientsByCashRegister += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// Main method
int main()
{
    int clientsNumb;
    double supervisor;
    bool finalClientsPerCashRegister = false; // *Boolean for the total of clients
    cashRegisters groceryStore;
    pthread_t tid[6];
    pthread_attr_t attr;
    cout << "Type the number of clients to attend (int) = " << endl;
    cin >> clientsNumb;
    int clientsPerCashRegister = clientsNumb / 21;
      while(finalClientsPerCashRegister == false){
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
        supervisor = pthread_create(&tid[0],&attr,cashRegister6,(void *)&groceryStore);
        supervisor = pthread_join(tid[0],NULL);
        // *First condition*
        if(groceryStore.clientsNumb > 0)
        {
            groceryStore.clientsByCashRegister += 1;
            supervisor = pthread_create(&tid[1],&attr,cashRegister1,(void *)&groceryStore);
            supervisor = pthread_join(tid[1],NULL);
            sleep(1);
            groceryStore.clientsByCashRegister = clientsPerCashRegister;
            finalClientsPerCashRegister = true;     
            
        }
          
      }
    // *Final print*
    cout<<"Total of clients: " + clientsNumb <<endl;
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return 0;
}