
// Question) 1460. Make Two Arrays Equal by Reversing Sub-arrays


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> ump;
    for(int itr = 0; itr < target.size(); itr++){
        ump[target[itr]]++;
        ump[arr[itr]]--;
    }        
    for(int itr = 0; itr < ump.size(); itr++){
        if(ump[itr] != 0) return false;
    }
    return true;
}

