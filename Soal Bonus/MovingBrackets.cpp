#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
    // Disable fitur flush dari output dan input untuk boost peformance execution time
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
 
    int testCase;
    cin >> testCase;
 
 
    for (int i=0; i<testCase; i++) {
        queue<char> q;
        int amount;
        char bracket;
 
        cin >> amount;
        int c=0;
 
        for (int j=0; j<amount; j++)
        {
            cin >> bracket;
 
            if (bracket == '(') {
                q.push('(');
            } else if (bracket == ')') {
                if (!q.empty()) {
                    q.pop();
                } else {
                    c++;
                }
            }
        }
    
        cout << c << endl;
    }
 
    return 0;
}
