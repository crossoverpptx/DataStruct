#include <iostream>

int Partition(int arr[], int low, int high) {
	int pivot = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= pivot) {
			--high;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) {
			++low;
		}
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}

int main() {
	int arr[] = { 7, 23, 19, 9, 33, 76, 55, 98, 3, 19, 0, 31 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, len - 1);
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
