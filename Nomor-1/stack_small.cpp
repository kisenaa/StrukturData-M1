#include <iostream>
#include <stack>

using namespace std;

stack<int> Min_Stack;

void push(int x, stack<int>& S)
{   
    S.push(x);
    // if the tempStack is empty, push the given element into it
    if (Min_Stack.empty()) 
    {
        Min_Stack.push(x);
    }
    else 
    {
        // push the given element into the tempStack
        // if it is less than or equal to the current Min_Stackimum
        if (Min_Stack.top() >= x) 
        {
            Min_Stack.push(x);
        }
    }
}

int pop(stack<int>& S)
{
    if (S.empty())
    {
        cout << "Empty" << endl;
        return -1;
    }

    int top = S.top();
    S.pop();

    // remove the top element from the tempStack
    // only if it is the Min_Stackimum element
    if (top == Min_Stack.top()) {
        Min_Stack.pop();
    }

    return top;
}

int top(stack<int>& S) {
    return S.top();
}

// Returns the size of the stack
int size(stack<int>& S) {
    return S.size();
}

bool empty(stack<int>& S) {
    return S.empty();
}

// Function to return the Min_Stackimum element from the stack in  //constant time
int getMin_Stack()
{
    if (Min_Stack.empty()) {
        cout << "Empty";
        return -1;
    }

    return Min_Stack.top();
}

void printlist(stack<int> S) {
    while (!S.empty()) {
        cout << S.top() << endl;
        S.pop();
    }
}

int main()
{
    stack<int> S;

    push(3, S);
    push(2, S);
    push(1, S);
    // Isi stack dari top : 1 , 2 , 3

    // Print : 1
   cout << "Min_Stack number : " << getMin_Stack() << endl;

   // Hapus top (1)
   pop(S);

   // Print : 2
   cout << "Min_Stack number : " << getMin_Stack() << endl;




    return 0;
}
