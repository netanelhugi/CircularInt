#include <iostream>

using namespace std;

class CircularInt{

    //values to set the circular number
    int lowNum;
    int highNum;
    //the difference between the initialization values of the circular number
    int diff;
    int now;
    

    public:
    //constructors
    CircularInt(int low,int high);
    CircularInt(); 
    //function to determine the appropriate value
    int getRealVal(int val);
    //get the current value
    int getNow() const;
    //get the high value of CircularInt
    int getHigh();
    //get the low value of CircularInt
    int getLow();
    int getDiff();

    //-------------------------------------
    // operators
    //
    // every operators send value(according the  arithmetic operation)
    // to "getRealVal" function, get the appropriate value
    // and set the "now" variable to be this value.
    //-------------------------------------


    ////////////////////////////////
    //////Arithmetic operators//////
    ////////////////////////////////
    CircularInt& operator=(const int& other){//CIrcularInt=int
        this->now = getRealVal(other);

        return *this;
    }

    CircularInt& operator=(const CircularInt& other){//CircularInt=CircularInt
        this->now = getRealVal(other.now);

        return *this;
    }

    const CircularInt operator++(int){//i++

        CircularInt ci(this->lowNum,this->highNum);
        ci.now = this->now;
        ci.diff = this->diff;

        this->now = getRealVal(now+1);

        return ci;
    }

    CircularInt& operator++(){//++i
        this->now = getRealVal(now+1);
 
        return *this;
    }

    const CircularInt operator--(int){//i--

        CircularInt ci(this->lowNum,this->highNum);
        ci.now = this->now;
        ci.diff = this->diff;

        this->now = getRealVal(now-1);

        return ci;
    }

    CircularInt& operator--(){//--i
        this->now = getRealVal(now-1);
 
        return *this;
    }

    const int operator-()const{//-(i)
        return highNum-now;
    }

    friend CircularInt operator - (int a,const CircularInt &b);//(int a-CirInt b)#1
    friend CircularInt operator + (int a,const CircularInt &b);//(int a+CirInt b)#2
    friend CircularInt operator * (int a,const CircularInt &b);//(int a*CirInt b)#3
    friend CircularInt operator / (int a,const CircularInt &b);//(int a/CirInt b)#4

    friend CircularInt operator - (const CircularInt &b,int a);//(CirInt b-int a)#5
    friend CircularInt operator + (const CircularInt &b,int a);//(CirInt b+int a)#6
    friend CircularInt operator * (const CircularInt &b,int a);//(CirInt b*int a)#7
    friend CircularInt operator / (const CircularInt &b,int a);//(CirInt b/int a)#8

    //(CirInt a-CirInt b)#9
    friend CircularInt operator - (const CircularInt &a ,const CircularInt &b);
    //(CirInt a+CirInt b)#10
    friend CircularInt operator + (const CircularInt &a ,const CircularInt &b);
    //(CirInt a*CirInt b)#11
    friend CircularInt operator * (const CircularInt &a ,const CircularInt &b);
    //(CirInt a/CirInt b)#12
    friend CircularInt operator / (const CircularInt &a ,const CircularInt &b);

    //int%CirInt//#13
    friend CircularInt operator % (int a, const CircularInt &b);
    //CirInt%int//#14
    friend CircularInt operator % (const CircularInt &a,int b);
    //CirInt%CirInt//#15
    friend CircularInt operator % (const CircularInt &a, const CircularInt &b);



    ////////////////////////////////
    //////Comparison operators//////
    ////////////////////////////////

    bool operator==(int other){//CircularInt==int

        if(this->now==getRealVal(other)){
            return true;
        }

        return false;
    }

    bool operator==(const CircularInt& other){//CircularInt==CircularInt

        if(this->now==getRealVal(other.now)){
            return true;
        }

        return false;
    }
        
    friend bool operator == (int b,CircularInt a);//int==CircularInt


    bool operator!=(const int& other){//CircularInt!=int

        if(this->now==getRealVal(other)){
            return false;
        }

        return true;
    }

    bool operator!=(const CircularInt& other){//CircularInt!=CircularInt

        if(this->now==getRealVal(other.now)){
            return false;
        }

        return true;
    }

    friend bool operator != (int b,CircularInt a);//int!=CircularInt


    bool operator>(const int& other){//CircularInt>int

        if(this->now>getRealVal(other)){
            return true;
        }

        return false;
    }

    bool operator>(const CircularInt& other){//CircularInt>CircularInt

        if(this->now>getRealVal(other.now)){
            return true;
        }

        return false;
    }

    friend bool operator > (int b,CircularInt a);//int!=CircularInt


    bool operator>=(const int& other){//CircularInt>=int

        if(this->now>=getRealVal(other)){
            return true;
        }

        return false;
    }

    bool operator>=(const CircularInt& other){//CircularInt>=CircularInt

        if(this->now>=getRealVal(other.now)){
            return true;
        }

        return false;
    }

    friend bool operator >= (int b,CircularInt a);//int!=CircularInt


    bool operator<(const int& other){//CircularInt<int

        if(this->now<getRealVal(other)){
            return true;
        }

        return false;
    }

    bool operator<(const CircularInt& other){//CircularInt<CircularInt

        if(this->now<getRealVal(other.now)){
            return true;
        }

        return false;
    }

    friend bool operator < (int b,CircularInt a);//int!=CircularInt


    bool operator<=(const int& other){//CircularInt<=int

        if(this->now<=getRealVal(other)){
            return true;
        }

        return false;
    }

    bool operator<=(const CircularInt& other){//CircularInt<=CircularInt

        if(this->now<=getRealVal(other.now)){
            return true;
        }

        return false;
    }

    friend bool operator <= (int b,CircularInt a);//int!=CircularInt


    /////////////////////////////
    //////Logical operators//////
    /////////////////////////////

    CircularInt operator!(){//!CircularInt
        CircularInt ci(lowNum,highNum);
        ci.now = getRealVal(!now);

        return ci;
    }

    //CircularInt&&int//#1
    friend CircularInt operator && (const CircularInt &a,int b);
    //int&&CircularInt//#2
    friend CircularInt operator && (int b,const CircularInt &a);
    //CircularInt&&CircularInt//#3
    friend CircularInt operator && (const CircularInt &a,const CircularInt &b);

    //CircularInt||int//#4
    friend CircularInt operator || (const CircularInt &a,int b);
    //int||CircularInt//#5
    friend CircularInt operator || (int b,const CircularInt &a);
    //CircularInt||CircularInt//#6
    friend CircularInt operator || (const CircularInt &a,const CircularInt &b);

    /////////////////////////////
    //////Bitwise operators//////
    /////////////////////////////

    CircularInt operator~(){//~CircularInt
        CircularInt ci(lowNum,highNum);
        ci.now = getRealVal(~now);

        return ci;
    }
    
    //CircularInt&int//#1
    friend CircularInt operator & (const CircularInt &a,int b);
    //int&CircularInt//#2
    friend CircularInt operator & (int b,const CircularInt &a);
    //CircularInt&CircularInt//#3
    friend CircularInt operator & (const CircularInt &a,const CircularInt &b);

    //CircularInt|int//#4
    friend CircularInt operator | (const CircularInt &a,int b);
    //int|CircularInt//#5
    friend CircularInt operator | (int b,const CircularInt &a);
    //CircularInt|CircularInt//#6
    friend CircularInt operator | (const CircularInt &a,const CircularInt &b);

    //CircularInt^int//#7
    friend CircularInt operator ^ (const CircularInt &a,int b);
    //int^CircularInt//#8
    friend CircularInt operator ^ (int b,const CircularInt &a);
    //CircularInt^CircularInt//#9
    friend CircularInt operator ^ (const CircularInt &a,const CircularInt &b);

    //CircularInt<<int//#10
    friend CircularInt operator << (const CircularInt &a,int b);
    //int<<CircularInt//#11
    friend CircularInt operator << (int b,const CircularInt &a);
    //CircularInt<<CircularInt//#12
    friend CircularInt operator << (const CircularInt &a,const CircularInt &b);

    //CircularInt>>int//#13
    friend CircularInt operator >> (const CircularInt &a,int b);
    //int>>CircularInt//#14
    friend CircularInt operator >> (int b,const CircularInt &a);
    //CircularInt>>CircularInt//#15
    friend CircularInt operator >> (const CircularInt &a,const CircularInt &b);


    


    /////////////////////////////////////////
    //////Compound assignment operators//////
    /////////////////////////////////////////
    CircularInt& operator+=(const int& other){//CircularInt+=int
        this->now = getRealVal(now+other);

        return *this;
    }

    CircularInt& operator+=(const CircularInt& other){//CircularInt+=CircularInt
        this->now = getRealVal(now+other.now);

        return *this;
    }

    CircularInt& operator-=(const int& other){//CircularInt-=int
        this->now = getRealVal(now-other);

        return *this;
    }

    CircularInt& operator-=(const CircularInt& other){//CircularInt-=CircularInt
        this->now = getRealVal(now-other.now);

        return *this;
    }

    CircularInt& operator*=(const int& other){//CircularInt*=int
        this->now = getRealVal(now*other);

        return *this;
    }

    CircularInt& operator*=(const CircularInt& other){//CircularInt*=CircularInt
        this->now = getRealVal(now*other.now);

        return *this;
    }

    CircularInt& operator/=(const int& other){//CircularInt/=int

    if(now%other!=0){
        string s = "There is no number x in {" + to_string(lowNum)+","+to_string(highNum)+"}"
                    +" such that x*"+to_string(now)+"="+to_string(other);
        throw string(s);
    }

    this->now = getRealVal(now / other);

    return *this;
    }

    CircularInt& operator/=(const CircularInt& other){//CircularInt/=CircularInt

    if(now%other.now!=0){
        string s = "There is no number x in {" + to_string(lowNum)+","+to_string(highNum)+"}"
                    +" such that x*"+to_string(now)+"="+to_string(other.now);
        throw string(s);
    }

    this->now = getRealVal(now / other.now);

    return *this;
    }

    CircularInt& operator%=(const int& other){//CircularInt&=int
        this->now = getRealVal(now%other);

        return *this;
    }

    CircularInt& operator%=(const CircularInt& other){//CircularInt&=CircularInt
        this->now = getRealVal(now%other.now);

        return *this;
    }

    CircularInt& operator&=(const int& other){//CircularInt&=int
        this->now = getRealVal(now&other);

        return *this;
    }

    CircularInt& operator&=(const CircularInt& other){//CircularInt&=CircularInt
        this->now = getRealVal(now&other.now);

        return *this;
    }

    CircularInt& operator|=(const int& other){//CircularInt|=int
        this->now = getRealVal(now|other);

        return *this;
    }

    CircularInt& operator|=(const CircularInt& other){//CircularInt|=CircularInt
        this->now = getRealVal(now|other.now);

        return *this;
    }

    CircularInt& operator^=(const int& other){//CircularInt^=int
        this->now = getRealVal(now^other);

        return *this;
    }

    CircularInt& operator^=(const CircularInt& other){//CircularInt^=CircularInt
        this->now = getRealVal(now^other.now);

        return *this;
    }

    CircularInt& operator<<=(const int& other){//CircularInt<<=int
        this->now = getRealVal(now<<other);

        return *this;
    }

    CircularInt& operator<<=(const CircularInt& other){//CircularInt<<=CircularInt
        this->now = getRealVal(now<<other.now);

        return *this;
    }

    CircularInt& operator>>=(const int& other){//CircularInt>>=int
        this->now = getRealVal(now>>other);

        return *this;
    }

    CircularInt& operator>>=(const CircularInt& other){//CircularInt>>=CircularInt
        this->now = getRealVal(now>>other.now);

        return *this;
    }

};

////////////////////////////////////////
//////Friends Arithmetic operators//////
////////////////////////////////////////

inline CircularInt operator - (int a,const CircularInt &b) {//#1
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a - b.now);
    
    return ci;
}

inline CircularInt operator + (int a,const CircularInt &b) {//#2
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a + b.now);
    
    return ci;
}

inline CircularInt operator * (int a,const CircularInt &b) {//#3
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a * b.now);

    return ci;
}

inline CircularInt operator / (int a,const CircularInt &b) {//#4
    CircularInt ci{b.lowNum,b.highNum};

    if(a%b.now!=0){
        string s = "There is no number x in {" + to_string(b.lowNum)+","+to_string(b.highNum)+"}"
                    +" such that x*"+to_string(b.now)+"="+to_string(a);
        throw string(s);
    }

    ci.now = ci.getRealVal(a / b.now);

    return ci;
}



inline CircularInt operator - (const CircularInt &b,int a) {//#5
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(b.now-a);

    return ci;
}

inline CircularInt operator + (const CircularInt &b,int a) {//#6
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a + b.now);

    return ci;
}

inline CircularInt operator * (const CircularInt &b,int a) {//#7
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a * b.now);
 
    return ci;
}

inline CircularInt operator / (const CircularInt &b,int a) {//#8
    CircularInt ci{b.lowNum,b.highNum};

    if(b.now%a!=0){
        string s = "There is no number x in {" + to_string(b.lowNum)+","+to_string(b.highNum)+"}"
                    +" such that x*"+to_string(a)+"="+to_string(b.now);
        throw string(s);
    }

    ci.now = ci.getRealVal(b.now/a);
    
    return ci;
}

inline CircularInt operator - (const CircularInt &a,const CircularInt &b) {//#9
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now - b.now);
    
    return ci;
}

inline CircularInt operator + (const CircularInt &a,const CircularInt &b) {//#10
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now + b.now);
    
    return ci;
}

inline CircularInt operator * (const CircularInt &a,const CircularInt &b) {//#11
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now * b.now);

    return ci;
}

inline CircularInt operator / (const CircularInt &a,const CircularInt &b) {//#12
    CircularInt ci{a.lowNum,a.highNum};

    if(a.now%b.now!=0){
        string s = "There is no number x in {" + to_string(a.lowNum)+","+to_string(a.highNum)+"}"
                    +" such that x*"+to_string(b.now)+"="+to_string(a.now);
        throw string(s);
    }

    ci.now = ci.getRealVal(a.now / b.now);

    return ci;
}

inline CircularInt operator % (int a,const CircularInt &b) {//#13
    CircularInt ci{b.lowNum,b.highNum};
    ci.now = ci.getRealVal(a%b.now);

    return ci;
}

inline CircularInt operator % (const CircularInt &a,int b) {//#14
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now%b);

    return ci;
}

inline CircularInt operator % (const CircularInt &a,const CircularInt &b) {//#15
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now%b.now);

    return ci;
}



/////////////////////////////////////
//////Friends Logical operators//////
/////////////////////////////////////

inline CircularInt operator && (const CircularInt &a,int b) {//#1
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now&&b);
    
    return ci;
}

inline CircularInt operator && (int b,const CircularInt &a) {//#2
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b&&a.now);
    
    return ci;
}

inline CircularInt operator && (const CircularInt &a,const CircularInt &b) {//#3
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now&&b.now);
    
    return ci;
}

inline CircularInt operator || (const CircularInt &a,int b) {//#4
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now||b);
    
    return ci;
}

inline CircularInt operator || (int b,const CircularInt &a) {//#5
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b||a.now);
    
    return ci;
}

inline CircularInt operator || (const CircularInt &a,const CircularInt &b) {//#6
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now||b.now);
    
    return ci;
}


/////////////////////////////////////
//////Friends Bitwise operators//////
/////////////////////////////////////

/////////////////////////////
///BitwiseAND (&) operator///
/////////////////////////////
inline CircularInt operator & (const CircularInt &a,int b) {//#1
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now&b);
    
    return ci;
}

inline CircularInt operator & (int b,const CircularInt &a) {//#2
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b&a.now);
    
    return ci;
}

inline CircularInt operator & (const CircularInt &a,const CircularInt &b) {//#3
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now&b.now);
    
    return ci;
}

/////////////////////////////
///Bitwise OR (|) operator///
/////////////////////////////
inline CircularInt operator | (const CircularInt &a,int b) {//#4
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now|b);
    
    return ci;
}

inline CircularInt operator | (int b,const CircularInt &a) {//#5
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b|a.now);
    
    return ci;
}

inline CircularInt operator | (const CircularInt &a,const CircularInt &b) {//#6
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now|b.now);
    
    return ci;
}

//////////////////////////////
///Bitwise XOR (^) operator///
//////////////////////////////
inline CircularInt operator ^ (const CircularInt &a,int b) {//#7
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now^b);
    
    return ci;
}

inline CircularInt operator ^ (int b,const CircularInt &a) {//#8
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b^a.now);
    
    return ci;
}

inline CircularInt operator ^ (const CircularInt &a,const CircularInt &b) {//#9
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now^b.now);
    
    return ci;
}

//////////////////////////////////////
///Bitwise left shift (<<) operator///
//////////////////////////////////////
inline CircularInt operator << (const CircularInt &a,int b) {//#10
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now<<b);
    
    return ci;
}

inline CircularInt operator << (int b,const CircularInt &a) {//#11
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b<<a.now);
    
    return ci;
}

inline CircularInt operator << (const CircularInt &a,const CircularInt &b) {//#12
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now<<b.now);
    
    return ci;
}

///////////////////////////////////////
///Bitwise right shift (<<) operator///
///////////////////////////////////////
inline CircularInt operator >> (const CircularInt &a,int b) {//#13
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now>>b);
    
    return ci;
}

inline CircularInt operator >> (int b,const CircularInt &a) {//#14
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(b>>a.now);
    
    return ci;
}

inline CircularInt operator >> (const CircularInt &a,const CircularInt &b) {//#15
    CircularInt ci{a.lowNum,a.highNum};
    ci.now = ci.getRealVal(a.now>>b.now);
    
    return ci;
}

/////////////////////////////

    inline bool operator==(int b,CircularInt a) {
        
        if(a.getNow()==a.getRealVal(b)){
                return true;
            }

            return false;
    }

    inline bool operator!=(int b,CircularInt a) {
        
        if(a.getNow()!=a.getRealVal(b)){
                return true;
            }

            return false;
    }

    inline bool operator>(int b,CircularInt a) {
        
        if(a.getNow()<a.getRealVal(b)){
                return true;
            }

            return false;
    }

    inline bool operator>=(int b,CircularInt a) {
        
        if(a.getNow()<=a.getRealVal(b)){
                return true;
            }

            return false;
    }

    inline bool operator<(int b,CircularInt a) {
        
        if(a.getNow()>a.getRealVal(b)){
                return true;
            }

            return false;
    }

    inline bool operator<=(int b,CircularInt a) {
        
        if(a.getNow()>=a.getRealVal(b)){
                return true;
            }

            return false;
    }


//int "toString" function
inline ostream& operator << (ostream& os, const CircularInt& c) {
    return (os << c.getNow());
}

// //bool "toString" function
// inline ostream& operator << (ostream& os,const bool& c) {
//     if(c==1){
//         return (os << "True");
//     }
//     return (os << "False");
// }




    