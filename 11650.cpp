#include<iostream>
#include<cstdio>


using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int partion(int** &arr, int left, int right){
    int r1 = left;
    int r2 = (left+right)/2;
    int r3 = right;
    
    int max, min;

    if(arr[r1][0]>arr[r2][0]&&arr[r1][0]>arr[r3][0]){
        max = r1;
    }else if(arr[r2][0]>arr[r1][0]&&arr[r2][0]>arr[r3][0]){
        max = r2;
    }else{
        max = r3;
    }

    if(arr[r1][0]<arr[r2][0]&&arr[r1][0]<arr[r3][0]){
        min = r1;
    }else if(arr[r2][0]<arr[r1][0]&&arr[r2][0]<arr[r3][0]){
        min = r2;
    }else{
        min = r3;
    }

    int r = (r1+r2+r3) - min - max;
    swap(arr[left][0],  arr[r][0]);
    swap(arr[left][1],  arr[r][1]);
    int* pivot = arr[left];
    int i = left, j = right;

    while(i<j){
        while(pivot[0]>=arr[i][0]){
            if(pivot[0]==arr[i][0]){
                if(pivot[1]>arr[i][1]){
                    i++;
                }else{
                    break;
                }
            }else{
                i++;
            }
        }
        
        while(pivot[0]<=arr[j][0]){
            if(pivot[0]==arr[j][0]){
                if(pivot[1]<arr[j][1]){
                    j--;
                }else{
                    break;
                }
            }else{
                j--;
            }

        }
        swap(arr[i][0], arr[j][0]);
        swap(arr[i][1], arr[j][1]);
    }
    swap(arr[i][0], arr[left][0]);
    swap(arr[i][1], arr[left][1]);

    return i;
}

void quickSort(int** &arr, int left, int right){
    if(left>=right){    
        return;
    }
    
    int p = partion(arr, left, right);

    quickSort(arr, left, p-1);
    quickSort(arr, p+1, right);
}

int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    int N, temp;
    cin>>N; 
    int** coorArr = new int*[N];

    for(int i=0; i<N; i++){
        coorArr[i] = new int[2];
        scanf("%d %d", &coorArr[i][0], &coorArr[i][1]);
    }

    quickSort(coorArr, 0, N-1);

    for(int i=0; i<N; i++){
        printf("%d %d\n", coorArr[i][0], coorArr[i][1]);
    }

    //cin>>N;

    delete[] coorArr;

}
