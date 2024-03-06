#include<bits/stdc++.h>
using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start, end, index;
};

// Function to compare meetings based on their end times
bool compareMeetings(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}


//time=O(n) +O(n log n) + O(n), sapce=O(N)
int maxMeeting(vector<int> &start, vector<int> &end, int n){
    vector<Meeting> met(n);
    for(int i=0; i<n; i++){
        met[i].start = start[i];
        met[i].end = end[i];
        met[i].index = i+1;
    }

    sort(met.begin(), met.end(), compareMeetings); //based on the time

    // Select the first meeting
    int selectedMeetings = 1;
    int endTime = met[0].end;

    // Iterate through the sorted meetings and select non-overlapping ones
    for (int i = 1; i < n; ++i) {
        if (met[i].start > endTime) {
            selectedMeetings++;
            endTime = met[i].end;
        }
    }

    return selectedMeetings;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,5,7,9,9};
    int N = 6;
    int result = maxMeeting(start, end, N);
    cout << result << endl;

    return 0;
}