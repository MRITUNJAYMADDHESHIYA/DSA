#include<bits/stdc++.h>
using namespace std;

//time=O(N1+N2),space=O(N1+N2)
double median1(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();

    vector<int> ans;

    //merge the two array
    int i=0, j=0;
    while(i<=n2 && j<=n2){
        if(a[i] < b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    //remaining element
    while(i < n1) ans.push_back(a[i++]);
    while(j < n2) ans.push_back(b[j++]);

    int n = n1 + n2;
    if(n%2 == 1){
        return (double)ans[n/2];
    }

    double median = ((double)ans[n / 2] + (double)ans[(n / 2) - 1]) / 2.0;
    return median;
}

//
//time=O(log(min(n1,n2))),sapce=O(1)
double median2(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) return median2(b, a); //for a is a smaller array

    int n = n1 + n2;
    int left = (n1 + n2 + 1)/2; //length of left half and same for odd and even

    int low = 0, high = n1;
    while(low<= high){
        int mid1 = (low+high) >> 1;  
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1, l2);  //odd
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0; //even
        }
        else if(l1 > r2) high = mid1  -1;
        else low = mid1 + 1;
    }
    return 0;

}
int main(){
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median2(a, b) << '\n';
}