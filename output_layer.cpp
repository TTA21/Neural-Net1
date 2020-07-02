#include "output_layer.h"

OUTPUT_LAYER::OUTPUT_LAYER()
{

}

void OUTPUT_LAYER::RECIEVE_INPUTS(vector<double> LOAD){

    this->ZEDS = LOAD;

}


double OUTPUT_LAYER::SIGMOID( double X , unsigned short Arith = 0 ){

    if( Arith == 0 ){   ///SIGMOID

        X = 1/( 1 + exp( -X ) );

        if( isinf(X) ) return 1;
        else return X;

    }else if ( Arith == 1 ){    ///TANH

        return tanh(X);

    }else{      ///ReLu

        if( X < 0 ){
            return 0;
        }else{
            return X;
        }

    }


}

double OUTPUT_LAYER::DER_SIGMOID( double X , unsigned short Arith = 0 ){


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


void OUTPUT_LAYER::FIND_COST(vector<double> TARGETS){

    PREDS.clear();
    DIFF.clear();

    for( size_t I = 0 ; I < ZEDS.size() ; I++ ){

        PREDS.push_back( SIGMOID( ZEDS[I] , Arith ) );

        //cout<<"PRED = " << " SIGMOID(" << ZEDS[I] << ")" << endl;

        DIFF.push_back( PREDS[I] - TARGETS[I] );

        //cout<<"DIFF = " << PREDS[I] << " - " << TARGETS[I] << endl;

    }


    this->Total_Cost = 0;

    for( size_t I = 0 ; I < DIFF.size() ; I++ ){

        this->Total_Cost += ( pow( DIFF[I] , 2 ) );

    }

    this->Total_Cost /= DIFF.size();

}


void OUTPUT_LAYER::MAKE_DER(){

    this->PROD_DER.clear();

    for( size_t I = 0 ; I < DIFF.size() ; I++ ){

        this->PROD_DER.push_back( (2* DIFF[I]) * DER_SIGMOID( ZEDS[I] , Arith ) );

    }

    double TEMP_DIFF = 1;

    for( size_t I = 0 ; I < DIFF.size() ; I++ ){

        TEMP_DIFF *= (2*DIFF[I]) * DER_SIGMOID( ZEDS[I] , Arith ) ;

    }

    this->PROD_DER.push_back( TEMP_DIFF );



}


void OUTPUT_LAYER::DEBUG(){

    cout<<"\n\n\n\nOUTPUT LAYER :"<<endl;

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"ZEDS SIZE : " << ZEDS.size() << endl;
    for( size_t I = 0 ; I < ZEDS.size() ; I++ ){
        cout<<"ZEDS[" << I << "] = " << ZEDS[I] << endl;
    }

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"PREDS SIZE : " << PREDS.size() << endl;
    for( size_t I = 0 ; I < PREDS.size() ; I++ ){
        cout<<"PREDS[" << I << "] = " << PREDS[I] << endl;
    }

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"DIFFS SIZE : " << DIFF.size() << endl;
    for( size_t I = 0 ; I < DIFF.size() ; I++ ){
        cout<<"DIFF[" << I << "] = " << DIFF[I] << endl;
    }

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"TOTAL COST = " << this->Total_Cost << endl;

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"PROD_DER SIZE : " << PROD_DER.size() << endl;
    for( size_t I = 0 ; I < PROD_DER.size() ; I++ ){
        cout<<"PROD_DER[" << I << "] = " << PROD_DER[I] << endl;
    }

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

}
