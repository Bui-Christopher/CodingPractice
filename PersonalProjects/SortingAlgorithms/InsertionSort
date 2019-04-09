//Iterative approach
void insertionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i;

		while (j > 0 && key < arr[j-1]) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = key;
	}
}

//Recursive approach
void insertionSortRecursive(int arr[], int n) {
	if (n <= 1)
		return;

	insertionSortRecursive(arr, n-1);

	int last = arr[n - 1];
	int j = n - 2;

	while (j >= 0 && arr[j] > last) {
		arr[j + 1] = arr[j];
		--j;
	}
	arr[j + 1] = last;
}
