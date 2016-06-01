#include "cl.h"

int 	main()
{
	int		*input;
	int		*output;
	int		n;

	n = 5;
	input = (int *)malloc(sizeof(cl_int) * 5);
	input[0] = 2;
	input[1] = 4;
	input[2] = 6;
	input[3] = 8;
	input[4] = 10;
	output = (int *)malloc(sizeof(cl_int) * 5);
	run_cl(input, output, n);
	
	n = -1;
	while (++n < 5)
		printf("%d\n", output[n]);



	free(input);
	free(output);
	return (0);
}
