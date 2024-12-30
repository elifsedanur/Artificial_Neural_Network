#include <math.h>
#include "Sample.h"

int sgn(double output);
double sigmoid(double net, double lamda); //bipolar sigmoid function
double derivativeOfSigmoid(double net, double lamda);
double* calculateMean(Sample* samples, int size);
double* calculateStdDer(Sample* samples, int size);
Sample* MeanStdNormalization(Sample* samples, int size);
int YPoint(int x, double* w, int carpan = 1);
void updateWeight(Layer* layers, int hLayerCount, int* desiredValue);