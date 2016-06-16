#include "cl.h"

int 	main()
{
	t_cl *cl;
	int		*input;
	int		*output;
	int		n;

	cl = (t_cl *)malloc(sizeof(t_cl));
	n = 5;
	input = (int *)malloc(sizeof(cl_int) * 5);
	input[0] = 2;
	input[1] = 4;
	input[2] = 6;
	input[3] = 8;
	input[4] = 10;
	output = (int *)malloc(sizeof(cl_int) * 5);
	init_cl(cl);
	run_cl(input, output, n, cl);
	
	n = -1;
	while (++n < 5)
		printf("%d\n", output[n]);



	free(input);
	free(output);
	release_cl(cl);
	return (0);
}
