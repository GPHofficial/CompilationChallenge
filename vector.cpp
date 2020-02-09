#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
    
    ifstream data ("input.csv");
    string line;
    vector<vector<int>> matrix1, matrix2;

    int i = 0;
    for(i = 0;i<1024;i++)
    {
        getline(data,line);
        stringstream lineStream(line);
        string cell;
        vector<int> parsedRow;
        
        while(getline(lineStream,cell,',')){
            parsedRow.push_back(stoi(cell));
        }
        matrix1.push_back(parsedRow);
    }
    cout << matrix1.size() << '\n';
    getline(data,line);
    for(i = 1025;i<2049;i++)
    {
        getline(data,line);
        stringstream lineStream(line);
        string cell;
        vector<int> parsedRow;
        
        while(getline(lineStream,cell,',')){
            parsedRow.push_back(stoi(cell));
        }
        matrix2.push_back(parsedRow);
    }
    cout << matrix2.size() << '\n';
    
    int j = 0;
    ofstream outputCSV;
    outputCSV.open("output.csv");
    string row;
    for(i=0; i<1024; i++){
        row = "";
        for(j=0; j<1024; j++){
           row += to_string(matrix1[i][j]);
           row += ",";
        }
        row = row.substr(0, row.size()-1);
        outputCSV << row << endl;
    }
    outputCSV.close();
}