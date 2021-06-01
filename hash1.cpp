/*
Description:

Code for saving contacts with phone no. and Name
hash using phone no.

insert delete and search is done in constant time complexity

*/

#include <iostream>
using namespace std;

#define SIZE 29
#define ll long long int 



struct Contacts
{
	string Name;
	ll Phone;
	
};

struct Contacts* hashArray[SIZE];
//hash function return index


ll hashCode(ll Phone)
{
	return Phone%SIZE;
}

//search method

struct Contacts *search(ll Phone){
	//get hash 
	ll hashindex = hashCode(Phone);

	//move in array until an empty
	while(hashArray[hashindex]!=NULL)
	{
		if (hashArray[hashindex]->Phone == Phone)
				return hashArray[hashindex];
		//else go to next cell
			hashindex = (hashindex+1)%SIZE;
			// wrap around the table
	}


// linear probing
	return NULL;


}


// insert method

void insert(ll Phone, string Name)
{
	ll hashindex = hashCode(Phone);
	struct Contacts *Item  = (struct Contacts*)malloc(sizeof(struct Contacts));
	Item->Name = Name;
	Item->Phone = Phone;

	//move in array until an empty or deleted cell

	while(hashArray[hashindex] != NULL && hashArray[hashindex]->Phone != -1){

		++hashindex;
		hashindex%=SIZE;
	}

	hashArray[hashindex] = Item ;

}

// Delete Operation

struct Contacts* deleteC(struct Contacts *Item)
{
	//get Phone
	ll iPhone = Item->Phone;

	struct Contacts *dummyItem  = (struct Contacts*)malloc(sizeof(struct Contacts));
dummyItem->Phone = -1;


	//get the hash
	ll hashindex = hashCode(iPhone);

	// move in array until an empty
	while(hashArray[hashindex]!=NULL)
	{
		if (hashArray[hashindex]->Phone == iPhone)
		{
			struct Contacts* temp = hashArray[hashindex];
			//assign it a dummy
			hashArray[hashindex]  = dummyItem;
			return temp;

		}

		//go and search for next cell
		++hashindex;
		hashindex%=SIZE;

	}
	return NULL;
}






int main(int argc, char const *argv[])
{
	
	struct Contacts *x1;
	insert(95213994,"Subhash Kumar");
	insert(90857192,"Rahul Kumar");
	insert(82941076,"shk");

	x1 = search(95213994);
	cout << x1->Name << endl;
	x1  = search(82941076);
	cout << x1->Name << endl;

	
}
