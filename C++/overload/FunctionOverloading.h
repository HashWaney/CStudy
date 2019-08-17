//
// Created by Hash on 2019-08-14.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#ifndef CPLUSPLUS_FUNCTIONOVERLOADING_H
#define CPLUSPLUS_FUNCTIONOVERLOADING_H


class FunctionOverloading {
public:
    FunctionOverloading(double real =0.0, double img=0.0):m_real(real),m_img(img){}
    void print() const ;
    FunctionOverloading operator+(const FunctionOverloading &A) const ;

private:
    double m_real;
    double m_img;
};


#endif //CPLUSPLUS_FUNCTIONOVERLOADING_H
