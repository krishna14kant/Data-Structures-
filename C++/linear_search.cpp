#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> &array, int find_value)
{
	for (int elem : array)
		if (elem == find_value)
			return 0;

	return -1;
}

int main(void)
{
	vector<int> array;

	for (int i = 1; i <= 9; i++)
		array.push_back(i);

	cout << linear_search(array, 2) << endl;
	cout << linear_search(array, 10) << endl;
}
