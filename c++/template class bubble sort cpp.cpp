#include<iostream>
using namespace std;

template<class T1>
class mySort
{
public:
    mySort(T1* A, int n)
    {
        int isSorted = 0;
        for(int i = 0; i < n-1; i++)
        {
            isSorted = 1;
            for(int j = 0; j < n-1-i; j++)
            {
                if(A[j] > A[j+1])
                {
                    A[j] = A[j]+A[j+1];
                    A[j+1] = A[j]-A[j+1];
                    A[j] = A[j]-A[j+1];
                    isSorted = 0;
                }
            }
            if(isSorted)
            {
                return;
            }
        }
    }

    mySort(T1* A, int n, int a)
    {
        int isSorted = 0;
        for(int i = 0; i < n-1; i++)
        {
            isSorted = 1;
            for(int j = 0; j < n-1-i; j++)
            {
                if(A[j] < A[j+1])
                {
                    A[j] = A[j]+A[j+1];
                    A[j+1] = A[j]-A[j+1];
                    A[j] = A[j]-A[j+1];
                    isSorted = 0;
                }
            }
            if(isSorted)
            {
                return;
            }
        }
    }


    void display(T1* A, int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    //float A[] = {23.6, 78.56, 12.78, 89.90, 60.7};
    int A[] = {3, 7, 4, 6, 90, 78, 99};
    int n = sizeof(A)/sizeof(int);

    mySort<int>Sort(A, n, -1);
    Sort.display(A, n);
    mySort<int>doSort(A, n);
    doSort.display(A, n);

    return 0;
}