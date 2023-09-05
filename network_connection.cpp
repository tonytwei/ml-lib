#include "network_connection.hpp"
#include "matrix.hpp"

network_connection::network_connection(vector<int> dimensions, float (*activation)(float), float (*Dactivation)(float))
	: weights({dimensions[1], dimensions[0]}), biases({dimensions[1], 1}), activation(activation), Dactivation(Dactivation){
}

network_connection::network_connection(vector<int> dimensions, float (*activation)(float), float (*Dactivation)(float), bool rand)
	: weights({dimensions[1], dimensions[0]}, rand), biases({dimensions[1], 1}, rand), activation(activation), Dactivation(Dactivation){
}

network_connection::~network_connection() {
}

void network_connection::forward_inplace(matrix &input) {
	prev_a.copy(input);
	weights.mult_inplace(input);
	biases.add_inplace(input);
	z.copy(input);
	activate_inplace(input);
	a.copy(input);
}
/*
matrix* network_connection::forward_inplace(matrix &input) {
	input = weights.mult(input);
	input.add(biases);
	input = activate(input);
	return &input;
}
*/

matrix network_connection::activate(matrix &input) {
	matrix res = matrix(input.dimensions);
	for (int i = 0; i < input.size; i++) {
		res.matrix_body[i] = activation(input.matrix_body[i]);
	}
	return res;
}

matrix network_connection::Dactivate(matrix &input) {
	matrix res = matrix(input.dimensions);
	for (int i = 0; i < input.size; i++) {
		res.matrix_body[i] = Dactivation(input.matrix_body[i]);
	}
	return res;
}

void network_connection::activate_inplace(matrix &input) {
	for (int i = 0; i < input.size; i++) {
		input.matrix_body[i] = activation(input.matrix_body[i]);
	}
}

void network_connection::backprop_inplace(matrix &dc_da, float learn_rate) {
	//TODO: change dc_da inplace after function is done
	
	matrix weights_copy;
	weights_copy.copy(weights);
	
	matrix dc_dz = Dactivate(z); // returns da_dz
	dc_dz.hammard_product_inplace(dc_da);

	// adjust weights
	// dz_dw = prev_a
	prev_a.transpose_inplace(); // we don't transpose back, replaced next forward pass
	matrix dc_dw = dc_dz.mult(prev_a);
	dc_dw.scalar_mult_inplace(learn_rate);
	dc_dw.sub_inplace(weights);

	// adjust biases
	matrix dc_db;
	dc_db.copy(dc_dz); // dz_db = 1
	dc_db.scalar_mult_inplace(learn_rate);
	dc_db.sub_inplace(biases);

	// calc dc_da for next layer
	weights_copy.transpose_inplace();
	dc_da = weights_copy.mult(dc_dz);
	// weights: {wj, wk}
	// dc_dz: {wj, 1}
	// dc_da_next: {wk, 1}
	
	dc_da.print_shape();
}