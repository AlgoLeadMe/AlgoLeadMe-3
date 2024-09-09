class LongestIncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, 1);

        for(int i = 0; i < nums.length; i++) {
            int now = nums[i];
            for(int j = i - 1; j >= 0; j--) {
                int opp = nums[j];

                if(opp < now) {
                    memo[i] = Math.max(memo[i], memo[j] + 1);
                }
            }
        }
        return Arrays.stream(memo).max().getAsInt();
    }
}