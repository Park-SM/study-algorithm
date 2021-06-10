#include <bits/stdc++.h>

using namespace std;

int getManhattanDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> leftThumb = {0, 3};
    pair<int, int> rightThumb = {2, 3};
    
    for (int i = 0 ; i < numbers.size(); i++) {
        int input = numbers[i];
        switch (input) {
            case 1: case 4: case 7: answer += "L"; leftThumb = {0, (input - 1) / 3}; break;
            case 3: case 6: case 9: answer += "R"; rightThumb = {2, (input / 3) - 1}; break;
            default:
                int y = (input == 0) ? 3 : (input / 3);
                int leftMahattanDist = getManhattanDist(leftThumb, {1, y});
                int rightMahattanDist = getManhattanDist(rightThumb, {1, y});
                if (leftMahattanDist < rightMahattanDist) {
                    answer += "L";
                    leftThumb = {1, y};
                } else if (leftMahattanDist > rightMahattanDist) {
                    answer += "R";
                    rightThumb = {1, y};
                } else {
                    if (hand == "left") {
                        answer += "L";
                        leftThumb = {1, y};
                    } else {
                        answer += "R";
                        rightThumb = {1, y};
                    }
                }
                break;
        }
    }
    
    return answer;
}
