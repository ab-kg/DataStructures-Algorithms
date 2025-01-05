#include <iostream>
using namespace std;



void badSwap(int x , int y );
void goodSwap(int& x , int& y );


int main()
{
	int myScore = 50 ;
	int yourScore = 100;
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << endl;

	cout << "calling badSwap" << endl;
	badSwap(myScore , yourScore);
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << endl;

	cout << "calling goodSwap" << endl;
	goodSwap(myScore , yourScore);

	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << endl;

}


// without using reference 
void badSwap(int x , int y )
{
	int temp = x ;
	x = y ;
	y = temp ;
}

// when we use reference suddenly we got good stuff .
void goodSwap(int& x  , int & y )
{
	int temp = x ;
	x = y ;
	y = temp;
}
