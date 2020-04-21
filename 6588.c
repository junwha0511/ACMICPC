#include<stdio.h>

int isPrime(int n){
	int i;
	for(i=3;i<n;i+=2){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	while(1){
		int n = 0;
		scanf("%d", &n);
		
		if(n==0){
			break;
		}
		int i, flag = 1;
		for(i=n-3;i>=3;i-=2){
			if(isPrime(i) && isPrime(n-i)){
				printf("%d = %d + %d\n", n, n-i, i);
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
}
