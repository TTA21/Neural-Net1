#include <iostream>
#include <time.h>

#include "REDE_NEURAL/INPUT_LAYER/input_layer.h"
#include "REDE_NEURAL/HIDDEN_LAYER/hidden_layer.h"
#include "REDE_NEURAL/OUTPUT_LAYER/output_layer.h"

#include "REDE_NEURAL/Samples/samples.h"

using namespace std;

int main()
{


    ///////////////////////////////////////////////////////////////////////////////////////////
    srand(time(nullptr));

    SAMPLES Sample;
        {
        /*vector<vector<double>> INS = {  {3.0 , 1.5},  ///FLOWER
                                        {2.0 , 1.0},
                                        {4.0 , 1.5},
                                        {3.0 , 1.0},
                                        {3.5 , 0.5},
                                        {2.0 , 0.5},
                                        {5.5 , 1.0},
                                        {1.0 , 1.0}
                                 };

        vector<vector<double>>OUTS = {  {1.0},
                                        {0.0},
                                        {1.0},
                                        {0.0},
                                        {1.0},
                                        {0.0},
                                        {1.0},
                                        {0.0}
        };*/

        /*vector<vector<double>> INS = {          { 0.0 , 0.0 },//NAND
                                                { 0.0 , 1.0 },
                                                { 1.0 , 0.1 },
                                                { 1.0 , 1.0 }
                                      };
        vector<vector<double>>OUTS = {  {1.0},
                                        {1.0},
                                        {1.0},
                                        {0.0}


        };*/
                                     //0   1   2   3   4   5   6   7   8   9   10  11
        vector<vector<double>> INS = {{1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 }, //Anything onto aluminum
                                      {0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 }, //Anything onto chromium
                                      {0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 }, //Anything onto copper
                                      {0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 }, //Anything onto iron
                                      {0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 }, //Anything onto Magnesium
                                      {0 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 },
                                      {0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
                                      {0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 },
                                      {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }};
                                     //0   1   2   3   4   5   6   7   8   9   10  11
        vector<vector<double>>OUTS = {{1},
                                      {0},
                                      {0},
                                      {0},
                                      {0},
                                      {0}, //Anything onto aluminum
                                      {0},
                                      {1},
                                      {0},
                                      {0},
                                      {0},
                                      {0}, //Anything onto chromium
                                      {1},
                                      {1},
                                      {1},
                                      {1},
                                      {0},
                                      {1}, //Anything onto copper
                                      {1},
                                      {1},
                                      {1},
                                      {1},
                                      {1},
                                      {1}, //Anything onto iron
                                      {0},
                                      {0},
                                      {0},
                                      {0},
                                      {1},
                                      {0}, //Anything onto Magnesium
                                      {0},
                                      {0},
                                      {0},
                                      {0},
                                      {0},
                                      {1},
                                      {0}};

        Sample.Setup_Samples( INS , OUTS );   ///Takes the vectors above and stores them
        }
    ///////////////////////////////////////////////////////////////////////////////////////////

    Sample.CHOOSE_LINE();

        INPUT_LAYER INPUT1;

            HIDDEN_LAYER HIDDEN1;

        OUTPUT_LAYER OUTPUT1;

        INPUT1.Arith = 2;   ///Relu on Input 1
        HIDDEN1.Arith = 2;  ///Relu on Hidden 1
        OUTPUT1.Arith = 0;  ///Sigmoid on Output 1


            Sample.CHOOSE_LINE();   ///RANDOM LINE FOR THE FIRST TIME
            INPUT1.RECIEVE_INPUTS( Sample.TRAINING_INPUTS[ Sample.ChosenLine ] );   ///INPUT RECIEVES VALUES FROM SAMPLES CLASS

            INPUT1.MAKE_WEIGHTS( 4 );   ///INPUT RECIEVES RANDOM WEIGHS , 4 OUTPUTS

            HIDDEN1.MAKE_WEIGHTS( 1 , 4 );  ///HIDDEN RECIEVES RANDOM WEIGHTS , 1 OUTPUTS , 3 INPUTS

            for( size_t I = 0 ; I < 5000000 ; I++ ){

                INPUT1.RECIEVE_INPUTS( Sample.TRAINING_INPUTS[ Sample.ChosenLine ] );   ///INPUT LAYER RECIEVES RANDOM SET OF INITIAL VALUES

                INPUT1.MAKE_ZEDS();     ///BASED ON ITS WHEIGHTS , MAKES A NON SIGMOIDED PREDICTION

                //cout<<"\n\nINPUT1:"<<endl;

                //INPUT1.DEBUG();

                //OUTPUT_FROM_INPUT1 = INPUT1.ZEDS;   ///FEED TO HIDDEN INPUT

                HIDDEN1.RECIEVE_INPUTS( INPUT1.ZEDS );   ///HIDDEN LAYER tHE RECIEVES THESE PREDICTIONS

                HIDDEN1.MAKE_PREDS();       ///SIGMOID THE INPUTS SO THEY CAN BE USED

                HIDDEN1.MAKE_ZEDS();        ///THEN MAKE THE ZEDS, WICH WILL BE FOWARDED TO THE NEXT LAYER

                //cout<<"\n\nHIDDEN1:"<<endl;

                //HIDDEN1.DEBUG();

                //OUTPUT_FROM_HIDDEN1 = HIDDEN1.ZEDS; ///FEED TO OUTPUT INPUT

                OUTPUT1.RECIEVE_INPUTS( HIDDEN1.ZEDS );  ///OUTPUT RECIEVES ZEDS FROM HIDDEN

                OUTPUT1.FIND_COST( Sample.TRAINING_OUTPUTS[ Sample.ChosenLine ] );  ///OUTPUT THEN CALCULATES THE PREDICTION , DIFFERENCE AND COST BASED ON RESPECTIVE OUTPUT

                OUTPUT1.MAKE_DER();     ///OUTPUT THEN MAKES THE DERIVATION PRODUCT

                //cout<<"\n\nOUTPUT1:"<<endl;

                //OUTPUT1.DEBUG();

                //OUTPUT_FROM_OUTPUT1 = OUTPUT1.PROD_DER; ///DREIVATIVE PRODUCT IS THEN PASSED BACK

                HIDDEN1.BACKPROP( OUTPUT1.PROD_DER );

                //PRODUCT_FROM_HIDDEN1 = HIDDEN1.PROD_DER;

                INPUT1.BACKPROP( HIDDEN1.PROD_DER );

                Sample.CHOOSE_LINE();   ///RANDOM LINE FOR THE FIRST TIME

                //cin.get();

            }

            vector<double> TEST;
            double TEMP_TEST;

            while(1){

                TEST.clear();

                for( size_t I = 0 ; I < INPUT1.INPUTS.size() ; I++ ){

                    cout<<"INPUT[" << I << "] : ";

                    cin>>TEMP_TEST;
                    TEST.push_back( TEMP_TEST );
                    cin.get();

                    cout<<"\n\n";

                }



                INPUT1.RECIEVE_INPUTS( TEST );

                INPUT1.MAKE_ZEDS();

                HIDDEN1.RECIEVE_INPUTS( INPUT1.ZEDS );

                HIDDEN1.MAKE_PREDS();

                HIDDEN1.MAKE_ZEDS();

                OUTPUT1.RECIEVE_INPUTS( HIDDEN1.ZEDS );

                OUTPUT1.FIND_COST( Sample.TRAINING_OUTPUTS[ Sample.ChosenLine ] );

                OUTPUT1.DEBUG();

                cin.get();

            }



    return 0;
}
