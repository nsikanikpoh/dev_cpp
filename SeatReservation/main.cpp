#include <iostream>
using namespace std;

void reserveSeat(int x, int y, char **tab)
{
	if(tab[x][y]=='X')
	cout<<"Already Reserved"<<endl;
	else
	tab[x][y]='X';

}



int main() {
char **tab = new char *[5];
for(int i = 0; i<5; i++)
{
	tab[i] = new char[4];
}
	for (int i = 0; i<5; i++)
		for (int j = 0; j<4; j++)
		{
			tab[i][j] = 65 + j;
		}

reserveSeat(0,0,tab);
reserveSeat(0,0,tab);

reserveSeat(3,3,tab);

		for (int i = 0; i<5; i++)
		{
			cout<<i+1<<" ";
		for (int j = 0; j<4; j++)
		{
			cout<<tab[i][j]<<" ";
		}
			cout<<endl;
		}

	// your code goes here
	return 0;
}
