kernel void		thread(global float *input, global float *output) {
	int		i;
	
	i = get_global_id(0);
	output[i] = input[i] * input[i];
}
