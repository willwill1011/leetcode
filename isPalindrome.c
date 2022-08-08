
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 11;
    int count = 0;
    // negative condition
    if(x<0){
        return 0;
    }else if(x==1){
        return 1;
    }
    // get each digital numbers into char array
    char* array_head = malloc( 10*sizeof(char) );
    while( x != 0 ){
        array_head[count] = x%10;
        x = x/10;
        printf("array_head[%d]=%d ", count, array_head[count]);
        count++;
    }
    printf("\ncount=%d\n", count);
    // check
    // 0 1 2 3 4 - array index
    // 1 2 3 2 1 - array value
    //     *     - middle = count/2, could be zero
    for(int i=0,j=count-1;i<count/2;i++){
        printf("array_head[%d]=%d [%d]=%d\t", i, array_head[i], j, array_head[j]);
        if(array_head[i]==array_head[j]){
            j--;
        }
        else{
            return 0;
        }
    }
    printf("\n------x is isPalindrome------");
    return 1;
}