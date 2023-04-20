#include<iostream>
#include<bits/stdc++.h>

using namespace std;



bool isVisited(int input[4][4], int row, int col, bool visited[4][4]) {

	return( (row>=0) && (row < 4) && (col >= 0) && (col < 4) && (input[row][col] && !visited[row][col] ) );

}



void findPath(int input[4][4], int i, int j, bool visited[4][4]) {

	static int row[] = {-1, 0, 1, 0};
	static int col[] = { 0, -1, 0, 1};

	visited[i][j] = true;

	for(int k = 0; k < 4; k++) {
		if(isVisited(input, i+row[k], j+col[k], visited) ) 
			findPath(input, i+row[k], j+col[k], visited);
	}
	return;
}



int main() {

	int input[4][4] = {
		{0, 0, 0, 0},
		{1, 0, 1, 1},
   	 	{1, 0, 1, 0},
    		{1, 1, 1, 0}
		};

	bool visited[4][4];
	memset(visited, 0, sizeof(visited));

	int count = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j <  4; ++j) {
			if(input[i][j] && !visited[i][j]) {
				findPath(input, i, j, visited) ;
				count++;
			}
		}
	}
	cout << count << endl;
}
