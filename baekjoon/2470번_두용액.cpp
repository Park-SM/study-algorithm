#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    
    int s = 0, e = n - 1;
    int left, right, min = INT_MAX;
    while (s < e) {
        if (abs(arr[s] + arr[e]) < min) {
            min = abs(arr[s] + arr[e]);
            left = s;
            right = e;
        }
        if (arr[s] + arr[e] < 0) {
            s++;
        } else {
            e--;
        }
    }
    cout << arr[left] << " " << arr[right];
}
