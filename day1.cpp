#include <iostream>
#include <fstream>
#include <list>
#include <cmath>

using namespace std;

int main()
{
    list<int> left;
    list<int> right;
    ifstream file;
    file.open("file.txt");
    int input;
    int count = 0;
    int sum = 0;
    
    while(file >> input){
	    if(count % 2 == 0)
		    left.push_back(input);
	    
	    else
		    right.push_back(input);
	    count++;
    }

    /*
    cout << "left" << endl;
    for(auto it = left.begin(); it != left.end(); ++it)
	    cout << *it << " ";
    cout << endl;
   
    cout << "right" << endl;
    for(auto it = right.begin(); it != right.end(); ++it)
	    cout << *it << " ";
    cout << endl;
   */

    left.sort();
    right.sort();

    auto lit = left.begin();
    auto rit = right.begin();
    for(int i = 0; i < left.size(); i++){
	    sum += abs(*lit - *rit);
	    ++lit;
	    ++rit;
    }

    cout << sum << endl;    
    
    file.close();
    return 0;
}
