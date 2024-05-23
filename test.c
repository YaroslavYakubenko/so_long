#include <stdio.h>

int main(void)
{
	printf("\033[0;31mRED\033[0m, \033[1;42mGREEN\033[0m, \033[4;34mBLUE\033[0m, \033[45mPURPLE\033[0m, \033[1;36mCYAN\033[0m");
	printf("\n\033[1;31m""\n  ERROR » ""\033[0m" "\033[1;34m""error msg\n\n""\033[0m\n");
	return (0);
}

// # define COLOR_RESET "\033[0m"
// # define COLOR_RED "\033[1;31m"
// # define COLOR_GREEN "\033[1;32m"
// # define COLOR_BLUE "\033[1;34m"
// # define COLOR_PURPLE "\033[1;35m"
// # define COLOR_CYAN "\033[1;36m"