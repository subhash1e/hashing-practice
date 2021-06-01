#include <iostream>
#include <unordered_set>
using namespace std;
 
/* Function to check if subarray with 
two-sum is present in a given array or not*/


bool hasZeroSumSubarray(int A[], int n)
{
	unordered_set<int> set;

	set.insert(0);

	int sum = 0;
	

	for (int i = 0; i < n; ++i)
	{
		sum+=A[i];
// new sum should be greater than previous sum by 2
// if (subsequent sum)-2 is found in set already 
//it means subarray exists
		if (set.find(sum-2) != set.end())
			{
				cout <<"Subarray with a sum of  2 exists\nDisplaying Subarray ::";

				sum=A[i];
				int j=i; 
				// j is last posn of subarray


				while(sum!=2)
				{
					sum+=A[--i];
				}
				// i is start pos of subarray

				//Printing subarray(from i to j) whose sum is 2

				cout <<"{ ";
				for (;i<=j;++i)
				{
					if(i!=j)
					cout << A[i]<< ", ";
				else
					cout << A[i];
				}
				cout <<" }\n";
				return true;
				
			}

// inserting sum in set 
			// 
			//for finding if subarray of sum 2 exists
		else set.insert(sum);
	}

	cout <<"Subarray doesnt exists\n";
	return false;
}



 int main(int argc, char const *argv[])
{
	int A[] = {11,-4,1,4,11,-4,3,3,3,4,};
	int n = sizeof(A)/sizeof(A[0]);

	hasZeroSumSubarray(A,n);
		
		
	return 0;
}
