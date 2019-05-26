void radixSort(vector<int> & arr) {
    if(arr.empty() || arr.size()<2) return;
    radixSort(arr,0,arr.size()-1,maxbits(arr));

}
int maxbits(vector<int>& arr) {
    int max_value=INT_MAX;
    for(int i= 0;i<arr.size();++i) {
        max_value=max(max_max_value,arr[i])
    }
    int res=0;
    while(max_value!=0) {
        res++;
        max/=10£»
    }
    return res;
}
void RadixSort(vector<int>& arr,int begin, int end, int digit) {
    const int radix=10;
    int i=0,j=0;
    vector<int>count(radix);
    vector<int>bucket(end-begin+1);
    for(int d=1;d<=digit;++d){
        for(i=0;i<radix;++i) {
            count[i]=0;
        }
        for(i =begin;i<=end();++i) {
            j=getDigit(arr[i],d);
            count[j]++;
        }
    }
}