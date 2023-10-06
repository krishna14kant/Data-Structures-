#include <iostream>
using namespace std;

int tripletSum(int *input, int size, int x)
{
	int count=0;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
            for (int k = j+1; k < size; k++) {
                if (i==j==k){
				    continue;
			    }
			    else{
				    if(input[i]+input[j]+input[k]==x){
					    count++;
				    }
			    }
		    }
        }
    }
	return count;
}

int main()
{
	int size;
	int x;
  cout<<"enter the size of array: ";
	cin >> size;

	int *input = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
	}
  cout<<"enter the sum of elements to be found: ";
	cin >> x;

	cout << tripletSum(input, size, x) << endl;
	delete[] input;
	return 0;
}
