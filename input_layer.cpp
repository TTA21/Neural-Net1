#include "input_layer.h"

INPUT_LAYER::INPUT_LAYER(){

}

void INPUT_LAYER::RECIEVE_INPUTS(vector<double> LOAD){

    this->INPUTS = LOAD;    ///This is where you load your training samples , only the inputs

}

void INPUT_LAYER::MAKE_WEIGHTS(unsigned long NUM_OF_OUTPUTS){

    ///The number of indexes in the input vector is the number of inputs in this layer
    /// Remember that this layer has to support the one in front of it, so tell how many neurons it has to output to

    for( size_t I = 0 ; I < INPUTS.size() * NUM_OF_OUTPUTS ; I++ ){
        this->WEIGHTS.push_back( rand() / double(RAND_MAX) );
    }

    this->BIAS = rand() / double(RAND_MAX);

    this->NUM_OF_OUTPUTS = NUM_OF_OUTPUTS;

    //this->WEIGHTS.push_back( 0.447377 );
    //this->WEIGHTS.push_back( 0.640638 );

    //BIAS = 0.829377;


}

void INPUT_LAYER::MAKE_ZEDS(){

    ZEDS.clear();   ///Zeds are calculated on the fly, they will be different every time, so they are cleared

    double TEMP_ZED = 0;    ///Holds the value of zed temporarely
    unsigned long Weight_Index = 0; ///Tunrs a matrix into a linear array

    for( size_t I = 0 ; I < NUM_OF_OUTPUTS ; I++ ){
        for( size_t J = 0 ; J < INPUTS.size() ; J++ ){

            TEMP_ZED += INPUTS[J] * WEIGHTS[Weight_Index];  ///VALUE * WHEIGHT + VALUE * WHEIGHT ...
            //cout<< INPUTS[J] << " * " << WEIGHTS[Weight_Index] << " + ";
            Weight_Index++;
        }
        //cout<< BIAS ;
        //cout<< " = " << TEMP_ZED + BIAS << endl;
        this->ZEDS.push_back( TEMP_ZED + BIAS );    ///VALUE * WHEIGHT + BIAS

        TEMP_ZED = 0;   ///In case there are many outputs , the value is reset to be calculated again

    }

}

double INPUT_LAYER::DER_SIGMOID( double X , unsigned short Arith = 0 ){


    if( Arith == 0 ){   ///SIGMOID

        X = exp(X) / pow((exp(X) + 1), 2);

        if ( isinf(X) ) return 1;
        else return X;

    }else if ( Arith == 1 ){    ///TANH

        return 1-(tanh(X) * tanh(X));

    }else{  ///ReLu

        if( X < 0 ) return 0;
        else return 1;

    }

}

void INPUT_LAYER::BACKPROP(vector<double> PROD_DER){

    ///The input layer is responsible for one thing only, Deliver ZED to the next layer, the next layer will sigmoid it and derive it accordingly

    {
        unsigned long Weight_Index = 0;

        for( size_t I = 0 ; I < ZEDS.size() ; I++ ){
            for( size_t J = 0 ; J < INPUTS.size() ; J++ ){

                this->WEIGHTS[Weight_Index] -= LEARNING_RATE * ( PROD_DER[I] * INPUTS[J] );

                Weight_Index++;

            }
        }
    }

    BIAS -= LEARNING_RATE * PROD_DER.front();


}

void INPUT_LAYER::DEBUG(){

    cout<<"\n\n\nINPUT LAYER:"<<endl;

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"NUMBER OF INPUTS : " << INPUTS.size() << endl;
    for( size_t I = 0 ; I < INPUTS.size() ; I++){
        cout<<"INPUT[" << I << "] = " << INPUTS[I] << endl;
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"NUMBER OF WEIGHTS : " << WEIGHTS.size() << endl;
    for( size_t I = 0 ; I < WEIGHTS.size() ; I++){
        cout<<"WEIGHT[" << I << "] = " << WEIGHTS[I] << endl;
    }

    cout<<"BIAS = " << BIAS << endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"NUMBER OF ZEDS : " << ZEDS.size() << endl;
    for( size_t I = 0 ; I < ZEDS.size() ; I++){
        cout<<"ZEDS[" << I << "] = " << ZEDS[I] << endl;
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

}
