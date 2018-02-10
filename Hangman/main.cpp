#include<iostream>

using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true) 
{
	if (printTop) {
		cout << "+---------------------------------+" << endl;
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << "|" << message.c_str() << "|"<<endl;
	if (printBottom)
	{
		cout << "+---------------------------------+" << endl;
	}
}

void DrawHangman(int guessCount=0)
{
	if (guessCount >= 1)
		PrintMessage("|", false, false);
	if(guessCount >= 2)
		PrintMessage("|", false, false);
	if (guessCount >= 3)
		PrintMessage("O", false, false);
	if (guessCount == 4)
		PrintMessage("/  ", false, false);
	if (guessCount == 5)
		PrintMessage("/| ", false, false);
	if (guessCount >= 6)
		PrintMessage("/|\\", false, false);
	if (guessCount >= 7)
		PrintMessage("|", false, false);
	if (guessCount == 8)
		PrintMessage("/  ", false, false);
	if (guessCount >= 9)
		PrintMessage("/ \\", false, false);
}

int main()
{
	PrintMessage("HANGMAN");
	DrawHangman(9);
	getchar();
	return 0;
}