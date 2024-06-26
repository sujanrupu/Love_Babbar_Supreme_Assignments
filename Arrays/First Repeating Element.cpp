class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if(arr[i] == arr[j])    return i+1;
            }
        }
        return -1;
    }
};
