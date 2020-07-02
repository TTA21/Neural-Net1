#ifndef INPUT_LAYER_H
#define INPUT_LAYER_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class INPUT_LAYER
{
public:
    INPUT_LAYER();

    vector<double> INPUTS;
    vector<double> WEIGHTS;
    double BIAS;

    vector<double> ZEDS;
    unsigned long NUM_OF_OUTPUTS;

    const double LEARNING_RATE = 0.001;
    //const double LEARNING_RATE = 0.001; ///BEST RESULTS

    unsigned short Arith = 0;   ///type of calculation done by this layer

    void RECIEVE_INPUTS( vector<double> LOAD );

    void MAKE_WEIGHTS( unsigned long NUM_OF_OUTPUTS );

    void MAKE_ZEDS();

    void BACKPROP( vector<double> PROD_DER );

    double DER_SIGMOID( double X , unsigned short Arith );

    void DEBUG();

};

#endif // INPUT_LAYER_H
