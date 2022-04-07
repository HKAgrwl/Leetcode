class Solution {
     public final String[] dict = new String[]{
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    public List<String> letterCombinations(String digits) {
        List<String> results = new ArrayList<>();
        if(digits.length() == 0) return results;
        backtracking(results, new StringBuilder(), 0, digits);
        return results;
    }
    
    public void backtracking(List<String> results, StringBuilder sb, int i, String digits) {
        if (i >= digits.length()) {
            results.add(sb.toString());
            return;
        }
        int d = digits.charAt(i) - '2';
        String word = dict[d];
        for (char c: word.toCharArray()) {
            sb.append(c);
            backtracking(results, sb, i + 1, digits);
            sb.setLength(sb.length() - 1);
        }
    }
}