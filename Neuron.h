//
// Created by tim-l on 03.08.2021.
//

using namespace std;
#ifndef SMALL_NEURAL_NETWORK_NEURON_H
#define SMALL_NEURAL_NETWORK_NEURON_H


class Neuron {
    float value = 0.0f;
    float bias = 0.0f;
    int index = 0;
    int pixels = 0;
    int h_rows = 0;
    int h_neurons = 0;
    int o_neurons = 0;
    float *weights;
public:
    Neuron() = default;
    Neuron(int pixels,int h_rows,int h_neurons,int o_neurons, float value);
    Neuron(int pixels,int h_rows,int h_neurons,int o_neurons, int index, float bias, float *weights);
    float generate_value();

};


#endif //SMALL_NEURAL_NETWORK_NEURON_H
