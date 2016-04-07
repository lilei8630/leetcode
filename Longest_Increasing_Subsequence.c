#include <stdio.h>
#include <stdlib.h>
/*
 * 参考：https://www.felix021.com/blog/read.php?1587
 * */
//在非递减序列上查找第一个大于或等于key的位置，如果都小于key，则返回e+1
int upperBound(int arr[],int s,int e,int key){
    int mid;
    printf("arr[e]:%d--- ",arr[e]);
    //if(arr[e]==key) return e;
    if(arr[e]<=key) return e+1;
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
    for (int i=0;i<numsSize+1;i++) end[i] =nums[0]; 
    for( int i = 1;i< numsSize;i++){
        //找到插入的位置
        int pos = upperBound(end,0,len,nums[i]);
        printf("key:%d insert as pos:%d \n",nums[i],pos);
        end[pos] = nums[i];
        if(len <=pos)
            len=pos;
        for(int i=0;i<len;i++) printf("%d ",end[i]);printf("\n");
    }
    return len;
        
}
int lengthOfLIS_2(int* nums,int numsSize){
    int len = 1;
    if(numsSize==0) return 0;
    int * ends = (int *)malloc(sizeof(int) *(numsSize+1));
    ends[0] = nums[0];
    for(int i = 1;i<numsSize;i++){
        if(nums[i]<=ends[0]){
            ends[0] = nums[i];
        }else if(nums[i]>ends[len]){
            ends[len++] = nums[i];
        }else{
            int left =0,right = len;
            while(left<right){
                int mid = left + (right -left)/2;
                if(ends[mid]< nums[i]) left = mid+1;
                else right = mid;
            }
            ends[len] = nums[i];
        }


    }
    return len;
}
int main(){

    int arr[] ={10,9,2,5,3,7,101,18};
    //for(int i = 0;i<9;i++) printf("%d ",arr[i]);
    //printf("\n");
    //int arr[] = {2,2,2,2};
    //int arr[] = {0};
    int res = lengthOfLIS_2(arr,sizeof(arr)/sizeof(int));
    printf("%d\n",res);
    return 0;
}


