#include "pch.h"
#include "Process.h"
#include "Sample.h"
#include <iostream>
using namespace std;

int sgn(double output) {

	return (output >= 0.0 ? 1 : -1);
}

/*int perceptionLearning(double* w, Samples* samples, int size) {
	double c = 0.1;
	int err = 0;
	int cycle = 0;
	double sum;
	int fnet;
	int i;

	do {
		err = 0;

		for (i = 0; i < size; i++) {
			sum = w[0] * samples[i].x1 + w[1] * samples[i].x2 + w[3] * samples[i].w;  //Toplama fonksiyonu
			fnet = sgn(sum);

			if (fnet != samples[i].label) {
				err++;
				w[0] = w[0] + c * (samples[i].label - fnet) * samples[i].x1;
				w[1] = w[1] + c * (samples[i].label - fnet) * samples[i].x2;
				w[2] = w[2] + c * (samples[i].label - fnet) * samples[i].w;
			}

		}
		cycle++;
	} while (err == 0);

	return cycle;
}*/
double sigmoid(double net, double lamda) { //bipolar sigmoid function
	return ((2 / (1 + exp(-lamda * net))) - 1);
}

double derivativeOfSigmoid(double net, double lamda) {
	double fnet = sigmoid(net, lamda);
	return 0.5 * (1 - pow(fnet, 2));
}
double* calculateMean(Sample* samples, int size) {
	double* means = new double[2];  //means[0] -> x1'lerin ortalamasý means[1] -> x2 lerin ortalamasýný tutar
	double x1sum = 0;
	double x2sum = 0;

	for (int i = 0; i < size; i++) {
		x1sum += samples[i].x[0];
		x2sum += samples[i].x[1];
	}
	means[0] = x1sum / size;
	means[1] = x2sum / size;

	return means;
}
double* calculateStdDer(Sample* samples, int size) {
	double* means = calculateMean(samples, size);
	double* std = new double[2];  //std[0]->x1'lerin std std[1] -> x2 lerin std tutar
	double x1sum = 0;
	double x2sum = 0;

	for (int i = 0; i < size; i++) {
		x1sum += pow(samples[i].x[0] - means[0], 2);
		x2sum += pow(samples[i].x[1] - means[1], 2);
	}

	std[0] = sqrt(x1sum / size);
	std[1] = sqrt(x2sum / size);

	return std;
}
Sample* MeanStdNormalization(Sample* samples, int size) {
	Sample* normalizedSamples = new Sample[size];
	double* means = calculateMean(samples, size);
	double* stds = calculateStdDer(samples, size);

	for (int i = 0; i < size; i++) {
		normalizedSamples[i].x[0] = (samples[i].x[0] - means[0]) / stds[0];
		normalizedSamples[i].x[1] = (samples[i].x[1] - means[1]) / stds[1];
		normalizedSamples[i].label = samples[i].label;
	}
	return normalizedSamples;
}
int YPoint(int x, double* w, int carpan) {
	return (int)((double)(-1 * (double)carpan * w[2] - w[0] * x) / (double)(w[1]));
}
void updateWeight(Layer* layers, int hLayerCount, int* desiredValue, Sample* normalizedSamples) {
	int i, k, j, l;
	double net;
	double c = 0.1;
	int desired;
	double error = 0;
	double totalError = 0;
	int cycle = 0;
	int width;
	//çýkýþ katmaný için backpropagation
	width = (layers[hLayerCount].inputDim + 1);
	for (k = 0; k < layers[hLayerCount].numOfNeuron; k++) {
		desired = desiredValue[normalizedSamples[i].label * layers[hLayerCount].numOfNeuron + k];
		error += 0.5 * pow((desired - layers[hLayerCount].outputs[k]), 2);
		layers[hLayerCount].delta[k] = (desired - layers[hLayerCount].outputs[k]) * layers[hLayerCount].out_derived[k];

		for (j = 0; j < layers[hLayerCount].inputDim; j++) {
			layers[hLayerCount].W[k * width + j] += c * layers[hLayerCount].delta[k] * layers[hLayerCount - 1].outputs[j];
		}
		layers[hLayerCount].W[k * width + layers[hLayerCount].inputDim] += c * layers[hLayerCount].delta[k];

	}
	totalError += (error / layers[hLayerCount].numOfNeuron);
	//backpropagation
	for (l = hLayerCount - 1; l > 0; l--) {
		width = (layers[l].inputDim + 1);
		for (k = 0; k < layers[l].numOfNeuron; k++) {
			layers[l].delta[k] = 0;

			for (int kk = 0; kk < layers[l + 1].numOfNeuron; kk++) {
				layers[l].delta[k] += layers[l + 1].delta[kk] * layers[l + 1].W[kk * (layers[l + 1].inputDim + 1) + k];
			}
			layers[l].delta[k] *= layers[l].out_derived[k];

			for (j = 0; j < layers[l].inputDim; j++) {
				layers[l].W[k * width + j] += c * layers[l].delta[k] * layers[l - 1].outputs[j];

			}
			layers[l].W[k * width + layers[l].inputDim] += c * layers[l].delta[k];


		}
	}//giriþ için aðýrlýk güncellemesi
	width = (layers[0].inputDim + 1); //DIMENSION+1
	for (k = 0; k < layers[0].numOfNeuron; k++) {
		layers[0].delta[k] = 0;
		for (int kk = 0; kk < layers[1].numOfNeuron; kk++) {
			layers[0].delta[k] += layers[1].delta[kk] * layers[1].W[kk * (layers[1].inputDim + 1) + k];
		}
		layers[0].delta[k] *= layers[0].out_derived[k];

		for (j = 0; j < layers[0].inputDim; j++) {
			layers[0].W[k * width + j] += c * layers[0].delta[k] * normalizedSamples[i].x[j];

		}
		layers[0].W[k * width + layers[0].inputDim] += c * layers[0].delta[k];

	}
}
