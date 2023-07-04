#include <iostream>
#include <vector>
using namespace std;

// �鲢
int merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> temp(right - left + 1);  // ��ʱ���飬���ڴ洢�鲢���
	int i = left;  // ����������±�
	int j = mid + 1;  // ����������±�
	int k = 0;  // ��ʱ������±�
	int count = 0;
	while (i <= mid && j <= right) {
		// ֻҪ����������������Ԫ��δ��ȡ�꣬�ͽ��бȽ�
		if (arr[i] <= arr[j]) {
			// ���������е�Ԫ�ظ�С�������������
			temp[k++] = arr[i++];
		} else {
			// ���������е�Ԫ�ظ�С�����������
			temp[k++] = arr[j++];
			count += mid - i + 1;  // ͳ������Ը���
		}
	}
	while (i <= mid) {
		// ����������黹��ʣ�ֱ࣬�Ӽ�����ʱ����
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		// ����������黹��ʣ�ֱ࣬�Ӽ�����ʱ����
		temp[k++] = arr[j++];
	}
	for (int n = 0; n < k; n++) {
		// ����ʱ�����е�Ԫ�ظ��ƻ�ԭ����
		arr[left + n] = temp[n];
	}
	return count;
}

// �鲢����
int mergeSort(vector<int> &arr, int left, int right) {
	if (left >= right) {
		// �������鳤��Ϊ1ʱ�����ٷָ�
		return 0;
	}
	int mid = left + (right - left) / 2;  // �ָ�����
	int leftCount = mergeSort(arr, left, mid);  // ͳ���������������Ը���
	int rightCount = mergeSort(arr, mid + 1, right);  // ͳ���������������Ը���
	int allCount = merge(arr, left, mid, right);  // ͳ�ƿ�Խ�������������������Ը���
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
		cout << count << endl;  // �������Ը���
	}

	return 0;
}
