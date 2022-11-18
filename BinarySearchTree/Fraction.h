#pragma once
#ifndef _FRACTION_H_
#define _FRACTION_H_
#include "Lib/Node.h"
#include "Lib/IntNumber.h"
struct Fraction{
    int Numerator, Denominator;
    Fraction() : Numerator(1), Denominator(1) {}
    Fraction(int x) : Numerator(x), Denominator(1) {}
    Fraction(int x, int y){
        if(x < 0 && y < 0){
            Numerator = x * -1;
            Denominator = y * -1;
        }else if(y < 0){
            Numerator = x;
            Denominator = y * -1;
        }else{
            Numerator = x;
            if(y == 0){
                cout << "0 was changed to 1!" << endl;
                Denominator = 1;
            }
        }
    }
    int getNumerator(){
        return Numerator;
    }
    int getDenominator(){
        return Denominator;
    }
    bool input(){
        cout << "Enter numerator: ";
        cin >> Numerator;
        do{
            cout << "Enter denominator( != 0): ";
            cin >> Denominator;
        }while(Denominator == 0);
        if(Denominator < 0){
            Numerator *= -1;
            Denominator *= -1;
        }
        return true;
    }

    void show(){
        cout << Numerator << "/" << Denominator << " ";
    }

    float value(){
        return Numerator/Denominator*1.0;
    }

};

void traverseTreeFracLRN(Node<Fraction> *root){
    if(root == NULL) return;
    traverseTreeFracLRN(root->getPrev());
    traverseTreeFracLRN(root->getNext());
    root->getInfo().show();
}
void traverseTreeFracLNR(Node<Fraction> *root){
    if(root == NULL) return;
    traverseTreeFracLRN(root->getPrev());
    root->getInfo().show();
    traverseTreeFracLRN(root->getNext());
}
void traverseTreeFracNLR(Node<Fraction> *root){
    if(root == NULL) return;
    root->getInfo().show();
    traverseTreeFracLRN(root->getPrev());
    traverseTreeFracLRN(root->getNext());
}
void traverseTreeFracNRL(Node<Fraction> *root){
    if(root == NULL) return;
    root->getInfo().show();
    traverseTreeFracLRN(root->getNext());
    traverseTreeFracLRN(root->getPrev());
}
void traverseTreeFracRNL(Node<Fraction> *root){
    if(root == NULL) return;
    traverseTreeFracLRN(root->getNext());
    root->getInfo().show();
    traverseTreeFracLRN(root->getPrev());
}
void traverseTreeFracRLN(Node<Fraction> *root){
    if(root == NULL) return;
    traverseTreeFracLRN(root->getNext());
    traverseTreeFracLRN(root->getPrev());
    root->getInfo().show();
}

Node<Fraction>* findTNodeLargerThanX(Node<Fraction> *root, Fraction X){
    if(root == NULL) return NULL;
    if(root->getInfo().value() > X.value()) return root;
    findTNodeLargerThanX(root->getPrev(), X);
    findTNodeLargerThanX(root->getNext(), X);
}

Node<Fraction> *findTNodeHasDenominatorIsPrime(Node<Fraction> *root){
    if(root == NULL) return NULL;
    if(isPrime(root->getInfo().getDenominator()) == true) return root;
    findTNodeHasDenominatorIsPrime(root->getNext());
    findTNodeHasDenominatorIsPrime(root->getPrev());
}

float totalFraction(Node<Fraction> *root){
    if(root == NULL) return 0.0;
    float cnr = totalFraction(root->getNext()),
        cnl = totalFraction(root->getPrev());
    return root->getInfo().value() + cnr + cnl;
}

Node<Fraction> *findMinFraction(Node<Fraction> *root){
    if(root == NULL) return NULL;
    if(root->getPrev() == NULL) return root;
    return findMinFraction(root->getPrev());
}

Node<Fraction> *findMaxFraction(Node<Fraction> *root){
    if(root== NULL) return NULL;
    if(root->getNext() == NULL) return root;
    return findMaxFraction(root->getNext());
}

void showNumeratorLargerThanDenominator(Node<Fraction> *root){
    if(root== NULL) return;
    if(root->getInfo().getNumerator() > root->getInfo().getDenominator()) root->getInfo().show();
    showNumeratorLargerThanDenominator(root->getNext());
    showNumeratorLargerThanDenominator(root->getPrev());
}

void showNumeratorSmallerThanDenominator(Node<Fraction> *root){
    if(root== NULL) return;
    if(root->getInfo().getNumerator() < root->getInfo().getDenominator()) root->getInfo().show();
    showNumeratorLargerThanDenominator(root->getNext());
    showNumeratorLargerThanDenominator(root->getPrev());
}

void showFractionHasNumeAndDenoIsPrime(Node<Fraction> *root){
    if(root == NULL )return;
    if(isPrime(root->getInfo().getNumerator()) && isPrime(root->getInfo().getDenominator())) root->getInfo().show();
    showFractionHasNumeAndDenoIsPrime(root->getNext());
    showFractionHasNumeAndDenoIsPrime(root->getPrev());
}

void showFractionAtK(Node<Fraction> *root, int &k){
    if(root == NULL || k < 0) return;
    root->getInfo().show();
    showFractionAtK(root->getNext(), k-1);
    showFractionAtK(root->getPrev(), k-1);
}
int countFractionAtK(Node<Fraction>* root, int& k){
    if(root == NULL || k < 0) return 0;
    int cnr = countFractionAtK(root->getNext(), k-1),
        cnl = countFractionAtK(root->getPrev(), k-1);

    return 1 + cnr + cnl;
}

int countFracHasNumAndDenoisPrime(Node<Fraction> *root, int &k){
    if(root == NULL  || k < 0) return 0;
    k-=1;
    int cnl = countFracHasNumAndDenoisPrime(root->getPrev(), k),
        cnr = countFracHasNumAndDenoisPrime(root->getNext(), k);
    return 1 + cnl + cnr;
}
#endif