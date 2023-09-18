#include "main.h"
/**
 * main - the first function to be executed 
 * the main function of shell
 * @argc: this is an argument count
 * @argv: this is an argument vector
 * Return: 0 on success 1 for fail
 */

int main(int argc, char **argv)
{
	my_info_stShll my_infoShll[] = { MY_INFO_INITSHLL };

	int my_fdShll = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (my_fdShll)
			: "r" (my_fdShll));

	if (argc == 2)
	{
		my_fdShll = open(argv[1], MY_O_RDONLYSHLL);
		if (my_fdShll == -1)
		{
			if (errno == MY_EACCESSHLL)
				exit(126);

			if (errno == MY_ENOENTSHLL)
			{
				_eputsShll(argv[0]);
				_eputsShll(": 0: can't open ");
				_eputsShll(argv[1]);
				_eputcharShll('\n');
				_eputcharShll(MY_BUF_FLUSHSHLL);
				exit(127);
			}
			return (MY_EXIT_FAILURESHLL);
		}
		/*This code is created by Mehdi and Amina*/
		my_infoShll->readfd = my_fdShll;
	}
	my_populate_env_listShll(my_infoShll);
	my_read_historyShll(my_infoShll);
	my_hshShll(my_infoShll, argv);
	return (MY_EXIT_SUCCESSSHLL);
}

