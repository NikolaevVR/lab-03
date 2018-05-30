#include<vector>
#include <iostream>
#include "Temperature.h"
using namespace std;

int main() {
    size_t Kol_chisel;
    cerr << "Vvedite kollichestvo chisel" << endl;
    cin >> Kol_chisel;
    vector<Temperature> massive(Kol_chisel);
    cerr << "Vvedite massiv chisel" << endl;
    for (size_t i = 0; i<Kol_chisel; i++)
    {
        cin >> massive[i];
        if (cin.fail()==true) { return -1; }
        massive[i].value = convert(massive[i], 'k');
        massive[i].scale = 'K';
    }
    size_t Kol_stolb=0;
    cerr << "Vvedite kollichestvo stolbcov" << endl;
    cin >> Kol_stolb;
    // � ��������� ���� �������� �������� ������ �� ������������ ��� �� �����(����������� ���-�� ������ �������� ��� ���� ������, ��� ������ �� ����� ������������, �� ������ ���������, ��� �� ���� ���������, �� ��� ������ ����������� � ���� ������ ������ ������������ �� �����.
    double max = massive[0].value;
    for (Temperature number : massive)
    {
        if (max<number.value)
        {
            max = number.value;
        }
    }
    double min = massive[0].value;
    for (Temperature number : massive)
    {
        if (number.value<min)
        {
            min = number.value;
        }
    }
    vector <size_t> intervals(Kol_stolb, 0);
    for (Temperature number : massive)
    {
        size_t f = (size_t)((number.value - min) / (max - min) * Kol_stolb);
        if (f == Kol_stolb)
        {
            f = f - 1;
        }
        intervals[f] ++;
    }

    cout << endl;
    const size_t screen_width = 80;
    const size_t viravnivanie = 4;
    const double maximum_width = (double)(screen_width - viravnivanie);

    double max_count = intervals[0];
    for (size_t count : intervals)
    {
        if (max_count<count)
        {
            max_count = count;
        }
    }
    bool isscalingneeded = true;
    if (maximum_width<max_count) {
        isscalingneeded = false;
    }
    for (size_t i = 0; i<max_count; i++)
    {
        if (isscalingneeded == false)
        {
            double koeff = maximum_width / max_count;
            intervals[i] = (size_t)(intervals[i] * koeff);
        }
        for (size_t j = 0; j<Kol_stolb; j++)
        {
            if (i<intervals[j]) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
