#include<bits/stdc++.h>
using namespace std;

// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.
// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void partitionHelper(int index, string s, vector<vector<string>> &ans, vector<string> &path){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){

            path.push_back(s.substr(index, i-index+1));
            partitionHelper(i+1, s, ans, path);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> path;
    partitionHelper(0, s, ans, path);
    return ans;
}

int main(){
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    int n = ans.size();

    cout<<" [ ";
    for(auto i: ans){
        cout<<" [ ";
        for(auto j: i){
            cout<< j <<" ";
        }
        cout<<"]";
    }
    cout<<"]";
    return 0;
}