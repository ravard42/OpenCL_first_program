#ifndef CL_H
# define CL_H

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <OpenCL/opencl.h>


typedef struct			s_cl
{
	cl_context			context;
	cl_command_queue	cmd_queue;
	cl_kernel			kernel;
	size_t				gws;
	cl_mem				input_cl_mem;
	cl_mem				output_cl_mem;
}						t_cl;

void		init_cl(t_cl *cl);
void		run_cl(int *input, int *output, int n, t_cl *cl);;
void		release_cl(t_cl *cl);


#endif
