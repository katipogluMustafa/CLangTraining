#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	void quickSort(char* str, int n);
	char ptr[] = "sadsdsdaddddssasdafff";
	char* str = (char*)malloc( strlen(ptr) * sizeof(char) );
	strcpy(str,ptr);
	quickSort( str,strlen(str) );

	printf("%s",str);

}


void quickSort(char* str, int n){
	void quicky(char* str, int start, int end);
	quicky(str, 0, n);
}

void quicky(char* str, int start, int end){
	int partition(char* str, int low, int high);

	if(start >= end){
		return;
	}

	int pivot = partition(str,start,end);

	quicky(str,start, pivot - 1);
	quicky(str,pivot+1, end);
}

int partition(char* str, int low, int high){
	void swap(char*, int, int);
	int pickPivot(char*, int, int);

	int i;
	int pivot = pickPivot(str,low,high);
	char pivotValue = str[pivot];

	if( str[low] != str[pivot] ){
		swap(str,low,pivot);
	}

	int newPivot = low + 1;

	for(i = newPivot; i <= high; i++){
		if( str[i] <= pivotValue ){
			swap(str, i, newPivot);
			newPivot++;
		}
	}

	newPivot--;
	swap(str, newPivot, low);

	return newPivot;
}

void swap(char* str, int x, int y){
	char temp = str[x];
	str[x] = str[y];
	str[y] = temp;
}

int pickPivot(char* arr, int a, int b) { // median-of-three

	int i = (a+b)>>1;
	char x = arr[a], y = arr[i], z = arr[b];

	if(x > y) {
		if(y > z) return i;
		if(x > z) return b;
	return a;
	}

	if(y < z) return i;

	if(x < z) return b;

return a;
}