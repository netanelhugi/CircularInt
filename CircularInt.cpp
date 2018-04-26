#include <iostream>
#include "CircularInt.hpp"

using namespace std;

//constructor
CircularInt::CircularInt(int low, int high){
    this->lowNum = low;
    this->highNum = high; 
    this->now = low;
    this->diff = high-low+1;
}

CircularInt::CircularInt(){
    highNum = 12;
    lowNum = 1;
    now = lowNum;
}

int CircularInt::getHigh(){
    return this->highNum;
}

int CircularInt::getLow(){
    return this->lowNum;
}

int CircularInt::getDiff(){
        return this->diff;
    }

int CircularInt::getNow() const{
    return this->now;
}

void CircularInt::setNow(int n){

    this->now = this->getRealVal(n);

}

//function to determine the appropriate value
//if "val" between "lowNum" and "highNum", the function return him.
//else, the function adds/subtracts the difference to/from the value
//until we reach the appropriate value

int CircularInt::getRealVal(int val){

    if(val>highNum){
        return getRealVal(val-diff);
    }
    else if(val<lowNum){
        return getRealVal(val+diff);
    }
    else{
        return val;
    }

}

