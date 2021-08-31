#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    unordered_map<string, int> courseMap;
    for (int i = 0; i < orders.size() - 1; i++) {
        for (int j = i + 1; j < orders.size(); j++) {
            vector<char> s;
            for (int k = 0; k < orders[j].length(); k++) {
                if (orders[i].find(orders[j][k]) != string::npos) s.push_back(orders[j][k]);
            }
            if (s.size() < 2) continue;
            
            for (int c = 0; c < course.size(); c++) {
                sort(s.begin(), s.end());
                do {
                    if (s.size() < course[c]) break;
                    string croped(s.begin(), s.begin() + course[c]);
                    vector<char> tmp(croped.begin(), croped.end());
                    sort(tmp.begin(), tmp.end());
                    string sorted(tmp.begin(), tmp.end());
                    courseMap[sorted]++;
                } while(next_permutation(s.begin(), s.end()));
            }
        }
    }
    
    for (auto it = courseMap.begin(); it != courseMap.end(); it++) it->second = 0;
    for (auto it = courseMap.begin(); it != courseMap.end(); it++) {
        for (int i = 0; i < orders.size(); i++) {
            string target = it->first;
            bool isEquals = true;
            for (int j = 0; j < target.length(); j++) {
                if (orders[i].find(target[j]) == string::npos) isEquals = false;
            }
            if (isEquals) courseMap[target]++;
        }
    }
    
    for (int i = 0; i < course.size(); i++) {
        vector<pair<string, int>> result;
        for (auto it = courseMap.begin(); it != courseMap.end(); it++) {
            if (it->first.length() == course[i] && it->second >= 2) {
                 result.push_back(*it);
            }
        }
        if (result.size() == 0) continue;
        
        sort(result.begin(), result.end(), compare);
        answer.push_back(result[0].first);
        for (int i = 1; i < result.size(); i++) {
            if (result[0].second == result[i].second) {
                answer.push_back(result[i].first);
            } else break;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}