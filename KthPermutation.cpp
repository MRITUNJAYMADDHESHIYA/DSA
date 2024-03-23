#include<bits/stdc++.h>
using namespace std;

//time=O(N*N)We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.
//space=O(N) storing the value in vector
string getPermutation(int n, int k){
    int fact = 1;
    vector<int> number;

    //factorial of n-1 and push all the value in number
    for(int i=1; i<n; i++){
        fact = fact*i;
        number.push_back(i);
    }
    number.push_back(n);

    string ans = " "; //for storing the ans
    k = k - 1;

    while(true){
        ans = ans + to_string(number[k/fact]); //first value added in the ans and first value is k/fact
        number.erase(number.begin() + k/fact); //erase the value from vector
        if(number.size() == 0){
            break;
        }
        k = k % fact; //next value of k
        fact = fact / number.size(); //next fact
    }
    return ans;
}

int main() {
  int n = 3, k = 3;
  string ans = getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}


