
// Question) 349. Intersection of Two Arrays


// Implementation

// 1st Approach in C++
// Time Complexity = O(N*M), Space Complexity = O(N)
// where N = nums1.size(), M = nums2.size()

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> st;        
    for(int itr = 0; itr < nums1.size(); itr++){
        for(int jtr = 0; jtr < nums2.size(); jtr++){
            if(nums1[itr] == nums2[jtr]){
                st.insert(nums1[itr]);
                break;
            }
        }
    }
    
    vector<int> vt;
    for(auto itr = st.begin(); itr != st.end(); itr++){
        vt.push_back(*itr);
    }
    return vt;
}


// 2nd Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for(int itr = 0; itr < nums2.size(); itr++){
            if(st.find(nums2[itr]) != st.end()){
                res.emplace_back(nums2[itr]);
                st.erase(nums2[itr]);
            }            
        }
        return res;
    }


// 3rd Approach in Java
// Time Complexity = O(N*M), Space Complexity = O(N)
// where N = nums1.length, M = nums2.length

public int[] intersection(int[] nums1, int[] nums2) {
    HashSet<Integer> set = new HashSet();  
    
    for(int itr = 0; itr < nums1.length; itr++){
        for(int jtr = 0; jtr < nums2.length; jtr++){
            if(nums1[itr] == nums2[jtr]){
                set.add(nums1[itr]);
                break;
            }
        }
    }
    
    int[] arr = new int[set.size()];        
    int jtr = 0;
    for (int itr : set)  
        arr[jtr++] = itr; 
    
    return arr;
}


// 4th Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int[] intersection(int[] nums1, int[] nums2) {
    HashSet<Integer> set = new HashSet(); 
    HashSet<Integer> res = new HashSet(); 
    
    for(int itr = 0; itr < nums1.length; itr++){
        set.add(nums1[itr]);
    }
    
    for(int itr = 0; itr < nums2.length; itr++){
        if(set.contains(nums2[itr])) res.add(nums2[itr]);
    }
    
    int[] arr = new int[res.size()];        
    int jtr = 0;
    for (int itr : res)  
        arr[jtr++] = itr; 
    
    return arr;
}
