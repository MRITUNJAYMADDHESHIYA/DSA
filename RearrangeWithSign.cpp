#include<bits/stdc++.h>
using namespace std;

//time=O(N+N/2),space=o(n/2+n/2)
vector<int> RearrangeSign1(vector<int> &arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    return arr;
}

//time=O(N),space=O(N)
vector<int> RearrangeSign2(vector<int> &arr, int n){
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0; i<n; i++){
        if(arr[i] <0){
            ans[negIndex] = arr[i];
            negIndex +=2;
        }
        else{
            ans[posIndex] = arr[i];
            posIndex +=2;
        }
    }
    return ans;
}

//if positive != negative in the question
//time=O(n)+O(length and many more thing)
vector<int> RearrangeSign3(vector<int> &arr){
    int n = arr.size();
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        //now i want to arrange the extra positive element
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        //now i want to arrange the extra negative element
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}


int main(){
    vector<int> arr ={1, 2, -4, -5};
    int n=4;
    vector<int> ans = RearrangeSign3(arr);

    for(int i=0; i<n; i++){
        cout<< ans[i] <<endl;
    }
    return 0;
}