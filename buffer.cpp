#include <iostream>
#include "buffer.h" 
using namespace std;

// void BoundedBuffer::print_buffer(){          uncomment if needed
//     for (int i=0; i<BUFFER_SIZE; i++){
//         cout << buffer[i] << " - "; 
//     }
//     cout << endl;
// }

// Constructor
BoundedBuffer::BoundedBuffer(){
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
}

// Producer
int BoundedBuffer::insert_item(buffer_item item){
    try{
        sem_wait(&empty);
        
        pthread_mutex_lock(&mutex);
            static int in = 0;
            buffer[in] = item;
            in = (in+1)%BUFFER_SIZE;
            // print_buffer();          uncomment if needed
        pthread_mutex_unlock(&mutex);

        sem_post(&full);

        return 0;
    }
    catch(...){
        return -1;
    }
}

// Consumer
int BoundedBuffer::remove_item(buffer_item *item){
    try{
        sem_wait(&full);
        
        pthread_mutex_unlock(&mutex);
            static int out = 0;
            *item = buffer[out];
            out = (out+1)%BUFFER_SIZE;
            // print_buffer();          uncomment if needed
        pthread_mutex_unlock(&mutex);

        sem_post(&empty);

        return 0;
    }
    catch(...){
        return -1;
    }
}

// Destructor
BoundedBuffer::~BoundedBuffer(){
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}