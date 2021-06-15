#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> target(gems.begin(), gems.end());
    
    int start = 0;
    map<string, int> basket;
    for (int end = 0; end < gems.size(); end++) {
        basket[gems[end]]++;
        if (basket.size() == target.size()) {
            do {
                if (--basket[gems[start]] == 0) {
                    basket.erase(gems[start]);
                    if (answer.size() == 0 || answer[1] - answer[0] > end - start) {
                        answer.clear();
                        answer.push_back(start + 1);
                        answer.push_back(end + 1);
                    }
                    start++;
                    break;
                }
            } while (++start <= end);
        }
    }
    return answer;
}
