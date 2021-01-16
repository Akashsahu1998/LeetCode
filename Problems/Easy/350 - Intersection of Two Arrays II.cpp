
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


// 3rd Approach in Java
// Time Complexity = O(M*N), Space Complexity = O(M)

public int[] intersect(int[] nums1, int[] nums2) {
    ArrayList<Integer> arr = new ArrayList<Integer>();
    for(int itr = 0; itr < nums1.length; itr++){
        for(int jtr = 0; jtr < nums2.length; jtr++){
            if(nums1[itr] == nums2[jtr]){
                nums2[jtr] = -11;
                arr.add(nums1[itr]);
                break;
            }
        }   
    }
    int[] res = new int[arr.size()];
    for(int itr = 0; itr < arr.size(); itr++){
        res[itr] = arr.get(itr);
    }
    return res; 
}


// 4th Approach in Java
// Time Complexity = O(M+N), Space Complexity = O(M)

public int[] intersect(int[] nums1, int[] nums2) {
    HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
    ArrayList<Integer> arr = new ArrayList<Integer>();
    
    for(int itr = 0; itr < nums1.length; itr++){
        if (temp.containsKey(nums1[itr]))              { 
            temp.put(nums1[itr], temp.get(nums1[itr]) + 1); 
        }  
        else{ 
            temp.put(nums1[itr], 1); 
        } 
    }
    
    for(int itr = 0; itr < nums2.length; itr++){
        if(temp.containsKey(nums2[itr])){
            int n = temp.get(nums2[itr]) - 1;
            if(n >= 0){
                temp.put(nums2[itr], temp.get(nums2[itr]) - 1); 
                 arr.add(nums2[itr]);
            }
        }
    }
    
    int[] res = new int[arr.size()];
    for(int itr = 0; itr < arr.size(); itr++){
        res[itr] = arr.get(itr);
    }
    return res;       
}


