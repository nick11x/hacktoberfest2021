int Solution::findMedian(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int x=(n*m/2)+1;
    int count=0;
    int mi=INT_MAX,ma=INT_MIN;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mi>a[i][j])mi=a[i][j];
            if(ma<a[i][j])ma=a[i][j];
        }
    }
    while(mi<ma){
       int mid=mi+(ma-mi)/2;
       count=0;
        for(int i=0;i<n;i++){
            count=count+upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin(); 
        }if(count<x){
            mi=mid+1;
        }else{
            ma=mid;
        }
       
    }return mi;
}
