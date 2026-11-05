class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m , string(n , '#'));
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(i == 1) break;
                result[i][j] = '.';
            }
            if(i == 1) break;
        }

        int i=0;
        int j=n-1;
        while(i<m) {
            result[i][j] = '.';
            i++;
        }
        return result;
    }
};