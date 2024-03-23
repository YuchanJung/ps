#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001] = {0};
int N, M;
int low = 0, high = 0;
int res = 0; 

void search() {
	while (low <= high) {
		int mid = (low + high) / 2;
		
		long long sum = 0;
		for (auto i = 0; i < N; i++) {
			if (arr[i] > mid)
			    sum += (arr[i] - mid);
		}
		if (sum >= M) {
            res = mid;
			low = mid + 1;
		}
		if (sum < M) {
			high = mid - 1;
		}
	}
    cout << res;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
        high = max(high, arr[i]);
	}
	search();
}