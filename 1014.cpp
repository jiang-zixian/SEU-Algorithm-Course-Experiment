#include <iostream>
#include <vector>
using namespace std;

vector<int> FindMaxCrossingSubarray(vector<int> &A, int low, int mid, int high) {
	vector<int>nums(3, 1);
	int leftSum = 0xc0c0c0c0;
	int rightSum = 0xc0c0c0c0;
	int maxLeft, maxRight;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum = sum + A[i];
		if (sum > leftSum) {
			maxLeft = i;
			leftSum = sum;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum = sum + A[j];
		if (sum > rightSum) {
			maxRight = j;
			rightSum = sum;
		}
	}
	nums[0] = maxLeft;
	nums[1] = maxRight;
	nums[2] = leftSum + rightSum;
	return nums;
}

vector<int> FindMaxSubarray(vector<int> &A, int low, int high) {

	vector<int>nums = { low, high, A[low] };
	vector<vector<int>>answers(3, nums);
	if (low == high) {
		return nums;
	} else {
		int mid = (low + high) / 2;
		answers[0] = FindMaxSubarray(A, low, mid);
		answers[1] = FindMaxSubarray(A, mid + 1, high);
		answers[2] = FindMaxCrossingSubarray(A, low, mid, high);
		if (answers[0][2] >= answers[1][2] && answers[0][2] >= answers[2][2]) {
			return answers[0];
		} else if (answers[1][2] >= answers[0][2] && answers[1][2] >= answers[2][2]) {
			return answers[1];
		} else {
			return answers[2];
		}
	}
}

int main() {
	int m, n;
	cin >> m;
	while (m--) {
		cin >> n;
		vector<int>h(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		cout << FindMaxSubarray(h, 0, h.size() - 1)[2] << endl;
	}
	return 0;
}