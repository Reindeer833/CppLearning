#ifndef QUICKSORTA_H_INCLUDED
#define QUICKSORTA_H_INCLUDED


#include <iostream>
#include <vector>
#include <random>
#include <functional>


using namespace std;



vector<int> vit;

void testQuickSort();

template <class T>
void performQuickSort(vector<T>& vit,int lo,int hi);

template <class T>
void swapv(vector<T> &vit,int ia,int ib);

template <class T>
void printVector(vector<T>& vit);

random_device rde;
mt19937 rndG(rde());
uniform_int_distribution<int> uiD(0,1);

auto rnd =bind(uiD,rndG);

#endif // QUICKSORTA_H_INCLUDED
