#include<bits/stdc++.h>
using namespace std;

int find_days(vector<int> &weights, int capacity){
    int days = 1;
    int load = 0;
    int n = weights.size();
    for(int i=0; i<n; i++){
        if(load + weights[i] > capacity){
            days += 1; //shift the day if load on the ship is more than the capacity
            load = weights[i];  //loading on the ship
        }
        else{
            load += weights[i]; //load the weight on the same day
        }
    }
    return days;
}

//time=O(N * (sum(weights[]) – max(weights[]) + 1)),space=o(1)
int leastWeightCapacity1(vector<int> &weights, int d){
    int maxi = *max_element(weights.begin(), weights.end()); //find the max value in an array
    int sum = accumulate(weights.begin(), weights.end(), 0); //find the sum of all element in the array

    //now my ans is between the maxi and sum
    for(int i=maxi; i<=sum; i++){
        if(find_days(weights, i) <= d){
            return i;
        }
    }
    return -1;
}


//time=O(N * log(sum(weights[]) – max(weights[]) + 1)),space=o(1)
int leastWeightCapacity2(vector<int> &weights, int d){
    int low = *max_element(weights.begin(), weights.end()); //find the max value in an array
    int high = accumulate(weights.begin(), weights.end(), 0); //find the sum of all element in the array
    while(low <=high){
        int mid = (low + high)/2;
        if(find_days(weights, mid) <= d){
            high = mid - 1; //eliminate right half 
        }
        else{
            low = mid+1;  //eliminate left half
        }
    }
    return low;
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int d = 1;
    int ans = leastWeightCapacity2(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}