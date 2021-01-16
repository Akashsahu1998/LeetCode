
// Question) 350. Intersection of Two Arrays II


// Implementation

// 1st Approach in C++
// Time Complexity = O(M*N), Space Complexity = O(M)

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
    vector<int> res;        
    for(int itr = 0; itr < nums1.size(); itr++){
        for(int jtr = 0; jtr < nums2.size(); jtr++){
            if(nums1[itr] == nums2[jtr]){
                nums2[jtr] = -11;
                res.push_back(nums1[itr]);
                break;
            }
        }   
    }
    return res;       
}


// 2nd Approach in C++
// Time Complexity = O(M+N), Space Complexity = O(M)

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
    unordered_map<int, int> temp;
    vector<int> res;
    for(int itr = 0; itr < nums1.size(); itr++){
        temp[nums1[itr]]++;
    }
    for(int itr = 0; itr < nums2.size(); itr++){
        if(temp.find(nums2[itr]) != temp.end()){
            if(--temp[nums2[itr]] >= 0){
                res.push_back(nums2[itr]);
            }
        }
    }
    return res;       
}
