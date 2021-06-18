#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
#include <bits/stdc++.h>
#include<limits>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <chrono>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::swap;
using std::numeric_limits;
using std::fixed;
using std::setprecision;
using std::setw;
using std::ifstream;
using std::stringstream;
using std::ofstream;
struct pazymiai
{
    string vardas, pavarde;
    vector <int> pazymys = {};
    double galutinis;
    pazymiai()
    {
        galutinis = 0;
    }
};
int ZodziuKiekis(string str);
#endif // ADD_H_UNCLUDED
