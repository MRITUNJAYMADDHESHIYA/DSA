#include<bits/stdc++.h>
using namespace std;

vector<int> union1(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    for(int i=0; i<m; i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it: st){
        temp.push_back(it);
    }
    return temp;
//     Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.
// Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
// Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
// O(1) {If Space of union ArrayList is not considered}
}

vector<int> union2(vector<int> a, vector<int> b){
    int n = a.size();
    int m =b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    //remaining in the b array
    while(j<m){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
        j++;
    }
    //remaining in the a array
    while(i<n){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
        i++;
    }
    return unionArr;
//     Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 
// Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
// O(1) {If Space of union ArrayList is not considered}
}

//time=O(n*m),space=o(M)
vector<int> Interaction1(vector<int> &a, int n, vector<int> &b, int m){
    vector<int> ans;
    int ves[m] = {0}; //this array store the value 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == a[j] && ves[j] == 0){
                ans.push_back(a[i]);
                ves[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return ans;
}

//time=O(N+M),space=O(1)
vector<int> Interaction2(vector<int> &a, int n, vector<int> &b, int m){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set(nums1.begin(), nums1.end());
    vector<int> result;
    
    for (int num : nums2) {
        if (set.count(num)) {
            result.push_back(num);
            set.erase(num); // Ensure uniqueness
        }
    }
    
    return result;
}