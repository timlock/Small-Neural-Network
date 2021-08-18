//
// Created by tim-l on 03.08.2021.
//

using namespace std;
#ifndef SMALL_NEURAL_NETWORK_NEURON_H
#define SMALL_NEURAL_NETWORK_NEURON_H


class Neuron {
public:
    float value = 0.0f;
    float *bias = nullptr;
    Neuron() = default;
    Neuron(float *bias);
};


#endif //SMALL_NEURAL_NETWORK_NEURON_H
