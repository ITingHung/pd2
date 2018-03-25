#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	cout << "6 8 1 7 C 4 9 2" << endl;
	string map;
	int i;
	int mana;
	char deck[4];
	int mana_need[4];
	int number_tower;
	int towerhp[6];
while(1){
	getline(cin,map);

	if(map == "BEGIN")
	{
		while(1)
		{
			cin >> map;
			if (map == "END")
			{
				break;
			}
			if (map == "MANA")
			{
				cin >> mana;
			}
			if (map == "DECK")
			{
				for(i=0; i<4; i++) cin >> deck[i];
			}
			if (map == "TOWER")
			{
				cin >> number_tower;
				cin >> towerhp[number_tower];
			}
		}
	}
	
	for(i=0; i<4; i++)
	{
		switch(deck[i])
		{
			case '1':
				mana_need[i] = 5;
				break;
			case '7':
				mana_need[i] = 8;
				break;
			case '8':
				mana_need[i] = 5;
				break;
			case 'C':
				mana_need[i] = 7;
				break;
			case '4':
				mana_need[i] = 6;
				break;
			case '9':
				mana_need[i] = 3;
				break;
			case '6':
				mana_need[i] = 4;
				break;
			case '2': 
				mana_need[i] = 3;
				break;
		}
		if (mana_need[i] <= mana)
		{
			if (deck[i] == '9')
			{
				cout << "1 9 1 1" << endl << "0" << endl;
			}
			if (deck[i] != '9')
			{
				cout << "1 " << deck[i] << " 5 24" << endl << "0" << endl;
			}
		}
	}
}
	return  0;
}
