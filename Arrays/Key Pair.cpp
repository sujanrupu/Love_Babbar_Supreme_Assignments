class Solution{
public:	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr+n);
	    int start = 0, end = n-1;
	    while(start < end) {
	        if(arr[start] + arr[end] == x)  return true;
	        else if(arr[start] + arr[end] < x)  start++;
	        else    end--;
	    }
	    return false;
	}
};
