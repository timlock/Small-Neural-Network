//
// Created by tim-l on 03.08.2021.
//

#include "Network.h"

extern float *data;

Network::Network(int pixels,int h_rows,int h_neurons,int o_neurons){
    input_neurons = new Neuron*[pixels];
    hidden_neurons = new Neuron*[h_neurons * h_rows];
    output_neurons = new Neuron*[o_neurons];
    int amount_of_weights = pixels * h_neurons + ((int) pow(h_neurons,h_rows)) + h_neurons * o_neurons;
    weights = new float[amount_of_weights];
    std::mt19937 rand;
    std::uniform_real_distribution<float> distr_weights(-10.0f, 10.0f);//generates random values for the weights
    std::uniform_real_distribution<float> distr_biases(0.0f, 30.0f);//generates random values for the biases
    for (int i = 0; i < pixels; i++) {
        input_neurons[i] = new Neuron(pixels,h_rows,h_neurons,o_neurons, data[i]);
    }
    for(int i = 0; i < amount_of_weights; i++){
        weights[i] = distr_weights(rand);
    }
    for(int i = 0; i < h_neurons; i++){
        hidden_neurons[i] = new Neuron(pixels,h_rows,h_neurons,o_neurons, i, distr_biases(rand), weights);
    }



}