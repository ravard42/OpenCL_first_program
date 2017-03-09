#ifndef CL_H
# define CL_H

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>

#include <OpenCL/opencl.h>

typedef struct					s_cl
{
	cl_context			context;
	cl_command_queue		cmd_queue;
	size_t				gws[2];
	cl_kernel			kernel[2];
	cl_mem				input_cl_mem[2];
	cl_mem				output_cl_mem[2];
}						t_cl;

void		init_cl(int kernel_id, char *kernel_path, t_cl *cl);
void		run_cl(int kernel_id, float *input, float *output, t_cl *cl);
void		release_cl(t_cl *cl);


#endif
