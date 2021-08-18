//
// Created by tim-l on 03.08.2021.
//

#include "Neuron.h"
#include "accessingData.h"
#include "iostream"
#include <cmath>
#include <random>

using namespace std;
#ifndef SMALL_NEURAL_NETWORK_NETWORK_H
#define SMALL_NEURAL_NETWORK_NETWORK_H


class Network {
    Neuron **output_neurons = nullptr;
    Neuron **input_neurons = nullptr;
    Neuron **hidden_neurons = nullptr;
    int img_pixels = 0;
    int h_rows = 0;
    int h_neurons = 0;
    int o_neurons = 0;
    float *weights_and_biases = nullptr;

public:
    Network(int img_pixels, int h_rows, int h_neurons, int o_neurons);
    void setup_weights();
    int calculate_value(int index, int curr_range, int pre_range);
};


#endif //SMALL_NEURAL_NETWORK_NETWORK_H
