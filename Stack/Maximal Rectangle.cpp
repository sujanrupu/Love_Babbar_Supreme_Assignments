class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            int j = i;
            int left = 0;
            while(j >= 0 && heights[j] >= heights[i]) {
                left++; j--;
            }
            j = i;
            int right = 0;
            while(j < heights.size() && heights[j] >= heights[i]) {
                right++;    j++;
            }
            ans = max(ans, heights[i]*(left + right - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>height(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == '1')    height[j]++;
                else    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            ans = max(ans, area);
        }
        return ans;
    }
};
