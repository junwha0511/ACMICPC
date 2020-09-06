#include<iostream>
#include<string>

using namespace std;


int isfillZero(int**& greed, int x, int y, int size){
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(greed[i][j]==1){
                return -1;
            }
        }
    }
    return 0;
}


int isfill(int**& greed, int x, int y, int size){

    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(greed[i][j]==0){
                return isfillZero(greed, x, y, size);
            }
        }
    }
    return 1;
}

string quadTree(int**& greed, int x, int y, int size){
    int quadResult = isfill(greed, x, y, size);
    if(quadResult!=-1){
        return to_string(quadResult);
    }else{
        int devidedSize = size/2;
        return "("+quadTree(greed, x, y, devidedSize)+quadTree(greed, x+devidedSize, y, devidedSize)+quadTree(greed, x, y+devidedSize, devidedSize)+quadTree(greed, x+devidedSize, y+devidedSize, devidedSize)+")";
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int**greed = new int*[64];
    
    for(int i=0; i<64; i++){
        greed[i] = new int[64];
    }

    cin>>N;

    for(int i=0; i<N; i++){
        string line;
        cin>>line; 
        for(int j=0; j<N; j++){
            greed[i][j] = line[j] - '0';  
                   
        }
    }

    

    cout<<quadTree(greed, 0, 0, N);
    cin>>N;

    delete[] greed;
}