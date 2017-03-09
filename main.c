#include "cl.h"

int 	main(int argc, char **argv)
{
	t_cl *cl;
	float		*input;
	float		*output;
	int		i;

	if (argc != 3)
		return (0);
	cl = (t_cl *)malloc(sizeof(t_cl));
	cl->context = NULL;
	input = (float *)malloc(sizeof(float) * 7);
	input[0] = 2.001;
	input[1] = 4.001;
	input[2] = 6.001;
	input[3] = 8.001;
	input[4] = 10.001;
	input[5] = 47;
	input[6] = 53;
	output = (float *)malloc(sizeof(float) * 7);
	output[6] = 19;


	cl->gws[0] = 5;
	init_cl(0, argv[1], cl);
	cl->gws[1] = 7;
	init_cl(1, argv[2], cl);

	
	run_cl(0, input, output, cl);
	i = -1;
	while (++i < 7)
		printf("%f\n", output[i]);

	run_cl(1, input, output, cl);
	i = -1;
	while (++i < 7)
		printf("%f\n", output[i]);

	
	free(input);
	free(output);
	release_cl(cl);
	return (0);
}
