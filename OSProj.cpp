#include <iostream>
#include <unistd.h>
#include "buffer.h"
using namespace std;

void *producer(void *param){
    BoundedBuffer *buffer = static_cast<BoundedBuffer*>(param); 
    buffer_item item;
    while(true){
        sleep(rand()%3);
        item = rand()%100;

        if (buffer->insert_item(item) == -1)
            cout << "Error in inserting item." << endl;
        else
            cout << "Producer produced " << item << endl;
    }
}

void *consumer(void *param){
    BoundedBuffer *buffer = static_cast<BoundedBuffer*>(param);
    buffer_item item;
    while(true){
        sleep(rand()%3);
        if (buffer->remove_item(&item) == -1)
            cout << "Error in removing item." << endl;
        else
            cout << "Consumer consumed " << item <<endl;
    }
}

int main(int argc, char *argv[]){
    if (argc != 4){
        cout << "Input must be this way: " << endl;
        cout << "g++ -o producer_consumer OSProj.cpp buffer.cpp -pthread" << endl;
        cout << "./producer_consumer <sleep_time> <num_producers> <num_consumers>";
    }

    int sleep_time = atoi(argv[1]);
    int num_producers = atoi(argv[2]);
    int num_consumers = atoi(argv[3]);

    BoundedBuffer buffer;
    pthread_t consumers[num_consumers];
    pthread_t producers[num_producers];

    for(int i=0; i<num_producers; i++){
        if (pthread_create(&producers[i], NULL, producer, &buffer)){
            cout<<"Error in creating a producer" << endl;
            return 1;
        }
    }

    for(int i=0; i<num_consumers; i++){
        if (pthread_create(&consumers[i], NULL, consumer, &buffer)){
            cout<<"Error in creating a consumer" << endl;
            return 1;
        }
    }

    sleep(sleep_time);

    for(int i=0; i<num_consumers; i++){
        pthread_cancel(consumers[i]);
    }
    for(int i=0; i<num_producers; i++){
        pthread_cancel(producers[i]);
    }

    return 0;
}