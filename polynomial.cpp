#include "polynomial.h"

#include <iostream>
using namespace std;
Polynomial::Polynomial(int A[], int size) {
    size_ = size;
    for(int i=0;i< size; i++){
        coefficients.insert_back(A[i]);
    }
}
Polynomial* Polynomial::add(Polynomial* rhs) {
    int MaxArraySize;
    int MinArraySize;
    if(size_ >= rhs->size_){
        MinArraySize = rhs-> size_;
        MaxArraySize = size_;
    }
    else{
        MinArraySize = size_;
        MaxArraySize = rhs->size_;
    }


    int newArray [MaxArraySize];
    for (int i=0;i< MaxArraySize; i++) {
        newArray[i] = coefficients.select(i) + rhs->coefficients.select(i);

        if (rhs->size_ == MinArraySize) {
            for (int i = MinArraySize; i <= MaxArraySize; i++) {
                newArray[i] = coefficients.select(i);
            }
        } else {
            for (int i = MinArraySize; i <= MaxArraySize; i++) {
                newArray[i] = rhs->coefficients.select(i);
            }
        }
    }
    Polynomial* newPolynomial = new Polynomial(newArray, MaxArraySize);
    return newPolynomial;
}
Polynomial* Polynomial::sub(Polynomial* rhs) {
    int MaxArraySize;
    int MinArraySize;
    if(size_ >= rhs->size_){
        MinArraySize = rhs-> size_;
        MaxArraySize = size_;
    }
    else{
        MinArraySize = size_;
        MaxArraySize = rhs->size_;
    }
    int newArray [MaxArraySize];
    for (int i=0;i< MinArraySize; i++) {
        newArray[i] = coefficients.select(i) - rhs->coefficients.select(i);

        if (rhs->size_ == MinArraySize) {
            for (int i = MinArraySize; i < MaxArraySize; i++) {
                newArray[i] = coefficients.select(i);
            }
        } else {
            for (int i = MinArraySize; i < MaxArraySize; i++) {
                newArray[i] = rhs->coefficients.select(i);
            }
        }
    }


    Polynomial* newPolynomial = new Polynomial(newArray, MaxArraySize);
    return newPolynomial;
}
Polynomial* Polynomial::mul(Polynomial* rhs) {
    int MaxArraySize = size_ + rhs-> size_;

    int result[MaxArraySize];
    for(int i = 0; i<MaxArraySize;i++)
        result[i]=0;

    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < rhs->size_; j++) {
            result[i + j] += coefficients.select(i) * rhs->coefficients.select(j);
        }
    }

    Polynomial* newPolynomial = new Polynomial(result, MaxArraySize);
    return newPolynomial;
}
void Polynomial::print() {
    int notZero = 0;
    for(int i=0; i< size_;i++){
        if(coefficients.select(i) != 0){
            notZero ++;
        }
    }

    int counter = notZero;
    for(int i = size_ -1; i>= 0; i--){
        if(coefficients.select(i) != 0 && counter != 0 && counter != notZero){
            cout << " + ";
        }
        //pos
        if(coefficients.select(i) > 0 ){
            cout << coefficients.select(i) << "x^" << i;
            if (counter > 0 ){
                counter --;
            }
        }

        //neg
        else if (coefficients.select(i) < 0) {
            cout << "(" << coefficients.select(i) << ")" << "x^" << i;

            if (counter > 0) {
                counter--;
            }
        }
    }
    cout << endl;
}


