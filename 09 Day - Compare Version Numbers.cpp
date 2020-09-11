class Solution {
public:
    void Extract_Int(string v1, vector<long long> &array) {
        long long val = 0;
        for(int itr = 0; itr < v1.size(); itr++) {
            if(v1[itr] != '.') {
                val = val * 10;
                int a, b;
                a = int(v1[itr]);
                b = int('0');
                val += (a - b);
            }
            if(itr == v1.size() - 1) {
                array.push_back(val);            
                break;
            }
            if(v1[itr] == '.') {
                array.push_back(val);             
                val = 0;
            }            
        }
    }

    int compareVersion(string version1, string version2) {
        vector<long long> array1, array2;
        Extract_Int(version1, array1);
        Extract_Int(version2, array2);
        for(int i = 0, j = 0; i < array1.size() || j < array2.size(); i++, j++) {
            if(i < array1.size() && j < array2.size()) {
                if(array1[i] < array2[j]) return -1;
                else if(array1[i] > array2[j]) return 1;                    
            }
            else if(i < array1.size() && j >= array2.size()) {
                 if(array1[i] > 0) return 1;                     
            }
            else if(i >= array1.size() && j < array2.size()) {
                if(array2[j] > 0) return -1;                    
            }
        }   
        return 0; 
    }
};
