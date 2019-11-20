# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void insertSort(vector<int> &nums);
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before quicksort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after quicksort"<<endl;
    insertSort(nums);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void insertSort(vector<int> &nums)
{
    if(nums.size()<=1) return;
    int i,len=nums.size();
    for(i = 0;i<len-1;++i)
    {
        int tmp=nums[i+1];
        int j = i;
        while(j>=0 && tmp < nums[j])
        {
            nums[j+1]=nums[j];
            --j;
        }
        nums[j+1]=tmp;
    }
}
