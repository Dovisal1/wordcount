#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

ifstream infile;

int main()
{
	cout << "Please enter a filename in the current directory\n";
	cout << "Don't forget to add the extension!\n";
	cout << "Filename>>";
	char file[50];
	cin >> file;

	infile.open(file);
	if ( !infile.is_open() ) {
		cout << "ERROR: Unable to open file\n";
		exit(1);
	}
	infile.clear();

	int wordCount = 0;
	bool foundNextWord(void);

	while ( foundNextWord()  )
		wordCount++;

	cout << "File has " << wordCount << " words.\n";

	infile.close();
	return 0;
}

/************************************************/

bool foundNextWord(void)
{
	int c;

	while ( !infile.eof() && isspace(c = infile.get()) )
		;

	if (!infile.eof()) {
		while ( !infile.eof() && isspace(c=infile.get()) )
			;
		return true;
	}
	return false;
}
