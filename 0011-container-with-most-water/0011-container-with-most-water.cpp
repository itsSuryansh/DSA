class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxWater=0;
        while(left<right){
            int width=right-left;
            int h=min(height[left],height[right]);
            int area=width*h;
            maxWater=max(maxWater,area);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna