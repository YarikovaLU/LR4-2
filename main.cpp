#include <locale.h>
#include <cmath>
#include <iostream>
#include "plant.h"
#include <iomanip>

using namespace std;

//���������� ��� ����� �������� ������:
//(���) L1, L2, L3, N, Xn1, Xn2, Xn3, B1, B2, B3.
void EnterN (int &n, int l[], double xn[], double b[])
{
    cout << "������� ����� �������������� ������ ��������� (N): ";
    cin >> n;

    cout << "������� ������ ���� ������� ������ L (3): ";
    for (size_t i = 0; i < 3; i++){
            cin >> l[i];
    }

    cout << "������� ����������� �������� (Xn): ";
    for (size_t i = 0; i < 3; i++){
        cin >> xn[i];
    }

    cout << "������� ���������� ���������� �� �������� (B): ";
    for (size_t i = 0; i < 3; i++){
        cin >> b[i];
    }
}

void Brak (double b[], double x[], double xn[], double br[])
{
    for (size_t i=0; i<3; i++){
              if ((-b[i] < fabs (x[i] - xn[i])) && (fabs (x[i] - xn[i]) < b[i])){
                br[i] = 1;
            } else {
                br[i] = 0;
            }
    }
}

int main()
{
    setlocale(0, "Russian");
    Plant plant;
    plant_init(plant);

    //1) ������ ��� ������ ����� EnterN;
    int L[3], result, number, D, N;
    double X[3], B[3], Br[3], Xn[3];
    EnterN (N, L, Xn, B);
    number = 0;

    cout <<  "     X1\t" << "      X2\t" << "X3  "
         << "���������  " << "�����\n";


    for (size_t p=0; p < N; p++)
    {
        for (size_t q=0; q<3; q++){
            X[q] = plant_measure(L[q], plant);
        }

        Brak (B, X, Xn, Br);

        for (size_t q=0; q<3; q++){
            cout << setprecision(2) << setw(8);
            cout << fixed << X[q] << " ";
        }
        cout << "|";

        result = 1;

        for (size_t t=0; t<3; t++){
            cout << setprecision(0) << setw(2);
            cout << fixed << Br[t] << " ";
            result = result * Br[t];
        }
        //cout << " | " << result;
        if (result == 0){
            cout << "| ���� \n";
            number++;
        } else {
            cout << "| ����� \n";
        }

    }

    cout << "\n����� ����������� ������ ��������� = " << number << "\n";
    cout << "�� ���� � ��������� �� N = " << number*100/N << "\n";

    return 0;
}
