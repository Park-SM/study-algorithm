#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    string tmp;
    for (int i = 0; i < new_id.length(); i++) {
        if ((new_id[i] >= '0' && new_id[i] <= '9')
            || (new_id[i] >= 'a' && new_id[i] <= 'z' )
            || (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
            tmp += new_id[i];
        }
    }
    new_id = tmp;

    tmp = "";
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] == '.') {
            tmp += '.';
            for (; i < new_id.length(); i++) { if (new_id[i] != '.') break; }
            i--;
        } else {
            tmp += new_id[i];
        }
    }
    new_id = tmp;

    if (new_id[0] == '.') new_id = new_id.substr(1, new_id.length() - 1);
    if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    if (new_id.length() == 0) new_id = "a";
    if (new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[14] == '.') new_id = new_id.substr(0, 14);
    while (new_id.length() < 3) new_id += new_id[new_id.length() - 1];

    
    return new_id;
}