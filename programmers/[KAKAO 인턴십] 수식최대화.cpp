#include <bits/stdc++.h>

using namespace std;

long long _cal(long long a, long long b, char op) {
    switch(op) {
        case '*': return a * b;
        case '+': return a + b;
        case '-': return a - b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> ops, op;
    string bufNum = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            ops.push_back(expression[i]);
            nums.push_back(stoll(bufNum));

            if (find(op.begin(), op.end(), expression[i]) == op.end()) {
                op.push_back(expression[i]);
            }
            bufNum = "";
        } else {
            bufNum += expression[i];
        }
    }
    nums.push_back(stoll(bufNum));

    sort(op.begin(), op.end());
    do {
        vector<long long> tmpNums = nums;
        vector<char> tmpOps = ops;

        for (int o = 0; o < op.size(); o++) {
            for (int i = 0; i < tmpOps.size(); i++) {
                if (op[o] == tmpOps[i]) {
                    tmpNums[i] = _cal(tmpNums[i], tmpNums[i+1], tmpOps[i]);
                    tmpNums.erase(tmpNums.begin() + i + 1);
                    tmpOps.erase(tmpOps.begin() + i);
                    i--;
                }
            }
        }
        answer = max(answer, abs(tmpNums[0]));
    } while (next_permutation(op.begin(), op.end()));

    return answer;
}
