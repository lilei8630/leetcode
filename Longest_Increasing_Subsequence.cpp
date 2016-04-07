#include <vector>
#include <iostream>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
        //如果nums为空，LIS为0 
        if(nums.empty()) return 0;
        //用nums[0]初始化vector数组
        vector<int> ends ={nums[0]};
        for(auto a:nums){
            if(a < ends[0]) 
                ends[0] = a;
            else if(a > ends.back()) 
                ends.push_back(a);
            else{
                int left = 0,right = ends.size();
                while(left<right){
                    int mid = left + (right - left) /2;
                    if(ends[mid] < a)
                        left = mid+1;
                    else
                        right = mid;
                }
                ends[right] = a;

            }

        }
        return ends.size();
 }
//trick:利用lower_bound函数来寻找数组中第一个大于或者等于查找值的元素
int lengthOfLIS_2(vector<int>& nums) {
    vector<int> v;
    for(auto a:nums){
        auto it = lower_bound(v.begin(),v.end(),a);
        if(it == v.end()) v.push_back(a);
       else *it = a; 
    }
    return v.size();
}

int main(){
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS_2(nums) << endl;
        return 0;
}
