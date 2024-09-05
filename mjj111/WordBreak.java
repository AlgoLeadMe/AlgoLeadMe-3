class WordBreak {
    private String s;
    private List<String> wordDict;
    private int[] memo;

    public boolean wordBreak(String s, List<String> wordDict) {
        this.s = s;
        this.wordDict = wordDict;
        this.memo = new int[s.length()];
        Arrays.fill(this.memo, -1);

        return dp(s.length() - 1);
    }

    private boolean dp(int i) {
        if (i < 0) return true;

        if (memo[i] == -1) {
            for (String word: wordDict) {
                if (i >= word.length() - 1 && dp(i - word.length())) {
                    if (s.substring(i - word.length() + 1, i + 1).equals(word)) {
                        memo[i] = 1;
                        break;
                    }
                }
            }
        }

        if (memo[i] == -1) {
            memo[i] = 0;
        }

        return memo[i] == 1;
    }
}