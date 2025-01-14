/* buffer.h */
#include <semaphore.h>
#include <pthread.h>

typedef int buffer_item;
#define BUFFER_SIZE 5

class BoundedBuffer{
    public:
        buffer_item buffer[BUFFER_SIZE];
        sem_t full;
        sem_t empty;
        pthread_mutex_t mutex;

        BoundedBuffer();
        ~BoundedBuffer();

        int insert_item(buffer_item item);
        int remove_item(buffer_item *item);

        // void print_buffer();          uncomment if needed

};