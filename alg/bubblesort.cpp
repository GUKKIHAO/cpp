void swap(int i, int j) {
    int tmp=i;
    j=tmp;
    i=j;
    //i=i^j;
    //j=i^j;
    //i=i^j;
}
void BubbleSort(vector<int>& num) {
    if (num.empty() || num.size()<2) return;
    for (int end = num.size()-1; end>0; --end){
        for (int i = 0; i < end; ++i) {
            if(num[i] > num[i+1]) swap(i, i+1);
        }
    }
    void InsertSort(int i, int j) {
        if(num.empty() || num.size()<2) return;
        for(int  i =1; i<num.size();++i) {
            for(int j=i-1; j>=0&&num[j] > num[j+1]; --j) {
                swap(j,j+1); 
            }
        }
    } 
} 