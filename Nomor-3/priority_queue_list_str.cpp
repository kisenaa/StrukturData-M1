/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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

struct PQueueNode {
    char data[101];
    PQueueNode *next;
};

// Default priority: minimum
struct PriorityQueue
{
    PQueueNode *_top;
    unsigned _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(const char*  value)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        strcpy(newNode->data, value);
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (strcmp (value, _top->data) >0) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && strcmp (temp->next->data, value) >0)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    char* top()
    {
        if (!isEmpty()) return _top->data;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    PriorityQueue Pqueue;

    Pqueue.init();

    Pqueue.push("angin");
    Pqueue.push("beruang");
    Pqueue.push("singa");
    Pqueue.push("zebra");


    while (!Pqueue.isEmpty())
    {
        printf("%s\n", Pqueue.top());
        Pqueue.pop();
    }
    
    return 0;
}
