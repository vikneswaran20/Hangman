#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<time.h>

using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
			message = " " + message;
		else
			message = message + " ";
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
	else
		PrintMessage("", false, false);
	if (guessCount >= 2)
		PrintMessage("|", false, false);
	else
		PrintMessage("", false, false);
	if (guessCount >= 3)
		PrintMessage("O", false, false);
	else
		PrintMessage("", false, false);
	if (guessCount == 4)
		PrintMessage("/  ", false, false);
	if (guessCount == 5)
		PrintMessage("/| ", false, false);
	if (guessCount >= 6)
		PrintMessage("/|\\", false, false);
	else
		PrintMessage("", false, false);
	if (guessCount >= 7)
		PrintMessage("|", false, false);
	else
		PrintMessage("", false, false);
	if (guessCount == 8)
		PrintMessage("/  ", false, false);
	if (guessCount >= 9)
		PrintMessage("/ \\", false, false);
	else
		PrintMessage("", false, false);
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
			won = false;
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

string LoadRandomWord(string path)
{
	string word;
	vector<string> words;
	ifstream reader(path);
	if (reader.is_open())
	{
		while (getline(reader, word))
		{
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			words.push_back(word);
		}
		int randomLine = rand() % words.size();

		word = words.at(randomLine);
		reader.close();
	}
	return word;
}

int TriesLeft(string word, string guessed)
{
	int error = 0;
	for (int i = 0; i < guessed.length(); i++)
	{
		if (word.find(guessed[i]) == string::npos)
			error++;
	}
	return error;
}

int main()
{
	srand(time(0));
	int tries = 0;
	bool win = false;
	string guesses;
	string wordToBeGuess = LoadRandomWord("words.txt");
	do
	{
		system("cls");
		PrintMessage("HANGMAN");
		DrawHangman(tries);
		PrintRemainingLetters(guesses);
		PrintMessage("Guess the word");
		win = PrintWordAndCheckWin(wordToBeGuess, guesses);

		if (win)
			break;

		char in;
		cout << ">"; cin >> in;
		if (guesses.find(in) == string::npos)
			guesses += in;

		tries = TriesLeft(wordToBeGuess, guesses);
	} while (tries < 10);

	if (win)
		PrintMessage("YOU WON THE GAME!", false, true);
	else
	{
		PrintMessage("YOU LOST THE GAME!", true, false);
		PrintMessage("WORD: " + wordToBeGuess);
	}

	system("pause");
	return 0;
}