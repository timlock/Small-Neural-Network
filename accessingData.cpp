//
// Created by tim-l on 27.07.2021.
//

#include "accessingData.h"


extern const string mnist_img = "ressources/train-images.idx3-ubyte";
extern const string mnist_lab = "ressources/train-labels.idx1-ubyte";
extern const int height = 28;
extern const int width = 28;
extern int d[width + 1][height + 1];
extern ifstream image;
extern ifstream label;

bool firstRead(){
    image.open(mnist_img,ios::in | ios::binary );
    label.open(mnist_lab,ios::in | ios::binary );

    char number;
    for (int i = 1; i <= 16; ++i) {
        image.read(&number, sizeof(char));
        cout << number << endl;
    }

    for (int i = 1; i <= 8; ++i) {
        label.read(&number, sizeof(char));
        cout << number << endl;
    }
    return true;
}
void readData(){
    char number;
    for (int j = 1; j <= height; ++j) {
        for (int i = 1; i <= width; ++i) {
            image.read(&number, sizeof(char));
            if (number == 0) {
                d[i][j] = 0;
            } else {
                d[i][j] = 1;
            }
        }
    }

    cout << "Image:" << endl;
    for (int j = 1; j <= height; ++j) {
        for (int i = 1; i <= width; ++i) {
            cout << d[i][j];
        }
        cout << endl;
    }




}