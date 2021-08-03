//
// Created by tim-l on 03.08.2021.
//

#include "Neuron.h"
#include <cmath>
#include <random>
#ifndef SMALL_NEURAL_NETWORK_NETWORK_H
#define SMALL_NEURAL_NETWORK_NETWORK_H


class Network {
    Neuron **output_neurons = nullptr;
    Neuron **input_neurons = nullptr;
    Neuron **hidden_neurons = nullptr;
    float *weights = nullptr;

public:
    Network(int pixels,int h_rows,int h_neurons,int o_neurons);

};


#endif //SMALL_NEURAL_NETWORK_NETWORK_H
