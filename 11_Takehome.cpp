#include <vector>
#include <iostream>
#include <string>
#include <random>
#include<algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

bool isPalindrome_helper(string k) {
	//TODO return true if k reads the same forwards and backwards
	//The string functions size() and substr() will be handy
	// //This function should call itself recursively
	if (k.size() <= 1) {
		return true;
	}
	if (k.front() != k.back()) {
		return false;
	}
	return isPalindrome_helper(k.substr(1, k.size() - 2));
}

bool isPalindrome(string k) {
	//TODO: Remove all whitespace from the string, and call the helper function
	//The string functions erase(), and remove_if() will be handy for this processing
	k.erase(remove_if(k.begin(), k.end(), ::isspace), k.end());
	return isPalindrome_helper(k);
}

string rearrange(string k) {
	//TODO: returns the string k scrambled into a random order
	//The functions size(), substr(), erase(), and rand() will be useful
	shuffle(k.begin(), k.end(),default_random_engine(time(0)));
	return k;
}

vector<vector<int>> p_triangle_helper(int row, int goal, vector<vector<int>> res) {
	//TODO: use recursion to add rows to res until the goal value is reached
	//HINT: A for loop is useful in this function, even though it calls itself at the end
	if (row == goal) {
		return res;
	}
	vector<int> currRow(row + 1, 1);
	for (int i = 1; i < row; i++) {
		currRow[i] = res.back()[i - 1] + res.back()[i];
	}
	res.push_back(currRow);
	return p_triangle_helper(row + 1, goal, res);
}



vector<vector<int>> p_triangle(int k) {
	//TODO: return a vector of vectors of ints forming a pascal triangle of k rows
	//Each vector is one of those rows
	//This function essentially just calls the helper with the appropriate parameters
	return p_triangle_helper(0, k, {});
}


int main()
{
	//TODO: Use different values of test and rows to evaluate your code
	srand(time(0));
	//srand(static_cast<unsigned>(time(nullptr)));
	string test = "was it a cat i saw";
	int rows = 10;
	cout << boolalpha;
	cout << "Input String: " << test << endl;
	cout << "Is it a palindrome?: " << isPalindrome(test) << endl;
	cout << "After randomizing: " << rearrange(test) << endl;
	cout << "The first " << rows << " rows of Pascal's triangle" << endl;
	vector<vector<int>> triangle = p_triangle(rows);
	for (vector<int> row : triangle) {
		for (int val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
}
