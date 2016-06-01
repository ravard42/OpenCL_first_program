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

void	run_cl(int *input, int *output, int n)
{
	char 				*source;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	cmd_queue;
	cl_context			context;
	cl_device_id		device;
	cl_mem				input_cl_mem;
	cl_mem				output_cl_mem;
	size_t				returned_size;
	size_t				global_work_size;

	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	
	returned_size = 0;
	cl_char	vendor_name[1024] = {0};
	cl_char device_name[1024] = {0};
	clGetDeviceInfo(device, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
	clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
	printf("connecting to %s, %s...\n", vendor_name, device_name);
	
	context = clCreateContext(0, 1, &device, NULL, NULL, NULL);
	cmd_queue = clCreateCommandQueue(context, device, 0, NULL);
	
	source = load_program_source();
	program = clCreateProgramWithSource(context, 1, (const char **)&source, NULL, NULL);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	kernel = clCreateKernel(program, "square", NULL);
	
	input_cl_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(int), NULL, NULL);
	clEnqueueWriteBuffer(cmd_queue, input_cl_mem, CL_TRUE, 0, n * sizeof(int), (void *)input, 0, NULL, NULL);
	
	output_cl_mem = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(int), NULL, NULL);
	clFinish(cmd_queue);
	
	clSetKernelArg(kernel, 0, sizeof(cl_mem), &input_cl_mem);
	clSetKernelArg(kernel, 1, sizeof(cl_mem), &output_cl_mem);
	
	global_work_size = n;
	clEnqueueNDRangeKernel(cmd_queue, kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL);
	clFinish(cmd_queue);
	
	clEnqueueReadBuffer(cmd_queue, output_cl_mem, CL_TRUE, 0, n * sizeof(int), output, 0, NULL, NULL);
	clFinish(cmd_queue);
	
	clReleaseCommandQueue(cmd_queue);
	clReleaseContext(context);
}
