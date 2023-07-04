#include <iostream>
#include <vector>
using namespace std;

// 归并
int merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> temp(right - left + 1);  // 临时数组，用于存储归并结果
	int i = left;  // 左子数组的下标
	int j = mid + 1;  // 右子数组的下标
	int k = 0;  // 临时数组的下标
	int count = 0;
	while (i <= mid && j <= right) {
		// 只要左右两个子数组有元素未被取完，就进行比较
		if (arr[i] <= arr[j]) {
			// 左子数组中的元素更小，不构成逆序对
			temp[k++] = arr[i++];
		} else {
			// 右子数组中的元素更小，构成逆序对
			temp[k++] = arr[j++];
			count += mid - i + 1;  // 统计逆序对个数
		}
	}
	while (i <= mid) {
		// 如果左子数组还有剩余，直接加入临时数组
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		// 如果右子数组还有剩余，直接加入临时数组
		temp[k++] = arr[j++];
	}
	for (int n = 0; n < k; n++) {
		// 将临时数组中的元素复制回原数组
		arr[left + n] = temp[n];
	}
	return count;
}

// 归并排序
int mergeSort(vector<int> &arr, int left, int right) {
	if (left >= right) {
		// 当子数组长度为1时，不再分割
		return 0;
	}
	int mid = left + (right - left) / 2;  // 分割数组
	int leftCount = mergeSort(arr, left, mid);  // 统计左子数组的逆序对个数
	int rightCount = mergeSort(arr, mid + 1, right);  // 统计右子数组的逆序对个数
	int allCount = merge(arr, left, mid, right);  // 统计跨越左右两个子数组的逆序对个数
	return leftCount + rightCount + allCount;
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int num = 0;
		cin >> num;
		vector<int> arr(num);
		for (int j = 0; j < num; j++) {
			cin >> arr[j];
		}
		int count = mergeSort(arr, 0, arr.size() - 1);
		cout << count << endl;  // 输出逆序对个数
	}

	return 0;
}
