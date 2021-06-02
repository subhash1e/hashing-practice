/*
Find a pair with the given sum in an array

ex - 
arr = [8,7,2,5,3,1]
sum = 10

output:
Pair found (8,2)
Pair found (7,3)


// method 1 : using brute force method  - O(n^2)
	method 2 : using sorting - low = 0, hi = n-1
	{
	 // loop till the search space is exhausted
    while (low < high)
      {
        // sum found
        if (arr[low] + arr[high] == sum)
        {
            cout << "Pair found (" << arr[low] << ", " << arr[high] << ")" << endl;
            return;
        }
 
        // increment `low` index if the total is less than the desired sum;

        // decrement `high` index if the total is more than the desired sum


        (arr[low] + arr[high] < sum)? low++: high--;
      }
	}
	T = O(nlogn)





method 3 :
Using HASHINg---T = O(n)




*/
/* unordered map is implemented using hashing
map<key,value>
map<arr[i],i>

*/

#include<iostream>

#include <unordered_map>
using namespace std;

//function to find pair

void findPair(int arr[], int n, int sum)
{
  //create empty map
  unordered_map<int, int> map;  // map[key]  = value


for (int i = 0; i < n; ++i)
{
  map[arr[i]] =  i ; //pair (arr[i],i) randomly stored in map using hash
}


  for (int i = 0; i < n; ++i)
  {
    // check pair (arr[i], sum-arr[i]) exists

    int secndNo = sum - arr[i];

    if(map.find(secndNo)!= map.end()) // {firstNo =(arr[i]),secndNo=(sum-arr[i])} found
    {
      cout << "Pair found (" << arr[i]<<", "<<arr[map[sum-arr[i]]]<<")\n";
      return;
    }



   /* // store i value with key arr[i]in map (arr[0],0)(arr[1],1)(arr[2],2),etc.
    map[arr[i]] = i;*/
  }
  //
  cout << "Pair not found\n";
}

int main(int argc, char const *argv[])
{
  int arr[] = {5,2,1,-1,1,3,7};
  int sum = 3;
  int n=sizeof(arr)/sizeof(arr[0]);
  findPair(arr,n,sum);
  return 0;
}