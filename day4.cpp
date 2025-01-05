//Idea, if we really want speed, doing this with threads would do

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

#define START 0 //start of the needed word
#define COMPLETION 3 //end of the needed word

//Directions
#define UPLEFTDIAGONAL 0  
#define UP 1  
#define UPRIGHTDIAGONAL 2  
#define LEFT 3  
#define RIGHT 4  
#define DOWNLEFTDIAGONAL 5  
#define DOWN 6  
#define DOWNRIGHTDIAGONAL 7  
#define ALL 8  

//Globals
int rowMax;
int colMax;
int sum1; //part 1 answer
vector<vector<int>> puzzle; //would like to avoid the heap if possible, but idk
const map<char, int> m = {{'X', 0}, {'M', 1}, {'A', 2}, {'S', 3}};
    
//Functions
void neighbors(int letter, int direction, int row, int col);
bool XFormat(int row, int col);

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
    rowMax = puzzle.size();
    colMax = puzzle[0].size();

    //Part 1
    for(int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if(puzzle[i][j] == START){ 
                neighbors(0, ALL, i, j);
            }
        }
    }

    //Part 2
    int sum2 = 0;
    for(int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if(puzzle[i][j] == m.at('A')){ //2 = A 
                if (XFormat(i, j)) sum2++;
            }
        }
    }

    cout << sum1 << endl;
    cout << sum2 << endl;

    file.close();
    return 0;
}

//part 1
void neighbors(int letter, int direction, int row, int col){
    if(letter == COMPLETION){
        sum1++;
        return;
    }
    if((row - 1) >= 0) {
        if((direction == ALL || direction == UPLEFTDIAGONAL)&&((col - 1) >= 0)){ //(row-1, col-1)
            if(puzzle[row-1][col-1] == letter + 1){
                neighbors(letter+1, UPLEFTDIAGONAL, row-1, col-1);
            }
        }
        if((direction == ALL || direction == UPRIGHTDIAGONAL)&&((col + 1) < colMax)){//(row-1, col+1)
            if(puzzle[row-1][col+1] == letter + 1) neighbors(letter+1, UPRIGHTDIAGONAL, row-1, col+1);
        }
        if((direction == ALL || direction == UP)&&(puzzle[row-1][col] == letter + 1)) 
            neighbors(letter+1, UP, row-1, col);//(row-1, col)
    }    
    if((row + 1) < rowMax) {
        if((direction == ALL || direction == DOWNLEFTDIAGONAL)&&((col - 1) >= 0)){//(row+1, col-1)
            if(puzzle[row+1][col-1] == letter + 1) neighbors(letter+1, DOWNLEFTDIAGONAL, row+1, col-1);
        }
        if((direction == ALL || direction == DOWNRIGHTDIAGONAL)&&((col + 1) < colMax)){//(row+1, col+1)
            if(puzzle[row+1][col+1] == letter + 1) neighbors(letter+1, DOWNRIGHTDIAGONAL, row+1, col+1);
        }
        if((direction == ALL || direction == DOWN)&&(puzzle[row+1][col] == letter + 1)) neighbors(letter+1, DOWN, row+1, col);//(row+1, col)
    }
    if((direction == ALL || direction == LEFT)&&((col - 1) >= 0)){//(row, col-1)
        if(puzzle[row][col-1] == letter + 1) neighbors(letter+1, LEFT, row, col-1);
    }
    if((direction == ALL || direction == RIGHT)&&((col + 1) < colMax)){//(row, col+1)
        if(puzzle[row][col+1] == letter + 1) neighbors(letter+1, RIGHT, row, col+1);
    }
}

//Part 2
bool XFormat(int row, int col){
    if(row == 0 || col == 0 || row == rowMax-1 || col == colMax-1) return false;
    int topleft = puzzle[row-1][col-1];
    int topright = puzzle[row-1][col+1];
    int bottomleft = puzzle[row+1][col-1];
    int bottomright = puzzle[row+1][col+1];

    if(topleft == m.at('X') || topleft == m.at('A')) return false;
    if(topright == m.at('X') || topright == m.at('A')) return false;
    if(bottomleft == m.at('X') || bottomleft == m.at('A')) return false;
    if(bottomright == m.at('X') || bottomright == m.at('A')) return false;

    if (topleft == m.at('M') && bottomright != m.at('S'))return false;
    else if (topleft == m.at('S') && bottomright != m.at('M'))return false;
    else if (topleft = m.at('X')) return false;
    if (topright == m.at('M') && bottomleft != m.at('S'))return false;
    else if (topright == m.at('S') && bottomleft != m.at('M'))return false;
    else if (topright == m.at('X')) return false;
    
    return true;
}