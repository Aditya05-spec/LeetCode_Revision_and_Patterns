#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

unordered_map<int , bool> rowCheck;
unordered_map<int , bool> upperDiagonalCheck;
unordered_map<int , bool> lowerDiagonalCheck;

void solve(string &s, string current , int index , vector<string> &ans) {
    //Base case
    if(index >= s.length()) {
        ans.push_back(current);
        return;
    }


    //Include
    char element = s[index];
    current.push_back(element);
    solve(s , current , index+1 , ans);
    
    //Backtracking 
    current.pop_back();

    //Exclude
    solve(s , current , index+1 , ans);

}

// -------------------------------> Pattern 1 -> Include and Exclude Game <---------------------------------------
vector<string> subsequences(string s) {
    vector<string> ans;
    string output = "";

    int index=0;
    solve(s , output , index , ans);

    return ans;
}

// -------------------------------------> Sabhi ke Sabhi element ke upar for loop chala rhe h apan <-----------------------------------------------
int solve(vector<int> arr , int amount) {
    //base case
    if(amount == 0) {
        return 0;
    }

    if(amount < 0) {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0 ; i<arr.size() ; i++) {
        int ans = solve(arr , amount-arr[i]);
        if(ans != INT_MAX) {
            mini = min(mini , ans+1);
        }
    }

    return mini;
}


int coin(vector<int> coins , int amount) {
    int ans = solve(coins , amount);

    if(ans == INT_MAX) {
        return -1;
    }

    return ans;
} 

int rodCuts(int n , int x , int y , int z) {
    //Base case
    if(n == 0) {
        return 0;
    }

    if(n < 0) {
        return INT_MIN;
    }

    int ans1 = rodCuts(n-x , x , y , z) + 1;
    int ans2 = rodCuts(n-y , x , y , z) + 1;
    int ans3 = rodCuts(n-z , x , y , z) + 1;

    int ans = max(ans1 , max(ans2 , ans3));

    return ans;

    return ans;
}


void solve(vector<int> arr , int index , int sum , int &maxi) {
    //Base case
    if(index >= arr.size()) {
        maxi = max(maxi , sum);
        return;
    }

    //Include
    sum = sum + arr[index];
    solve(arr , index+2 , sum , maxi);

    //Backtracking
    sum = sum - arr[index];
    

    //exclude
    solve(arr , index+1 , sum , maxi);

}

int maxSumOfNonAdjecentElement(vector<int> v) {
    int sum = 0;
    int index = 0;
    int maxi = INT_MIN;
    solve(v , index , sum , maxi);

    return maxi;
}

void permutationSolver(vector<string> &a , vector<vector<string> > &s , int index) {
    //Base case
    if(index >= a.size()) {
        s.push_back(a);
        return;
    }

    for(int i=index ; i<a.size() ; i++) {
        swap(a[i] , a[index]);
        permutationSolver(a , s , index+1);
        swap(a[i] , a[index]);
    }
}

vector<vector<string> > permutation(vector<string> &a) {
    vector<vector<string> > s;
    int index = 0;
    permutationSolver(a , s , index);

    return s;
}


bool isSafe(int srcX , int srcY , int row , int col , int arr[3][3] , vector<vector<bool> > &visited) {
    if((srcX >= 0 && srcX < row) && (srcY >= 0 && srcY < col) && (visited[srcX][srcY] == false) && arr[srcX][srcY] == 1) {
        return true;
    }
    else {
        return false;
    }
}

void solve(int arr[3][3] , int &row , int &col , int srcX , int srcY , vector<vector<bool> > &visited , vector<string> &path , string output) {
    //Base case
    if(srcX == row-1 && srcY == col-1) {
        path.push_back(output);
        return;
    }

    //Down
    if(isSafe(srcX+1 , srcY , row , col , arr , visited)) {
        visited[srcX+1][srcY] = true;
        solve(arr , row , col , srcX+1 , srcY , visited , path , output + 'D');
        //Backtracking
        visited[srcX+1][srcY] = false;
    }

    //Left
    if(isSafe(srcX , srcY-1 , row , col , arr , visited)) {
        visited[srcX][srcY-1] = true;
        solve(arr , row , col , srcX , srcY-1 , visited , path , output + 'L');
        //Backtracking
        visited[srcX][srcY-1] = false;
    }


    
    //Right
    if(isSafe(srcX , srcY+1 , row , col , arr , visited)) {
        visited[srcX][srcY+1] = true;
        solve(arr , row , col , srcX , srcY+1 , visited , path , output + 'R');
        //Backtracking
        visited[srcX][srcY+1] = false;
    }
    

    //Up
    if(isSafe(srcX-1 , srcY , row , col , arr , visited)) {
        visited[srcX-1][srcY] = true;
        solve(arr , row , col , srcX-1 , srcY , visited , path , output + 'U');
        //Backtracking
        visited[srcX-1][srcY] = false;
    }
}




void printSolution(vector<vector<char> > &arr , int n) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

bool isSafeQueen(int row , int col , vector<vector<char> > &arr , int &n) {
    // int checkRow = row;
    // int checkCol = col;

    //Check Row --> ye check kr rhe h ki jaha queen rakh rhe h uske peeche kahi queen padi h ke nhi
    // while(checkCol >= 0) {
    //     if(arr[checkRow][checkCol] == 'Q') {
    //         return false;
    //     }
    //     checkCol--;
    // }

    //Check upper left diagonal
    // checkRow = row;
    // checkCol = col;
    // while(checkCol >= 0 && checkRow >= 0) {
    //     if(arr[checkRow][checkCol] == 'Q') {
    //         return false;
    //     }
    //     checkCol--;
    //     checkRow--;
    // }

    //Check lower left diagonal
    // checkRow = row;
    // checkCol = col;
    // while(checkCol >= 0 && checkRow < n) {
    //     if(arr[checkRow][checkCol] == 'Q') {
    //         return false;
    //     }
    //     checkCol--;
    //     checkRow++;
    // }

    //Kahi par bhi queen nhi mili iska mtlb queen nhi h kahi
    // return true;




    if(rowCheck[row] == true) {
        return false;
    }

    if(upperDiagonalCheck[n+1+col-row] == true) {
        return false;
    }

    if(lowerDiagonalCheck[row+col] == true) {
        return false;
    }

    return true;
}

void solveQueen(vector<vector<char> > &arr , int col , int &n) {
    //Base case
    if(col >= n) {
        printSolution(arr , n);
        return;
    }

    for(int row = 0; row<n ; row++) {
        if(isSafeQueen(row , col , arr , n)) {
            arr[row][col] = 'Q';
            rowCheck[row] = true;
            lowerDiagonalCheck[row+col] = true;
            upperDiagonalCheck[n+1+col-row] = true;
            solveQueen(arr , col+1 , n);
            //Backtracking
            rowCheck[row] = false;
            lowerDiagonalCheck[row+col] = false;
            upperDiagonalCheck[n+1+col-row] = false;
            arr[row][col] = '-';
        }
    }
}

int main() {

    // ------------------------------> subsequence in a given string <-----------------------------------
    // string s = "abc";

    // vector<string> result = subsequences(s);

    // for(auto i : result) {
    //     cout  << "[ "<< i << " ]";
    // }

    // ---------------------------------> fewest number of coins required to make up the amount <--------------------------------------
    // vector<int> arr(3);

    // for(int i = 0; i < 3; i++) {
    //     cin >> arr[i];
    // }

    // int ans = coin(arr , 5);
    // cout << "Minimum number of coins to make up the amount is : " << ans << endl;


    // -------------------------------------------> rod cut Game <--------------------------------------------
    // int n = 7;
    // int x = 5;
    // int y = 2;
    // int z = 2;
    // int ans = rodCuts(n,x,y,x);

    // if(ans < 0) {
    //     ans = 0;
    // }
    // cout << ans << endl;


    // --------------------------------------------> Maximum sum of non adjacent nodes <------------------------------------------
    // vector<int> v{2,1,4,9};
    // int ans = maxSumOfNonAdjecentElement(v);
    // cout << ans << endl;

    // -----------------------------------------------> Permutation in a String <-----------------------------------------------
    // vector<string> s;
    // s.push_back("a");
    // s.push_back("b");
    // s.push_back("c");
    // vector<vector<string> > result = permutation(s);

    // for(auto i : result) {
    //     for(auto j : i) {
    //         cout << j;
    //     }
    //     cout << endl;
    // }



    // ------------------------------------------>Rat in a Maze Problem <----------------------------------------------------
    // int maze[3][3] = {{1,0,0} , {1,1,0} , {1,1,1}};
    // int row = 3;
    // int col = 3;

    // if(maze[0][0] == 0) {
    //     cout << "No path exists" << endl;
    //     return 0;
    // }

    // vector<vector<bool> > visited(row , vector<bool>(col,false));
    // visited[0][0] = true;

    // vector<string> path;
    // string output = "";

    // solve(maze , row , col , 0 , 0 , visited , path , output);

    // for(auto i : path) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // if(path.size() == 0) {
    //     cout << "Not a single path exist" << endl;
    // }


    // -------------------------------------------------------->N-Queens <------------------------------------------------------
    int n = 4;
    vector<vector<char> > arr(n , vector<char>(n,'.'));
    int col = 0;
    solveQueen(arr , col , n);



    return 0;
}