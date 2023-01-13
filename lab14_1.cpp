    #include <iostream>
    #include <cmath>
    using namespace std;

    void stat(const double[],int,double[]);

    int main(){
        double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
        int N = sizeof(A)/sizeof(A[0]);
        double B[6];
        stat(A,N,B);
        cout << "Arithmetic Mean = " << B[0];
        cout << "\nStandard Deviation = " << B[1];
        cout << "\nGeometric Mean = " << B[2];
        cout << "\nHarmonic Mean = " << B[3];
        cout << "\nMax = " << B[4];
        cout << "\nMin = " << B[5];
        return 0;
    }

    void stat(const double x[], int num, double y[])
    {
        double sum = 0, sumup = 0, summulti = 1, sumhalf = 0, max = 0, min = 999, mean, stdd, gmean, hmean;
        for (int i = 0; i < num; i++)
        {
            sum += x[i];
            summulti *= x[i];
            sumhalf += 1.0/x[i];
            sumup += pow(x[i], 2);
            if (max <= x[i]) max = x[i];
            else if (min >= x[i]) min = x[i];
        }
        mean = sum / num;
        stdd = sqrt((sumup / num) - pow(mean, 2));
        gmean = pow(summulti, (1.0/num));
        hmean = num / sumhalf;
        double dummy[6] = {mean, stdd, gmean, hmean, max, min};
        for (int i = 0; i < num; i++)
        {
            y[i] = dummy[i];
        }
    }
