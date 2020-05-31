/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/tsp-2-1/submissions/code/1321019894
 * Title: hw4_3
 * Abstract: This program reads an input data from a user first. Then, it should present a path.
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 02/19/2020
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

void display(int a[], int n);
void findPermutations(int a[], int n);
int findPath(vector<string>& city, string index);

int main()
{
    vector<vector<int>> perm;
    vector<string> output;
    int min = 0;
    vector<string> city;
    int vertices;
    int edges;
//    int temp = -1;

    cin >> vertices;
    vector<vector<int>> row;
    int a[vertices];

    for(int i = 0; i < vertices; i++)
    {
        a[i] = i;
    }

    findPermutations(a, vertices);

    for(int i = 0; i < vertices; i++)
    {
        vector<int> column;
        for(int j = 0; j < vertices; j++)
        {
            column.push_back(-1);
        }
        row.push_back(column);
    }

    string temp_city;

    for(int i = 0; i < vertices; i++)
    {
        cin >> temp_city;
        city.push_back(temp_city);
    }

    cin >> edges;
    string to, from;
    int weight;
    int x, y;

    for(int i = 0; i < edges; i++)
    {
        cin >> to;
        cin >> from;
        cin >> weight;
        x = findPath(city, to);
        y = findPath(city, from);
        row[x][y] = weight;
        if(min < weight)
        {
            min = weight;
        }
    }

    int positionIndex = -1;
    int variable = INT_MAX;

    for(int i = 0; i < perm.size();i++)
    {
        int sum = 0;
        for(int j = 0; j < vertices; j++) {
            if(row[perm[i][j]][perm[i][j+1]] != -1) {
                sum = sum + row[perm[i][j]][perm[i][j+1]];
            }
            else {
                sum = INT_MAX;
                break;
            }
        }
        if(sum < variable) {
            variable = sum;
            positionIndex = i;
        }
    }

    if(positionIndex == -1)
    {
        cout << "Path:" <<endl;
        cout << "Cost:-1" << endl;
    }else{
        for(int i = 0; i < vertices+1; i++)
        {
            output.push_back(city[perm[positionIndex][i]]);
        }

        cout << "Path:";
        for(int i =0; i < output.size();i++)
        {
            if(output.size()-1 != i)
            {
                cout << output[i] << "->";
            }
            else{
                cout << output[i];
            }
        }
        cout << endl;
        cout << "Cost:" << variable <<  endl;
    }
}

void display(int a[], int n)
{
    vector<int> permutations;
    for (int i = 0; i < n; i++)
    {
        permutations.push_back(a[i]);
    }
    permutations.push_back(0);
    perm.push_back(permutations);
}

// Function to find the permutations
void findPermutations(int a[], int n)
{
    // From library__Find all possible permutations
    while (next_permutation(a+1, a + n))
    {
        display(a, n);
    }
}

int findPath(vector<string>& city, string index)
{
    int pos =-1;
    for(int i = 0; i < city.size(); i++)
    {
        if(index == city[i])
        {
            pos = i;
        }
    }
    return pos;
}
