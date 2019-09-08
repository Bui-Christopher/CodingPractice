//Helper Function
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Iterative approach
void selectionSort(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		int minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(&arr[minIndex], &arr[i]);
	}
}

//Recursive approach
void selectionSortRecursive(int arr[], int n, int index) {

	if (n- 1 == index) //dont check the last one, should be in place
		return;

	int min = index;
	//finding minimum index of minimum value
	for (int i = index + 1 ; i < n; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	swap(&arr[min], &arr[index]);
	selectionSortRecursive(arr, n, index + 1);
}
