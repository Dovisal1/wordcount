
#include <iostream>
#include <fstream>
#include <cctype>

unsigned int wc(std::istream &is)
{
	unsigned int wc = 0;
	int b = ' ', c;

	while ((c = is.get()) != EOF) {
		if (isspace(b) && !isspace(c))
			wc++;
		b = c;
	}

	return wc;
}

int main(int argc, char **argv)
{
	std::ifstream f;
	if (argc == 2)
		std::ifstream f(argv[1]);

	std::istream &in = (argc == 2) ? f : std::cin;

	std::cout << wc(in) << std::endl;

	if (argc == 2) f.close();

	return 0;
}


