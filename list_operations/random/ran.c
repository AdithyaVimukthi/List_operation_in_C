//including libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int x = 100000000;

int r[100000000] , n;

int main(){
    clock_t begin,end ;
    
    for(int i = 0; i<x; i++){
        r[i] = rand();
    }

    printf("\nEnter number : "); //Get node numbers
    scanf("%d", &n);

    begin = clock();
    for(int i = 0; i<x/2; i++){
        if (n == r[i] || n== r[x-1-i]){
            if(n == r[i]){
                printf("Your number found in %d posistion \n\n", i+1);
            }else if(n== r[x-1-i]){
                printf("Your number found in %d posistion \n\n", x-i);
            }
            break;
        }
    }
    end = clock();
    
    double time_spent =  (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}