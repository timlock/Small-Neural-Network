//
// Created by tim-l on 03.08.2021.
//

#ifndef SMALL_NEURAL_NETWORK_NEURON_H
#define SMALL_NEURAL_NETWORK_NEURON_H


class Neuron {
    float value;
    float bias;
public:
    Neuron() = default;
    Neuron(float value, float bias);

};


#endif //SMALL_NEURAL_NETWORK_NEURON_H
