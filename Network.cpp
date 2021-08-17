//
// Created by tim-l on 03.08.2021.
//

#include "Network.h"

extern float *data;

Network::Network(int img_pixels, int h_rows, int h_neurons, int o_neurons) : pixels(img_pixels), h_rows(h_rows), h_neurons(h_neurons), o_neurons(o_neurons){
    input_neurons = new Neuron*[img_pixels];
    hidden_neurons = new Neuron*[h_neurons * h_rows];
    output_neurons = new Neuron*[o_neurons];
    int amount_of_weights = img_pixels * h_neurons + ((int) pow(h_neurons, h_rows)) + h_neurons * o_neurons;
    weights = new float[amount_of_weights];
    std::mt19937 rand;
    std::uniform_real_distribution<float> distr_weights(-10.0f, 10.0f);//generates random values for the weights
    std::uniform_real_distribution<float> distr_biases(0.0f, 30.0f);//generates random values for the biases
    for (int i = 0; i < img_pixels; i++) {
        input_neurons[i] = new Neuron();
    }
    for(int i = 0; i < amount_of_weights; i++){
        weights[i] = distr_weights(rand);
    }
    for(int i = 0; i < h_neurons * h_rows; i++){
        hidden_neurons[i] = new Neuron(distr_biases(rand));
    }
    for(int i = 0; i < o_neurons; i++){
        output_neurons[i] = new Neuron();
    }
}

/*
 *  calculates and sets the values for the input and hidden neurons
 */
float Network::setup_weights(){
    for(int i = 0; i < pixels; i++){ // sets the value according to the pixel value from the MNIST image
        input_neurons[i]->value = data[i];
    }
    for(int i = 0; i < h_rows * h_neurons; i++){ // calculates the value of each hidden neuron according to the neurons from the previous row, connected weights and the bias
        int range = 0;
        float value = 0.0f;
        if(h_neurons <= i) range = h_neurons; // determines if the current neuron is in the first hidden row
        else range = pixels;
        for(int j = 0; j < range; j++){ // multiplies each weight with the according neuron from the previous row
            if(range == pixels) value += weights[i * range + j] * input_neurons[j]->value; // first row
            else value += weights[i * range + j] * hidden_neurons[j]->value; // second row
        }
        hidden_neurons[i]->value = sigmoid(value - hidden_neurons[i]->bias);
    }
    return 0;
}