#include <stdio.h>
#include <stdlib.h>
/*
 * 参考：https://www.felix021.com/blog/read.php?1587
 * */

//在非递减序列上查找第一个大于或等于key的位置，如果都小于key，则返回e+1
int upperBound(int arr[],int s,int e,int key){
    int mid;
    if(arr[e]<key) return e+1;
    while(s<e){
        mid = s + (e-s)/2;
        if(arr[mid]<key) 
            s = mid+1;
        else
            e = mid;
    }
    return s;
}
//寻找最长递增子序列的长度
int lengthOfLIS(int* nums, int numsSize) {
    //用于记录当前LIS的长度
    int len = 0; 
    //用于记录对应长度LIS的最小末尾
    int *end = (int *) malloc(sizeof(int) *(numsSize+1)); 
    for( int i = 0 ;i< numsSize;i++){
        //找到插入的位置
        int pos = upperBound(end,0,len,nums[i]);
        printf("pos:%d \n",pos);
        end[pos] = nums[i];
        if(len < pos)
            len = pos;
        for(int i=0;i<len;i++) printf("%d ",end[i]);printf("\n");
    }
    return len;
        
}
int main(){

    int arr[] ={2,2,2,2,2,2,2,2,2,2};
    //for(int i = 0;i<9;i++) printf("%d ",arr[i]);
    //printf("\n");
    int res = lengthOfLIS(arr,sizeof(arr)/sizeof(int));
    printf("%d\n",res);
    return 0;
}


