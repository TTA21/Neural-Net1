#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class HIDDEN_LAYER
{
public:
    HIDDEN_LAYER();

    vector<double> INPUTS;
    vector<double> WEIGHTS;
    double BIAS;

    vector<double> ZEDS;
    vector<double> PREDS;
    vector<double> PROD_DER;
    unsigned long NUM_OF_OUTPUTS;

    unsigned short Arith = 0;   ///type of calculation done by this layer

    const double LEARNING_RATE = 0.001;

    void RECIEVE_INPUTS( vector<double> LOAD );

    void MAKE_WEIGHTS( unsigned long NUM_OF_OUTPUTS , unsigned long NUM_OF_INP );

    void MAKE_ZEDS();

    double SIGMOID( double X , unsigned short Arith );

    void MAKE_PREDS();

    void BACKPROP( vector<double> PROD_DER );

    double DER_SIGMOID( double X , unsigned short Arith );

    void DEBUG();


};

#endif // HIDDEN_LAYER_H
