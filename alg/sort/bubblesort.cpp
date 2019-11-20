# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void Swap(int &x,int &y);
void display(const vector<int>& vec);
void bubblesort(vector<int>& vec);

int main(){
    vector<int>num={1,3,4,2,5};
    display(num);
    bubblesort(num);
    display(num);


    int a=1;
    int b=2;
    system("pause");
    return 0;
}
void Swap(int& x, int& y)
{
    int temp= x;
	x = y;
	y = temp;
}
void bubblesort(vector<int>& vec)
{
    for(int i=0;i<vec.size()-1;++i) {
        for(int j = i;j<vec.size();++j) {
            if(vec[j]<vec[i]) {
                Swap(vec[j],vec[i]);
            }
        }
    }
};
void display(const vector<int>& vec){
    for(auto v:vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;
};

