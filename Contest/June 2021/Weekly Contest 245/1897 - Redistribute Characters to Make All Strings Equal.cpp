
// Question) 1897. Redistribute Characters to Make All Strings Equal


// Implementation

// 1st Approach in C++

bool makeEqual(vector<string>& words) {        
    unordered_map<char, int> ump;
    for(int itr = 0; itr < words.size(); itr++){
        string str = words[itr];
        int jtr = 0;
        while(str[jtr]) ump[str[jtr++]]++;
    }
    for(auto f: ump){
        if(f.second % (words.size()) != 0) return false;
    }
    return true;
}

// 2nd Approach in Java

public boolean makeEqual(String[] words) {
    HashMap<Character, Integer> hmp = new HashMap<Character, Integer>();
    for(int itr = 0; itr < words.length; itr++){
        String str = words[itr];
        int jtr = 0, len = str.length();
        while(jtr < len){
            if (hmp.containsKey(str.charAt(jtr)))  hmp.put(str.charAt(jtr), hmp.get(str.charAt(jtr)) + 1);
            else hmp.put(str.charAt(jtr), 1);
            jtr++;
        }
    }
    
    for(Map.Entry entry : hmp.entrySet()){            
        if((int)entry.getValue()%(words.length) != 0) return false;
    }
    return true;
}

