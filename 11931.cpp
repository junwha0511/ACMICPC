#include<iostream>
#include<cstdio>

using namespace std;

int arr[1001010], N;
int tmp[1001010];

void quickSort(int low, int high){
    if(low >= high) return;
    int pivot = low;
    int i = low+1, j = high;

    while(i <= j){
        while(arr[i]>arr[pivot] && i<=high) i++;
        while(arr[j]<=arr[pivot] && j>low) j--;
        if(i > j) swap(arr[j], arr[pivot]);
        else swap(arr[i], arr[j]);
    }

    quickSort(low, j-1);
    quickSort(j+1, high);
}

void insertionSort(){
    int pivot;
    for(int i=0; i<N-1; i++){
        pivot = i;
        for(int j=i+1; j<N; j++) if(arr[j] > arr[pivot]) pivot = j;
        swap(arr[pivot], arr[i]);
    }
}

void merge(int low, int mid, int high){
    int i = low, j = mid, tmp_idx = low;
    while(i<mid && j<high){
        if(arr[i] > arr[j]) tmp[tmp_idx++] = arr[i++];
        else tmp[tmp_idx++] = arr[j++];
    }

    while(i<mid) tmp[tmp_idx++] = arr[i++];
    while(j<high) tmp[tmp_idx++] = arr[j++];

    for(int i=low; i<high; i++) arr[i] = tmp[i];
    
}

void mergeSort(int low, int high){
    if(low == high-1) return;
    int mid = (low+high)/2;
    mergeSort(low, mid);
    mergeSort(mid, high); 
    merge(low, mid, high);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio();

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    
    mergeSort(0, N);
    
    for(int i=0; i<N; i++) cout << arr[i] << '\n';
}