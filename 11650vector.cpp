#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


typedef struct Coor{
    int x, y;
} Coor;

int partion(vector<Coor>& list, int left, int right){
    int mid = (left+right)/2;
    int middleX = (list[left].x+list[mid].x+list[right].x)-max({list[left].x, list[mid].x, list[right].x})-min({list[left].x, list[mid].x, list[right].x});
    int pivot;
    if(list[left].x==middleX){
        pivot = left;
    }else if(list[mid].x==middleX){
        pivot = mid;
    }else if(list[right].x==middleX){
        pivot = right;
    }
    int i = left, j = right;
    
    while(i<j){      
        while(i<=j&&list[pivot].x>=list[i].x){
            // if(list[pivot].x==list[i].x){
            //     if(list[pivot].y<list[i].y){
            //         break;
            //     }
            // }
            i++;
        }

        while(i<=j&&list[pivot].x<=list[j].x){
            // if(list[pivot].x==list[j].x){
            //     if(list[pivot].y>list[j].y){
            //         break;
            //     }
            // }
            j--;
        }
        swap(list[i].x, list[j].x);
        swap(list[i].y, list[j].y);
    }
    
    swap(list[pivot].x, list[i].x);
    swap(list[pivot].y, list[i].y);

    return i;
}
void quickSort(vector<Coor>& list, int left, int right){
    if(left>=right){
        return;
    }

    int pivot = partion(list, left, right);
    quickSort(list, left, pivot-1);
    quickSort(list, pivot+1, right);
}
int main(){
    int N;
    cin>>N;
    vector<Coor> coords(N);

    for(int i=0; i<N; i++){
        cin>>coords[i].x>>coords[i].y;
    }

    quickSort(coords, 0, N-1);

    for(int i=0; i<N; i++){
        cout<<coords[i].x<<" "<<coords[i].y<<endl;
    }
    cout<<endl;
    
    
    
    cin>>N;
    return 0;
}