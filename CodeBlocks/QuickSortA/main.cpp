#include "QuickSortA.h"


int main()
{
    cout << "Hello world!" << endl<< endl;
    testQuickSort();
    return 0;
}


void testQuickSort(){
    int diM=20;
    vector<int> vit;
    for(int ix=0;ix<diM;++ix){
        vit.push_back(rnd());
    }
    printVector<int>(vit);
    performQuickSort(vit,0,diM-1);
    printVector<int>(vit);
}
//
//
template <class T>
void printVector(vector<T>& vit){
    cout<<endl;
    for(T t:vit){
        cout<<t<<endl;
    }
    cout<<endl;
}
//
template <class T>
void performQuickSort(vector<T>& vit,int lo,int hi){
    if(lo >=hi){
      return;
    }
    int ii=lo-1;
    int jj=hi;
    T pivot = vit[hi];
    while(ii < jj){
        while(++ii < hi && vit[ii]<= pivot);
        while(--jj > lo && vit[jj]>= pivot);
        if(ii<jj){
            swapv<T>(vit,ii,jj);
        }
    }
    swapv<T>(vit,ii,hi);
    performQuickSort<T>(vit,lo,ii-1);
    performQuickSort<T>(vit,ii+1,hi);
}


template <class T>
void swapv(vector<T> &vit,int ia,int ib){
    if(vit[ia] == vit[ib]){
        return;
    }
    T tmp = vit[ib];
    vit[ib] = vit[ia];
    vit[ia] = tmp;
}
