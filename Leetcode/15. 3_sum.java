class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int N = nums.length;
        Arrays.sort(nums);
        
        if(N < 3 || nums[0] > 0 || nums[N-1] < 0) 
            return result;
        
        for(int i = 0; i < N - 2; i++) {
           
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int left = i + 1, right = N - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return result;
    }
}
