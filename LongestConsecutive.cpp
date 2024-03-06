#include<bits/stdc++.h>
using namespace std;


//time=o(N*N),space=O(1)
bool linearSearch(vector<int> &arr, int target){
    int n = arr.size();
    for(int i=0; i< n; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}

int longestConsecutive1(vector<int> &arr){
    int n = arr.size();
    int longest = 1;

    for(int i=0; i<n; i++){
        int x = arr[i];
        int count = 1;

        while(linearSearch(arr, x+1) == true){
            x +=1;
            count +=1;
        }

        longest = max(longest,count);
    }
    return longest;
}

//time=O(NlogN) + O(N),space=O(1)
int longestConsecutive2(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int largest = 1;
    int count = 0;
    int lastSmallest = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i]-1 == lastSmallest){
            count ++;
            lastSmallest = arr[i]; //new element in the sequence
        }
        //if repeacting number is not, then start the new sequence
        else if(arr[i] != lastSmallest){
            count = 1;
            lastSmallest = arr[i];
        }
        largest = max(largest, count);
    }
    return largest;

}

//Important
//time=O(N) + O(2*N) ~ O(3*N),space=o(N)
int longestConsecutive3(vector<int> &arr){
    int n = arr.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it; //first element
            while(st.find(x+1) != st.end()){ //linear search in  set data structure
                x = x+1;
                count ++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main(){
    vector<int> arr ={100,200,1,2,3,4,8};
    int ans = longestConsecutive3(arr);
    cout<< ans;
    return 0;
}