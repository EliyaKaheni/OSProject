Operation System Project / 2024-2025 / Computer Science IUST 

Project 4 —The Producer – Consumer Problem

## Project problem:
For this project, you will use standard counting semaphores
for empty and full and a mutex lock, rather than a binary semaphore, to
represent mutex. The producer and consumer—running as separate threads
—will move items to and from a buffer that is synchronized with the empty,
full, and mutex structures. You can solve this problem using either Pthreads
or the Windows API.

## Project Structure
OSProj.cpp: Contains the main function and the producer/consumer thread functions.
buffer.cpp: Implements the BoundedBuffer class with methods for inserting and removing items.
buffer.h: Defines the interface for the BoundedBuffer class.

## Compilation & Execution
compilation: g++ -o producer_consumer OSProj.cpp buffer.cpp -pthread
execution: ./producer_consumer <sleep_time> <num_producers> <num_consumers>
--------------------------
<sleep_time>: Time (in seconds) to run the program before canceling threads.
<num_producers>: Number of producer threads.
<num_consumers>: Number of consumer threads.

## BoundedBuffer Structure
empty: Signals the availability of empty slots in the buffer.
full: Signals the availability of full slots in the buffer.
Mutex:Protects critical sections of code where the buffer is accessed (insertion and removal) to prevent race conditions.

## Main Idea
This implementation demonstrates a basic producer-consumer problem using threads and semaphores in C++.
The use of semaphores and a mutex ensures correct synchronization and prevents data corruption in the shared buffer.
This approach can be extended to more complex scenarios with varying buffer sizes, different producer/consumer rates, and more sophisticated synchronization mechanisms.

## Contributers
Iliya Kaheni
Hamidreza Entezari
Alireza Dehghani EshratAbad
Instructor: Mahmoud Shirazi Ph.D.
