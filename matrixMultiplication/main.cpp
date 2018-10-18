#include <iostream>
#include <array>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::duration;
using namespace std;

void outputVector(int inputVector[], int inputVectorLength)
{
    for (int i=0; i<=inputVectorLength-1; i++)
    {
        cout << inputVector[i] << "  ";
    }
}

void foo(int N, int k)
{
    int myVector[N];
    int myMatrix[N][N];

    for(int iterations=1; iterations <=k; iterations++)
    {
        //Vector
        //cout << "VECTOR" << endl;
        for (int i = 0; i <= N - 1; i++) {
            myVector[i] = rand() % 9;
        }
        //outputVector(myVector, N);

        //Matrix
        //cout << endl << endl << "MATRIX" << endl;
        for (int i = 0; i <= N - 1; i++) {
            for (int j = 0; j <= N - 1; j++) {
                myMatrix[i][j] = rand() % 9;
                //cout << myVector[i] << "  ";
            }
            //cout << endl;
        }

        //Multiply Matrix with Vector
        int multipliedVector[N];
        for (int i = 0; i <= N - 1; i++) {
            int k = 0;

            for (int j = 0; j <= N - 1; j++) {
                int prod = myMatrix[j][i] * myVector[j];
                k = k + prod;
            }

            multipliedVector[i] = k;
        }
    }
}

int main()
{

    auto start = system_clock::now();
    const int N = 100;
    const int k = 10000;
    foo(N, k);
    auto end = system_clock::now();
    const double elapsed_seconds = duration<double>(end - start).count();
    cout << "Seconds: " << elapsed_seconds;

    return 0;

}