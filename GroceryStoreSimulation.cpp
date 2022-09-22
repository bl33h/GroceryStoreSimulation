/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: GroceryStoreSimulaation
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