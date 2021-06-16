#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    unordered_map<string, vector<int>> type;
    string input[4], score;
    
    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        ss >> input[0] >> input[1] >> input[2] >> input[3] >> score;
        
        for (int i = 0; i < 16; i++) {
            string tmp = "";
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) tmp += "-";
                else tmp += input[j];
            }
            type[tmp].push_back(stoi(score)); 
        }
    }
    
    for (auto it = type.begin(); it != type.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    
    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        ss >> input[0] >> score >> input[1] >> score >> input[2] >> score >> input[3] >> score;
        
        vector<int> users = type[input[0] + input[1] + input[2] + input[3]];
        int idx = lower_bound(users.begin(), users.end(), stoi(score)) - users.begin();
        answer.push_back(users.size() - idx);
    }
    return answer;
}
