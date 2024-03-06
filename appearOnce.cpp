#include<bits/stdc++.h>
using namespace std;

//time=O(N*N),space=(1)
int appearOnce1(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        int num = arr[i];
        int count=0;

        for(int j=0; j<arr.size(); j++){
            if(arr[j] == num){
                count++;
            }
        }
        if(count == 1) return num;
    }
    return -1; //this is for single element
}

int appearOnce2(vector<int> &arr){
    map<int, int> m;
    for(int i=0; i<arr.size(); i++){
        m[arr[i]]++;
    }

    for (auto it : m) {
        if (it.second == 1)
            return it.first;
    }
//     Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).
// Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).
// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
    return -1;
}

//time=O(N),space=O(1)
int appearOnce3(vector<int> &arr){
    int xorr = 0;
	for(int i=0; i<arr.size(); i++){
		xorr = xorr^arr[i];
	}
	return xorr;
}


int main(){
    vector<int> arr ={2,2,3,3,5,8,8};
    int ans = appearOnce3(arr);
    cout<< ans <<endl;
    return 0;
}