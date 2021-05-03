#include <bits/stdc++.h>
using namespace std;

vector<int> personTimes;

int main() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		personTimes.push_back(t);
	}
	sort(personTimes.begin(), personTimes.end());

	int result = 0;
	int time = 0;
	for (int i = 0; i < personTimes.size(); i++) {
		time += personTimes[i];
		result += time;
	}
	cout << result;
}
