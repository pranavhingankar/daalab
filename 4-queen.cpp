// Implementation of 4 queen problem using backtracking
// Name - Prathamesh Anand Mehare


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> possible_positions;
vector<vector<bool>> queen_position(4, vector<bool>(4, false));
const int N = 4;

// function to check whether the queen can be placed at given location
bool check(int row, int column) {
	for (int i = row - 1; i >= 0; i--) {
		if (queen_position[i][column])
			return false;
	}

	for (int i = column - 1, j = row - 1; i >= 0 && j >= 0; i--, j--) {
		if (queen_position[j][i])
			return false;
	}

	for (int i = column + 1, j = row - 1; i < 4 && j >= 0; i++, j--) {
		if (queen_position[j][i])
			return false;
	}

	return true;
}

void solve(vector<int> &solution, int row) {

	if (row == N) {
		possible_positions.push_back(solution);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check(row, i)) {
			solution.push_back(i);
			queen_position[row][i] = true;
			solve(solution, row + 1);
			solution.pop_back();
			queen_position[row][i] = false;
		}
	}
}

int main() {

	vector<int> solution;
	solve(solution, 0);

	// printing the positions of possible solutions
	cout << "\trow1\trow2\trow3\trow4" << endl;
	cout << endl;

	for (auto answer : possible_positions) {

		cout << "column  ";
		for (auto positions : answer)
			cout << positions << "\t";

		cout << endl;
	}

	return 0;
}