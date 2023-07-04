class Solution {
    public boolean checkValidString(String s) {
        int star=0, left=0, right=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='(') left++;
            else if(s.charAt(i)==')'){
                if(left>0) left--;
                else if(star>0) star--;
                else if(right>0){
                    right--;
                    star++;
                }
                else return false;
            }   
            else{
                if(left>0){
                    right++;
                    left--;
                }
                else star++;
            }
        }
        if(left==0) return true;
        return false;
    }
}