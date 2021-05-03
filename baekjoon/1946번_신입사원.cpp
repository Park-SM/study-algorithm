#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;
 
int grades[100001];

int main() {
    IN_OPT;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int f, s; cin >> f >> s;
            grades[f] = s;
        }
        
        int count = 1, cutLine = grades[1];
        for (int j = 2; j <= n; j++) {
            if (grades[j] < cutLine) {
            	cutLine = grades[j];
            	count++;
            }
        }
        cout << count << "\n";
    }
}
