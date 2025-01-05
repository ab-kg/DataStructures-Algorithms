#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string>& inventory);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield"); ; 

	display(inventory);

}

void display(const vector<string>& vec){
	cout << "your items:" << endl;
	for(vector<string>::const_iterator it = vec.begin(); it != vec.end() ; ++it){
		cout << *it << endl;
	}
}