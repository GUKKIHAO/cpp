void BucketSort(vector<int>& arr) {
    if(arr.empty() || arr.size()<2) return;
    int max_value = INT_MAX;
    for(int i= 0;i<arr.size();++i) {
        max_value=max(max_max_value,arr[i])
    }
    vector<int>bucket(max+1);
    for(int i =0;i<arr.size();++i) {
        bucket[arr[i]]++;
    }
    int i=0;
    for(int j=0;j<bucket.size();++j) {
        while(bucket[j]-- > 0) {
            arr[i++]=j;
        }
    }
}