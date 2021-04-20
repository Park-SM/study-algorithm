#include <bits/stdc++.h>
using namespace std;

int main() {
    string input, tmp = "";
    cin >> input;
    
    int result = 0;
    bool isPlus = true;
    for (int i = 0; i <= input.size(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == NULL) {
            if (isPlus) {
                result += stoi(tmp);
            } else {
                result -= stoi(tmp);
            }
            tmp = "";
            if (input[i] == '-') {
                isPlus = false;
            }
            continue;
        }
        tmp += input[i];
    }
    cout << result;
}
