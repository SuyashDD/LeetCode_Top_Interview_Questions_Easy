//  Approach 1 - 

class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        vector<int> result ;
        int size = (n1.size() < n2.size()) ? n1.size() : n2.size() ;
        int i = 0;
        while( i < n1.size())
        {
            for(int j = 0 ; j < n2.size() ; j++ )
            {
                if(n1[i] == n2[j])
                {
                    result.push_back(n1[i]);
                    n2[j] = -1 ;
                    break ;
                }
                
            }
            i++;
        }
        return result ;
    }
};

// Approach 2 - Hashmap 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> map ;
        vector<int> res ;
//         Below for loop only push the elements from nums1 into the map
        for(int i = 0 ; i < nums1.size() ; i++)
        {
                map[ nums1[i] ] += 1 ;   
        }
//         In the below for loop we are iterating over nums2. first we check if the element if present in the map or not ? if no then skip. if yes then we first decrese its count first and then we check if the count of the element if greater than or equal to 0 or not. 0 or greater mean the same element is present in nums1. Hence we push that element in result vector res. 
        for(int j = 0 ; j < nums2.size() ; j++)
        {
            if( map[ nums2[j] ] )
            {
                map[ nums2[j] ] -= 1 ;
                if(map[ nums2[j] ] >= 0 )
                {
                    res.push_back(nums2[j]);
                }
            }
        }
        return res ;
    }
};
