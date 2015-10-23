/*###############################################################
## MODULE: 035_SearchInsertPosition.cpp
## VERSION: 1.0 
## SINCE 2015-10-23
## AUTHOR Jimmy Lin (xl5224) - JimmyLin@utexas.edu  
## DESCRIPTION: 
##      
#################################################################
## Edited by MacVim
## Class Info auto-generated by Snippet 
################################################################*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return 0;
        for (int i = 0; i < size; i ++) {
            if (nums[i] < target) continue;     
            else return i;
        }
    }
};