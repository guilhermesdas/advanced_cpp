#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    map<string, vector<int>> scores;

    scores["Gui"].push_back(7);
    scores["Gui"].push_back(2);
    scores["Gui"].push_back(0);
    scores["Ale"].push_back(2);
    scores["Ale"].push_back(5);
    scores["Ale"].push_back(1);

    for ( auto score : scores ){
        sort(score.second.begin(), score.second.end());
        cout << score.first << ": ";
        for ( int i : score.second ){
            cout << i << ", ";
        }
        cout << endl;
    }


}