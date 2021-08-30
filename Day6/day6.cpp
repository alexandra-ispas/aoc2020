#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
ifstream input;

int partOne(void){
    int count = 0;
    string line, arr;
    while(getline(input, line)){
        if(line.empty()){
            count += arr.size();
            arr.clear();
        }
        while(line.length() > 0){
            if(arr.find(line[0]) == string::npos){
                // if the question has not been found before
                arr.push_back(line[0]);
            }
            line.erase(0, 1); // erase the first letter
        }
    }
    count += arr.size();
    return count;
}

int partTwo() {
    map<char, int> letters;
    int count = 0, lines = 0;
    string line;
    while(getline(input, line)){
//        cout << line << endl;
        if(line.empty()){
            for(auto it : letters){
                if(it.second == lines){
                    count++;
                }
            }
            lines = 0;
            letters.clear();
            continue;
        }
        while(line.length() > 0){
            auto it = letters.find(line[0]);
            if(it != letters.end()){
                // that letter already exists
                it->second++; // increment the number of appearances
            } else {
                letters.insert(make_pair(line[0], 1));
            }
            line.erase(0, 1); // erase the first letter
        }
        lines++;
    }
    for(auto it : letters){
        if(it.second == lines){
            count++;
        }
    }
    return count;
}

int main(void) {
    string filename = "input.txt";
    input.open(filename);
    if (!input) {
        cout << "Could not open input file.\n";
        exit(EXIT_FAILURE);
    }

//    cout << partOne() << endl;
    cout << partTwo() << endl;

    input.close();
    return 0;
}
