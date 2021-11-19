#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Draw(int sirka, int vyska,int player_x, int player_y)
{
	// malování okénka:
	
	// ┌  218

	// ┐  191

	// └  192

	// ┘  217

	// ─  196

	// │  179

	// ▄  220

	for (int y = 0; y < vyska; y++) 
	{
		for (int x = 0; x < sirka; x++)
		{
			if ((y == 0) && (x == 0))
			{
				cout << (char)218;
			}
			else if ((y == vyska - 1) && (x == 0))
			{
				cout << (char)192;
			}
			else if ((y == 0) && (x == sirka - 1))
			{
				cout << (char)191;
			}
			else if ((y == vyska - 1) && (x == sirka - 1))
			{
				cout << (char)217;
			}
			else if(y == 0)
			{
				cout << (char)196;
			}
			else if(y == vyska-1)
			{
				cout << (char)196;
			}
      		else if(x == 0)
			{
				cout << (char)179;
			}
			else if(x == sirka - 1)
			{
				cout << (char)179;
			}
			else if ((x == player_x)&&(y == player_y))
			{
				cout << (char)220;
			}
			else 
			{
				cout << " ";
			}




		}
		cout << "\n";
	}
}

int main()
{

	char znak;

	int player_x = 10;
	int player_y = 5;

	while (true)
	{
		if (_kbhit()) {

			znak = _getch();

			if (static_cast<int>(znak) == 27) // Escape
			{
				break;
			}
			else if (static_cast<int>(znak) == 72) // Arrow up
			{
				player_y--;
			}
			else if (static_cast<int>(znak) == 80) // Arrow right
			{
				player_y++;
			}
			else if (static_cast<int>(znak) == 75) // Arrow left
			{
				player_x--;
			}
			else if (static_cast<int>(znak) == 77) // Arrow down
			{
				player_x++;
			}
			
			//cout << "Znak: " << znak << " (ASCII:" << static_cast<int>(znak) << ")\n";

		}

		//cout << "nic\n";
		Draw(20,10, player_x, player_y);
		Sleep(100);
		system("cls");
		//Sleep(50);
	}

}