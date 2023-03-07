#include <iostream>
#include <string.h>
#include <queue>

struct p_queue
{
    int id;
    int priority;

    bool operator<(const p_queue & other) const {
        return priority < other.priority;
    }
};

using namespace std;

int main() {
    priority_queue<p_queue> s;

    int number;
    char str[7];
    cin >> number;

    for (int i=0; i<number; i++) {
        int priority,id;
        cin >> str;

        if (strcmp ("MASUK", str) == 0) {
            cin >> id >> priority;
            s.push({id,priority});
        } else {
            if (!s.empty()) {
                cout << s.top().id << endl;
                s.pop();
            }
        }
    }

    if (s.empty()) {
        cout << "HORE" << endl;
    }

    return 0;
}
