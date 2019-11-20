# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void shellSort(vector<int> &nums);
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before sort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after sort"<<endl;
    shellSort(nums);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void shellSort(vector<int> &nums)
{
    int len = nums.size();
    if(len<2) return;
    int insertNum = 0;
    unsigned int gap = len /2;
    while(gap>=1)
    {
        for(int i = gap;i<len;++i)
        {
            insertNum = nums[i];
            int j = i;
            while(j>=gap && insertNum < nums[j-gap])
            {
                nums[j]=nums[j-gap];
                j-=gap;
            }
            nums[j]=insertNum;
        }
        gap=gap/2;
    }
}
