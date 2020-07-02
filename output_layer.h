#ifndef OUTPUT_LAYER_H
#define OUTPUT_LAYER_H

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class OUTPUT_LAYER
{
public:
    OUTPUT_LAYER();

    vector<double> ZEDS;
    vector<double> PREDS;
    vector<double> DIFF;

    double Total_Cost = 0;

    unsigned short Arith = 0;   ///type of calculation done by this layer

    vector<double> PROD_DER;

    void RECIEVE_INPUTS( vector<double> LOAD );

    void FIND_COST( vector<double> TARGETS );

    void MAKE_DER();

    void DEBUG();





    double SIGMOID( double X , unsigned short Arith );
    double DER_SIGMOID( double X , unsigned short Arith );

};

#endif // OUTPUT_LAYER_H
