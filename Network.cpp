//
// Created by tim-l on 03.08.2021.
//

#include "Network.h"

extern float *data;

Network::Network(int img_pixels, int h_rows, int h_neurons, int o_neurons) : img_pixels(img_pixels), h_rows(h_rows),
                                                                             h_neurons(h_neurons),
                                                                             o_neurons(o_neurons) {
    input_neurons = new Neuron *[img_pixels];
    hidden_neurons = new Neuron *[h_neurons * h_rows];
    output_neurons = new Neuron *[o_neurons];
    int amount_of_weights = img_pixels * h_neurons + ((int) pow(h_neurons, h_rows)) + h_neurons * o_neurons;
    int amount_of_biases = h_rows * h_neurons + o_neurons;
    weights_and_biases = new float[amount_of_weights + amount_of_biases];
    std::mt19937 rand;
    std::uniform_real_distribution<float> distr_weights(-10.0f, 10.0f);//generates random values for the weights_and_biases
    std::uniform_real_distribution<float> distr_biases(0.0f, 30.0f);//generates random values for the biases
    for (int i = 0; i < img_pixels; i++) {
        input_neurons[i] = new Neuron();
    }
    for (int i = 0; i < amount_of_weights; i++) { // Initialize weights and biases with random values
        weights_and_biases[i] = distr_weights(rand);
    }
    for (int i = 0; i < h_neurons * h_rows; i++) {
        weights_and_biases[amount_of_weights + i] = distr_biases(rand);
        hidden_neurons[i] = new Neuron(&weights_and_biases[amount_of_weights + i]);
    }
    for (int i = 0; i < o_neurons; i++) {
        weights_and_biases[amount_of_weights + h_neurons * h_rows + i] = distr_biases(rand);
        output_neurons[i] = new Neuron(&weights_and_biases[amount_of_weights + h_neurons * h_rows + i]);
    }
}

/*
 *  calculates and sets the values for the input and hidden neurons
 */
void Network::setup_weights() {
    for (int i = 0; i < img_pixels; i++) { // sets the value according to the pixel value from the MNIST image
        input_neurons[i]->value = data[i];
    }
    int index = 0;
    index = calculate_value(index, h_neurons, img_pixels); // calculates the values for the neurons in the first hidden row
    for (int i = 0; i < h_rows; ++i) { // calculates the values for the neurons in the left hidden rows
        index += calculate_value(index, h_neurons, h_neurons);
    }
    calculate_value(index, o_neurons, h_neurons); // calculates the values for the neurons in the output row
}
/*
 *  calculates the value of each neuron according to the neurons from the previous row, connected weights_and_biases and the bias
 *  and returns the index for the weights_and_biases and biases array
 */
/// @param index index of for the array of weights_and_biases and biases
/// @param curr_range amount of neurons that share the row with the current neuron
/// @param pre_range amount of neurons in the previos row


int Network::calculate_value(int index, int curr_range, int pre_range){
    for (int i = 0; i < curr_range; i++) {
        float value = 0.0f;
        for (int j = 0; j < pre_range; j++) { // multiplies each weight with the according neuron from the previous row
            value += weights_and_biases[index + i * pre_range + j] * input_neurons[j]->value;
        }
        hidden_neurons[i]->value = sigmoid(value - *hidden_neurons[i]->bias);
    }
    return curr_range * pre_range;
}