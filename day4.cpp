#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

#define COMPLETION 3 //end of the needed word

int rowMax;
int colMax;

int main()
{
    ifstream file;
    file.open("input.txt");
    vector<int> v; //one line from input (one row)
    vector<vector<int>> puzzle;
    const map<char, int> m = {{'X', 0}, {'M', 1}, {'A', 2}, {'S', 3}};
    
    string line;
    int lineNum = 0;
    while(getline(file, line)){
        for(int i = 0; i < line.size(); i++){
            v.push_back(m.at(line[i]));
        }
        vector<int> temp;
        copy(v.begin(), v.end(), back_inserter(temp));
        puzzle.push_back(temp);
        v.clear();
        lineNum++;
    }
    for(int i = 0; i < puzzle.size(); i++){
        for (int j = 0; j < puzzle[i].size(); j++)
            cout << puzzle[i][j];
        cout << endl;
    }
    rowMax = puzzle.size();
    colMax = puzzle[0].size();

    file.close();
    return 0;
}
