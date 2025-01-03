//Idea, if we really want speed, doing this with threads would do

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

#define COMPLETION 4 //end of the needed word

//Globals
int rowMax;
int colMax;
int sum;
vector<vector<int>> puzzle; //would like to avoid the heap if possible, but idk
const map<char, int> m = {{'X', 1}, {'M', 2}, {'A', 3}, {'S', 4}};
    
//Functions
void neighbors(int letter, int row, int col);

int main()
{
    ifstream file;
    file.open("input.txt");
    vector<int> v; //one line from input (one row)
    
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
    // for(int i = 0; i < puzzle.size(); i++){
    //     for (int j = 0; j < puzzle[i].size(); j++)
    //         cout << puzzle[i][j];
    //     cout << endl;
    // }
    rowMax = puzzle.size();
    colMax = puzzle[0].size();

    //Part 1
    for(int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if(puzzle[i][j] == 0) neighbors(0, i, j);
            cout << "found x at " << i << ", " << j << " where it is " << puzzle[i][j] << endl;
        }
    }

    cout << sum;

    file.close();
    return 0;
}

void neighbors(int letter, int row, int col){
    if(letter == COMPLETION){
        sum++;
        return;
    }
    if((row - 1) >= 0) {
        if((col - 1) >= 0){ //(row-1, col-1)
            if(puzzle[row-1][col-1] == letter + 1) neighbors(letter+1, row-1, col-1);
        }
        if((col + 1) < colMax){//(row-1, col+1)
            if(puzzle[row-1][col+1] == letter + 1) neighbors(letter+1, row-1, col+1);
        }
        if(puzzle[row-1][col] == letter + 1) neighbors(letter+1, row-1, col);//(row-1, col)
    }    
    if((row + 1) < rowMax) {
        if((col - 1) >= 0){//(row+1, col-1)
            if(puzzle[row+1][col-1] == letter + 1) neighbors(letter+1, row+1, col-1);
        }
        if((col + 1) < colMax){//(row+1, col+1)
            if(puzzle[row+1][col+1] == letter + 1) neighbors(letter+1, row+1, col+1);
        }
        if(puzzle[row+1][col] == letter + 1) neighbors(letter+1, row+1, col);//(row+1, col)
    }
    if((col - 1) >= 0){//(row, col-1)
        if(puzzle[row][col-1] == letter + 1) neighbors(letter+1, row, col-1);
    }
    if((col + 1) < colMax){//(row, col+1)
        if(puzzle[row][col+1] == letter + 1) neighbors(letter+1, row, col+1);
    }
}