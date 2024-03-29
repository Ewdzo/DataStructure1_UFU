#include <stdio.h>

void quicksort(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];

	while(i <= j) {
		while(values[i] < pivo && i < end){	i++; }
		while(values[j] > pivo && j > began){ j--; }
		
        if(i <= j){
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began) quicksort(values, began, j+1);
	if(i < end) quicksort(values, i, end);
}

void main() {

	int array[10] = {5, 8, 1, 2, 7, 3, 6, 9, 4, 10};

    printf("Before QuickSort: ");

	for(int i = 0; i < 10; i++){ printf("%d ", array[i]); }

	quicksort(array, 0, 10);

    printf("\n\nAfter QuickSort: ");
	for(int i = 0; i < 10; i++){ printf("%d ", array[i]); }
}