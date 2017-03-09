#include "cl.h"

char	*load_program_source(char *kernel_path)
{
	int	fd;
	char	*line;
	char	*source;

	line = NULL;
	source = (char *)ft_memalloc(sizeof(char) * 42000);
	fd = open(kernel_path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

void	init_cl(int ker_id, char *kernel_path, t_cl *cl)
{
	cl_device_id			device;
	char 				*source;
	cl_program			program;

	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (!cl->context)	
	{
		cl->context = clCreateContext(0, 1, &device, NULL, NULL, NULL);
		cl->cmd_queue = clCreateCommandQueue(cl->context, device, 0, NULL);
	}
	source = load_program_source(kernel_path);
	program = clCreateProgramWithSource(cl->context, 1, (const char **)&source, NULL, NULL);
	free(source);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	cl->kernel[ker_id] = clCreateKernel(program, "thread", NULL);
	cl->input_cl_mem[ker_id] = clCreateBuffer(cl->context, CL_MEM_READ_ONLY, cl->gws[ker_id] * sizeof(float), NULL, NULL);
	cl->output_cl_mem[ker_id] = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, cl->gws[ker_id] * sizeof(float), NULL, NULL);
}

void	run_cl(int ker_id, float *input, float *output, t_cl *cl)
{	
	clEnqueueWriteBuffer(cl->cmd_queue, cl->input_cl_mem[ker_id], CL_TRUE, 0, cl->gws[ker_id] * sizeof(float), (void *)input, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
	
	clSetKernelArg(cl->kernel[ker_id], 0, sizeof(cl_mem), &cl->input_cl_mem[ker_id]);
	clSetKernelArg(cl->kernel[ker_id], 1, sizeof(cl_mem), &cl->output_cl_mem[ker_id]);
	
	clEnqueueNDRangeKernel(cl->cmd_queue, cl->kernel[ker_id], 1, NULL, &cl->gws[ker_id], NULL, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
	
	clEnqueueReadBuffer(cl->cmd_queue, cl->output_cl_mem[ker_id], CL_TRUE, 0, cl->gws[ker_id] * sizeof(float), output, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
}

void	release_cl(t_cl *cl)
{
	clReleaseCommandQueue(cl->cmd_queue);
	clReleaseContext(cl->context);
}
