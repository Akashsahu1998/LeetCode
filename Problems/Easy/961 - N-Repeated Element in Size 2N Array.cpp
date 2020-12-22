
// Question) 961. N-Repeated Element in Size 2N Array.


// Implementation

// 1st Approach in C++ Using Map
// Time Complexity = O(N), Space Complexity = O(N)

int repeatedNTimes(vector<int>& arr) {
    int n = arr.size()/2, maxVal = 0, arrElement = arr[0];        
    unordered_map<int, int> ump;
    for(int itr = 0; itr < arr.size(); itr++){
        ump[arr[itr]]++;
        if(ump[arr[itr]] > maxVal){
            maxVal = ump[arr[itr]];
            arrElement = arr[itr];
        }
    }
    return arrElement;
}


// 2nd Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int repeatedNTimes(vector<int>& arr) {                
    for(int itr =  0; itr < arr.size()-2; itr++){
        if(arr[itr] == arr[itr+2] || arr[itr] == arr[itr+1])
            return arr[itr];
    }
    return arr[arr.size()-1];
}


// 3rd Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int repeatedNTimes(vector<int>& arr) {                
    for(int itr =  2; itr < arr.size(); itr++){
        if(arr[itr] == arr[itr-2] || arr[itr] == arr[itr-1])
            return arr[itr];
    }
    return arr[0];
}


// 4th Approach in Java Using Map
// Time Complexity = O(N), Space Complexity = O(N)

public int repeatedNTimes(int[] arr) {
    int n = arr.length/2, maxVal = 0, arrElement = arr[0];        
    Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
    for(int itr = 0; itr < arr.length; itr++){
        if (mp.containsKey(arr[itr])) { 
            mp.put(arr[itr], mp.get(arr[itr]) + 1); 
        }  
        else { 
            mp.put(arr[itr], 1); 
        } 
        if(mp.get(arr[itr]) > maxVal){
            maxVal = mp.get(arr[itr]);
            arrElement = arr[itr];
        }
    }
    return arrElement;
}


// 5th Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int repeatedNTimes(int[] arr) {
    for(int itr =  0; itr < arr.length-2; itr++){
        if(arr[itr] == arr[itr+2] || arr[itr] == arr[itr+1])
            return arr[itr];
    }
    return arr[arr.length-1];
}


// 6th Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int repeatedNTimes(int[] arr) {
    for(int itr =  2; itr < arr.length; itr++){
        if(arr[itr] == arr[itr-2] || arr[itr] == arr[itr-1])
            return arr[itr];
    }
    return arr[0];
}
