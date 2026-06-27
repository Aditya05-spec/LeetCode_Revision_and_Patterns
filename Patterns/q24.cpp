#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>> &points , int day , int last) {
    //Base case
    if(day == 0) {
        int maxi = 0;
        for(int i=0 ; i<3 ; i++) {
            if(i != last) {
                maxi = max(maxi , points[0][i]);
            }
        } 
        return maxi;  
    }

    //Solution for one case
    int maxi = 0;
    for(int i=0 ; i<3 ; i++) {
        if(i != last) {
            int point = points[day][i] + solve(points , day-1 , i);
            maxi = max(maxi , point);
        }
    }
    return maxi;
}

int ninjaTraning(vector<vector<int>> &points) {
    return solve(points , points.size()-1 , 3);
}

int main() {
    vector<vector<int>> points;
    vector<int> row1;
    row1.push_back(10);
    row1.push_back(40);
    row1.push_back(70);
    points.push_back(row1);

    vector<int> row2;
    row2.push_back(20);
    row2.push_back(50);
    row2.push_back(80);
    points.push_back(row2);

    vector<int> row3;
    row3.push_back(30);
    row3.push_back(60);
    row3.push_back(90);
    points.push_back(row3);

    // vector<int> row1;
    // row1.push_back(10);
    // row1.push_back(20);
    // row1.push_back(30);
    // points.push_back(row1);

    cout << ninjaTraning(points);
    return 0;
}