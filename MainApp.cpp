//
// Created by tim-l on 27.07.2021.
//
#include <iostream>
#include <string>
#include "accessingData.h"
#include "Network.h"
using namespace std;


const string mnist_img = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-images.idx3-ubyte";
const string mnist_lab = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-labels.idx1-ubyte";
int height;
int width;
int number_of_pictures;
ifstream image;
ifstream label;
float  *data;


int main(){
    readingMetaData();
    Network *network = new Network(height* width,2,16,10);
    for(int i = 0;i < 1; i++){
        readData();
        network->setup_weights();
        //cost function
        //backpropagation
    }


    return 0;
}