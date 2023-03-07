/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

// Node Structure
struct QueueNode {
    char string[101];
    QueueNode *next;
};

/* Structure of Queue using List */
struct Queue
{
    QueueNode *_front, *_rear;
    unsigned _size;

    void init()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(const char* string)
    {
        QueueNode *newNode =\
            (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            strcpy (newNode->string, string);
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    char* front()
    {
        if (!isEmpty())
            return _front->string;
        exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek queue
    Queue myQueue;
    // PENTING!! Jangan lupa di-init()
    myQueue.init();

    myQueue.push("Jakarta");
     myQueue.push("Bandung");
     myQueue.push("Surabaya");

    // Cetak isi queue
    while (!myQueue.isEmpty()) {
        printf("%s\n", myQueue.front());
        myQueue.pop();
    }
    puts("");
    return 0;
}
