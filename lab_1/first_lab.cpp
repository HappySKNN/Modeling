//
// Created by HappySKN on 09.02.2023.
//

#include "first_lab.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

const int N = 1000;

double chi_square(const vector<int> &a) {
    map<int, int> freq;

    for (auto &i: a) {
        freq[i]++;
    }

    double average_expectation = N / freq.size();
    double chi = 0.0;

    for (auto &i: freq) {
        chi += pow(i.second - average_expectation, 2) / average_expectation;
    }

    return chi;
}

double autocorrelation(vector<int> a) {
    vector<int> left(a.begin(), a.end() - 1);
    vector<int> right(a.begin() + 1, a.end());

    double avg_left = accumulate(left.begin(), left.end(), 0.0) / left.size();
    double avg_right = accumulate(right.begin(), right.end(), 0.0) / right.size();

    double numerator = 0.0;

    for (int i = 0; i < left.size(); i++) {
        numerator += (left[i]) * (right[i]);
    }
    numerator /= left.size();

    double dispersion_left = 0.0;
    double dispersion_right = 0.0;

    for (int i = 0; i < left.size(); i++) {
        dispersion_left += pow(left[i], 2);
        dispersion_right += pow(right[i], 2);
    }

    dispersion_left /= left.size();
    dispersion_right /= right.size();

    dispersion_left -= pow(avg_left, 2);
    dispersion_right -= pow(avg_right, 2);

    double denominator = sqrt(dispersion_left * dispersion_right);

    return (numerator - avg_left * avg_right) / denominator;

}

vector<int> generate_random_vector() {
    vector<int> a(N);
    mt19937 engine(time(nullptr));
    uniform_int_distribution<int> distribution(1, (int) sqrt(N));
    ofstream out("..\\result.txt");


    for (int i = 0; i < N; i++) {
        a[i] = distribution(engine);
        out << a[i] << endl;
    }

    return a;
}

void calculate_all() {
    vector<int> a = generate_random_vector();

    double chi = chi_square(a);
    double corr = autocorrelation(a);

    cout << "Chi square: " << chi << endl << "Correlation: " << corr << endl;
}