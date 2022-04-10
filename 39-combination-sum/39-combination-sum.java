import java.util.ArrayList;
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> parent = new ArrayList<>();
        csHelper(parent, new ArrayList<>(), candidates, target, 0, 0 );
        return parent;
    }
    
    public void csHelper(List<List<Integer>> parent, ArrayList<Integer> child,int[] nums, int target, int sum, int idx) {
        if(sum > target || idx == nums.length) return;
        else if(sum == target) {
            parent.add(new ArrayList<>(child));
            return;
        }
        
        child.add(nums[idx]);
        csHelper(parent, child, nums, target, sum + nums[idx], idx);
        child.remove(child.size()-1);
        csHelper(parent, child, nums, target, sum, idx + 1);
    }
}