//
// Created by tim-l on 03.08.2021.
//

#include "Network.h"

Network::Network(int pixels,int h_rows,int h_neurons,int o_neurons){
    input_neurons = new Neuron*[pixels];
    hidden_neurons = new Neuron*[h_neurons * h_rows];
    output_neurons = new Neuron*[o_neurons];
    weights = new float[pixels * h_neurons + powf(h_neurons,h_rows) + h_neurons * o_neurons];
    std::mt19937 rand;
    std::uniform_real_distribution<float> distributionV(0.0f,1.0f);
    std::uniform_real_distribution<float> distributionB(0.0f,30.0f);
    for (int i = 0; i < pixels; i++) {
        input_neurons[i] = new Neuron(distributionV(rand),distributionB(rand));
    }
    for(int i = 0; i < h_neurons; i++){

    }



}