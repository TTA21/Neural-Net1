#ifndef SAMPLES_H
#define SAMPLES_H


#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct SAMPLES
{
    SAMPLES();

    /*double FlowerValues[8][3] = { 3.0, 1.5 , 1.0 ,	///Lenght IN , Width IN , color OUT
                                 2.0 , 1.0 , 0.0 ,
                                 4.0 , 1.5 , 1.0 ,
                                 3.0 , 1.0 , 0.0 ,
                                 3.5 , 0.5 , 1.0 ,
                                 2.0 , 0.5 , 0.0 ,
                                 5.5 , 1.0 , 1.0 ,
                                 1.0 , 1.0 , 0.0 };

    double MisteryFlower[2] = { 4.5 , 1.0 };///Gotta find the answer , should be 1

    const int NUM_OF_LINES = 8 ;
    const int NUM_OF_COLUMS = 3 ;

    unsigned int ChosenLine;*/

    vector<vector<double>> TRAINING_INPUTS;     ///{3.0 , 1.5}
    vector<vector<double>> TRAINING_OUTPUTS;    ///{1.0}

    vector<vector<double>> TESTING_INPUTS;      ///{3.0 , 1.5}
    vector<vector<double>> TESTING_OUTPUTS;     ///{1.0}

    unsigned long How_many_choices; ///Gives how many lines there are


    unsigned long ChosenLine;


            void Setup_Samples( vector<vector<double>> LOAD_IN , vector<vector<double>> LOAD_OUT ){

                TRAINING_INPUTS = LOAD_IN;
                TRAINING_OUTPUTS = LOAD_OUT;

                How_many_choices = LOAD_IN.size();

            }


            unsigned long CHOOSE_LINE(){     ///Seems to work

                ChosenLine = rand() % How_many_choices;
                return ChosenLine;

            }


};

#endif // SAMPLES_H
