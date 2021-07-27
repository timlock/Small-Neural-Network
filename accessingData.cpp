//
// Created by tim-l on 27.07.2021.
//

#include "accessingData.h"



extern const int height = 28;
extern const int width = 28;
extern const int n = 60000;
extern ifstream image;
extern ifstream label;
extern char list[n][width][height];

extern const string mnist_img = "resources/train-images.idx3-ubyte";
extern const string mnist_lab = "resources/train-labels.idx1-ubyte";

void firstRead(){
    image.open(mnist_img,ios::in | ios::binary );
    label.open(mnist_lab,ios::in | ios::binary );

    char *number;
    for (int i = 1; i <= 16; ++i) {
        image.read(number, sizeof(4));
        cout << number << endl;
    }

    for (int i = 1; i <= 8; ++i) {
        label.read(number, sizeof(4));
        cout << number << endl;
    }
}
void readData(){
    int d[width + 1][height + 1];
    char number;
    int index = 0;
    for(int l = 0; l < 10; l++){
    for (int j = 1; j <= height; ++j) {
        for (int i = 1; i <= width; ++i) {
            image.read(&number, sizeof(char));
            if (number == 0) {
                list[index][i][j] = 0;
            } else {
                list[index][i][j]  = 1;
            }
        }
    }

    cout << "Image:" << endl;
    for (int j = 1; j <= height; ++j) {
        for (int i = 1; i <= width; ++i) {
            cout << list[index][i][j];
        }
        cout << endl;
    }
    label.read(&number, sizeof(char));
    list[index][index + 1][0] = number;
    for(int i = 1; i< 10 ; i++){
        label.read(&number, sizeof(char));
        list[index][i + 1][0] = number;
    }
    cout << "Label: " << (int)(number) << endl;

    }


}