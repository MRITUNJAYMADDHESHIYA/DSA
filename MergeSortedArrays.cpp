#include<bits/stdc++.h>
using namespace std;

//time=O(n+m) + O(n+m),space=O(n+m)
void TwoarrayMerge(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    //declare 3rd array and 2 pointers
    vector<int> arr3;
    int left = 0; // for arr1
    int right = 0; // for arr2

    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3.push_back(arr1[left]);
            left++;
        }
        else{
            arr3.push_back(arr2[right]);
            right++;
        }
    }

    // when right pointer reaches the end
    while(left < n){
        arr3.push_back(arr1[left]);
        left++;
    }

    // when left pointer reaches the end
    while(right < m){
        arr3.push_back(arr2[right]);
        right++;
    }

    // fill all the elements in arr1 and arr2
    for (int i = 0; i < n + m; i++) {
        if (i < n){
            arr1[i] = arr3[i];
        }
        else{
            arr2[i - n] = arr3[i];
        }
    }
}


//time=O(min(n, m)) + O(n*logn) + O(m*logm),space=O(1)
void TwoarrayMerge2(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left = n-1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}


//gap method
//time=O((n+m)*log(n+m)),space=o(1)
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void TwoarrayMerge3(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    int len = n + m; //size of imaginary array
    int gap = (len / 2) + (len % 2); //Intial gap
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    TwoarrayMerge3(arr1, arr2);
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
