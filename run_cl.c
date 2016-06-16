#include "cl.h"

char	*load_program_source()
{
	int		fd;
	char	*line;
	char	*source;

	fd = open("./kernel.cl", O_RDONLY);
	source = (char *)malloc(sizeof(char) * 4096);
	source[0] = '\0';
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

void	init_cl(t_cl *cl)
{
	char 				*source;
	cl_program			program;
	cl_device_id		device;
	cl_char				vendor_name[1024];
	cl_char				device_name[1024];


	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	
	clGetDeviceInfo(device, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, NULL);
	clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(device_name), device_name, NULL);
	printf("connecting to %s, %s...\n", vendor_name, device_name);
	
	cl->context = clCreateContext(0, 1, &device, NULL, NULL, NULL);
	cl->cmd_queue = clCreateCommandQueue(cl->context, device, 0, NULL);
	
	source = load_program_source();
	program = clCreateProgramWithSource(cl->context, 1, (const char **)&source, NULL, NULL);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	cl->kernel = clCreateKernel(program, "square", NULL);;
}

void	run_cl(int *input, int *output, int n, t_cl *cl)
{	
	cl->gws = n;
	cl->input_cl_mem = clCreateBuffer(cl->context, CL_MEM_READ_ONLY, cl->gws * sizeof(int), NULL, NULL);
	clEnqueueWriteBuffer(cl->cmd_queue, cl->input_cl_mem, CL_TRUE, 0, cl->gws * sizeof(int), (void *)input, 0, NULL, NULL);
	
	cl->output_cl_mem = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, cl->gws * sizeof(int), NULL, NULL);
	clFinish(cl->cmd_queue);
	
	clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->input_cl_mem);
	clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->output_cl_mem);
	
	clEnqueueNDRangeKernel(cl->cmd_queue, cl->kernel, 1, NULL, &cl->gws, NULL, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
	
	clEnqueueReadBuffer(cl->cmd_queue, cl->output_cl_mem, CL_TRUE, 0, cl->gws * sizeof(int), output, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
}

void	release_cl(t_cl *cl)
{
	clReleaseCommandQueue(cl->cmd_queue);
	clReleaseContext(cl->context);
}
