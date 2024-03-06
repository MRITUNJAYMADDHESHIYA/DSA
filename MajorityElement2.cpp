#include<bits/stdc++.h>
using namespace std;

//time=O(N*N),space=O(1)(only 2 vlaue store )
vector<int> majority1(vector<int> &arr){
    int n = arr.size();
    vector<int> temp;  //all the ans inside the temp

    for(int i=0; i<n; i++){
        if(temp.size() == 0 || temp[0] != arr[i]){
            int count = 0;
            for(int j=0; j<n; j++){
                if(arr[j] == arr[i]){
                    count++;
                }
            }

            if(count > (n/3)){
                temp.push_back(arr[i]);
            }
        }
        if(temp.size() == 2){
            break;
        }
    }
    return temp;
}

//time=O(N*logN),space=O(N + 2)
vector<int> majority2(vector<int> &arr){
    int n= arr.size();
    vector<int> temp;

    int mini = int(n/3)+1;// least occurrence of the majority element:

    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;

        if(mpp[arr[i]] == mini){
            temp.push_back(arr[i]);
        }

        if(temp.size() == 2){
            break;
        }
    }
    return temp;
}

//time=O(N)+O(N),space=O(1)(only 2 vlaue store )
vector<int> majority3(vector<int> &arr){
    int n = arr.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != arr[i]) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && el1 != arr[i]) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (arr[i] == el1) cnt1++;
        else if (arr[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el1) cnt1++;
        if (arr[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majority3(arr);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}