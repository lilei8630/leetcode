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

int main(){
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS(nums) << endl;
        return 0;
}
