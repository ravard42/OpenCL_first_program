kernel void		square(global int *input, global int *output) {
	int		i;
	
	i = get_global_id(0);
	output[i] = input[i] * input[i];
}
