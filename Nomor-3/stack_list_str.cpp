/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
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

// Node structure
struct StackNode {
    char _str[100];
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(const char* string)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;

            strcpy (newNode->_str, string);

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    char* top()
    {
        if (!isEmpty())
            return _top->_str;
        exit(-1);
    }


};

int main(int argc, char const *argv[])
{
    // Buat objek stack
    Stack myStack;
    // PENTING!! Jangan lupa di-init
    myStack.init();

    myStack.push("Bandung");
    myStack.push("Jakarta");
    myStack.push("Surabaya");

    myStack.pop();

    // Cetak isi stack
    while (!myStack.isEmpty()) {
        printf("%s\n", myStack.top());
        myStack.pop();
    }
    puts("");
    return 0;
}
