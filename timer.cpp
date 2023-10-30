#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
using namespace std;

 struct Person
{
  string SSN;
  string name;
};

int main(int argc, char* argv[])
{
	fstream input;
	input.open(argv[1]);
	char IDR;
	string Name; 
	string SSN;
	string First;
	string Last;
	

	int insertionCount = 0;
	int deletionCount = 0;
	int retrievalCount = 0;
	int ArraySize = 1000;
	int numPersons = 0;
	Person *People = new Person[ArraySize];
 	clock_t start, end;
  	double duration;

  	start = clock();

	while(!input.eof())
	{	
		input>>IDR;
		
		input>>SSN;
		input>>First;
		input>>Last;

		Name = First + " " + Last;

		
		 Person p = {SSN, Name};

		switch(IDR)
		{
			case 'i':
			{

			bool matchfound = false;
			for (int i = 0; i < numPersons; i++)
			{
				if ((p.SSN).compare(People[i].SSN) ==0)
				{
					matchfound = true;
					break;
				}

			}
			if (!matchfound)
			{
				if (numPersons == ArraySize)
				{
					// The current array is full, we need to create double sized array
					ArraySize *=2; 
					Person *New_People = new Person[ArraySize];

					// Copy People elements to shadow
					for (int i = 0; i<numPersons; i++)
					{
						New_People[i] = People[i];
					}

					// Delete People
					delete [] People; 
					People = New_People;

				}
				else
				{
					//  increment insertionCount, and append element to end of array
					People[numPersons].name = p.name;
					People[numPersons].SSN = p.SSN;
					insertionCount++;
					numPersons++;
				}
			}
			break;
			}

			case 'd':
			{
				for (int i = 0; i < numPersons; i++)
				{
					if (((p.name).compare(People[i].name)) == 0 && ((p.SSN).compare(People[i].SSN) == 0 ))
					{
						if(numPersons < (ArraySize/4))
						{
							ArraySize /=2; 
						Person *New_People = new Person[ArraySize];
						for(int i = 0; i<numPersons; i++)
						{
							New_People[i] = People[i];
						}
						delete [] People;
						People = New_People;

						for(int pos = i+1; pos<numPersons; pos++)
						{
							People[pos-1] = People[pos];
						}
						numPersons--;
						deletionCount++;
						break;
						}
						else
						{
						for(int pos = i+1; pos<numPersons; pos++)
						{
							People[pos-1] = People[pos];
						}
						numPersons--;
						deletionCount++;
						break;
						}
					}
				}
				break;

			}
			
			case 'r':
			{
				for (int i = 0; i < numPersons; i++)
				{
					if ((p.name).compare(People[i].name) == 0 && (p.SSN).compare(People[i].SSN) == 0 )
					{
						retrievalCount++;
						break;
					}
				}
				break;
			}
		}
	}
	end = clock();
  	duration = ( end - start ) / (double) CLOCKS_PER_SEC;

	cout<< "The Number of Valid Insertation: " <<insertionCount<<endl;
	cout<< "The Number of Valid Deletion: "<<deletionCount<<endl;
	cout<< "The Number of Valid Retrieval: "<<retrievalCount<<endl;
	cout<<"Item numbers in the array: "<<numPersons<<endl;
	cout<<"Array Size is: "<< ArraySize<<endl;
	cout<<"Time elapsed: "<<duration<<endl;
}
