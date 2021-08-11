//
// Created by tim-l on 03.08.2021.
//

#include "Neuron.h"
// constructor for input neurons
Neuron::Neuron(int pixels,int h_rows,int h_neurons,int o_neurons, float value)
:pixels(pixels), h_rows(h_rows), h_neurons(h_neurons),o_neurons(o_neurons ), value(value) {};
// constructor for hidden and output neurons
Neuron::Neuron(int pixels,int h_rows,int h_neurons,int o_neurons, int index, float bias, float *weights) :
pixels(pixels), h_rows(h_rows), h_neurons(h_neurons),o_neurons(o_neurons ),index(index), bias(bias), weights(weights){
//    generate_value(); // kann nicht im Konstruktor aufgerufen werden
}

/*
 * calculates the value based on all connected weights and neurons form the input layer
 */
float Neuron::generate_value(){
    float value = 0.0f;
    int limit = 0;
    if(h_rows / index >= 1) limit = h_neurons; // determines if the current neuron is in the first hidden row
    else limit = pixels;
    for(int i = 0; i < limit; i++){ // benötigt noch die output neuron liste und hidden neuron liste
//        value += i * limit
    }
    return 0;
}