#include <iostream>
#include <math.h>
using namespace std;

void max_heapify(int *arr, int i, int n) {
	int left_num = (2*i);
	int right_num = (2*i) + 1;
	int largest = i;

	if(left_num <= n && arr[left_num] > arr[i]) {
		largest = left_num;
	} else {
		largest = i;
	}
	if(right_num <= n && arr[right_num] > arr[largest]) {
		largest = right_num;
	}
	if(largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr, largest, n);
	}
}

void build_heap(int *arr, int n) {
	for(int i=floor(n/2); i>=0; i--) {
		max_heapify(arr,i,n);
	}
}

int main() {
	int n;
	cout << "Enter no. of students : ";
	cin >> n;
	int *arr = new int[n];
	cout << "Enter Marks of M3 : \n";
	for(int i=1;i<=n;i++) {
		cin >> arr[i];
	}
	//HEAP SORT
	build_heap(arr,n);
	for(int i=n;i>=1;i--) {
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;

		max_heapify(arr,1,i-1);
	}
	cout << "Maximum Marks Obtained = " << arr[n] << endl;
	cout << "Minimum Marks Obtained = " << arr[1] << endl;
	return 0;
}
