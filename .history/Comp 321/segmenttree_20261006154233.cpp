#include <iostream>
#include <vector>
using namespace std;

vector<int> buildSegmentTree(vector<int> arr){
    int n = arr.size();
    vector<int> segment(2*n);
    copy(arr.begin(), arr.end(), segment.begin() + n);
    for(int i = n-1; i > 0; i--){
    segment[i] = max(segment[2*i], segment[2*i + 1]);

    }
}

void update(vector<int>& arr, int i, int n){
    arr[i] = n;

    while(i > 1){
        i /= 2;
        int newValue = max(arr[2*i], arr[2*i + 1]);
        if (newValue != arr[i]){
            arr[i] = newValue;
        }
        else{
            return;
        }
    }
}




int main(){

}