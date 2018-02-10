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
	cout << "|" << message.c_str() << "|" << endl;
	if (printBottom)
	{
		cout << "+---------------------------------+" << endl;
	}
}

void DrawHangman(int guessCount = 0)
{
	if (guessCount >= 1)
		PrintMessage("|", false, false);
	if (guessCount >= 2)
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

void PrintLetters(string input, char from, char to)
{
	string alphabets;
	for (char i = from; i <= to; i++)
	{
		if (input.find(i) == string::npos)
		{
			alphabets += i;
			alphabets += " ";
		}
		else
			alphabets += "  ";
	}
	PrintMessage(alphabets, false, false);
}

void PrintRemainingLetters(string taken)
{
	PrintMessage("AVAILABLE LETTERS");
	PrintLetters(taken, 'A', 'M');
	PrintLetters(taken, 'N', 'Z');
}

bool PrintWordAndCheckWin(string word, string guess)
{
	bool won = true;
	string chkWord;
	for (int i = 0; i < word.length(); i++)
	{
		if (guess.find(word[i]) == string::npos)
		{
			chkWord += "_ ";
		}
		else
		{
			chkWord += word[i];
			chkWord += " ";
		}
	}
	PrintMessage(chkWord, false, true);
	return won;
}

int main()
{
	string guesses = "SOME";
	PrintMessage("HANGMAN");
	DrawHangman(9);
	PrintRemainingLetters(guesses);
	PrintMessage("Guess the word");
	PrintWordAndCheckWin("SOMETHING", guesses);
	getchar();
	return 0;
}