#include <stdio.h>
#include <stdlib.h>

int main(){
    int target=20;
    int numsSize=5;
    int nums[5]={2,5,7,9,11};
    int *returnSize=(int*)malloc(sizeof(int*));
    int *result=(int*)malloc(sizeof(int*)*2);

    for(int i=0;i<numsSize;i++){
        for( int j=i+1;j<numsSize;j++){
            if(target-nums[i]==nums[j]){
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                printf("index=%d %d", result[0], result[1]);
                //return result;
            }
        }
    }
    //*returnSize=0;
    //return NULL;
}