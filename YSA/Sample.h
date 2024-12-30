#pragma once
#include <time.h>
#include <iostream>
#define DIMENSION 2

struct Sample {
	double* x = new double[DIMENSION];
	int label;
	~Sample() { delete x; }
};
struct Layer {
	int numOfNeuron;
	int inputDim;
	double* W;
	double* moment;
	double* outputs;  //fnet
	double* out_derived;
	double* delta;

	void InitializeValue(int neuronCount, int inputCount) {
		numOfNeuron = neuronCount;
		inputDim = inputCount;
		outputs = new double[neuronCount];
		out_derived = new double[neuronCount];
		delta = new double[neuronCount];
		W = new double[neuronCount * (inputCount + 1)];  //bias dahil
		moment = new double[neuronCount * (inputCount + 1)];
	}
	void startTheWeights() {
		srand(time(0));
		for (int i = 0; i < numOfNeuron; i++) {
			for (int j = 0; j < (inputDim + 1); j++) { //bias deðeri dahil edildi
				W[i * (inputDim + 1) + j] = ((double)rand() / (RAND_MAX)) * 2.0 - 1.0;  //-1 1 arasýnda random deðer
				moment[i * (inputDim + 1) + j] = 0;
			}
		}
	}
	void startMoment() {
		for (int i = 0; i < numOfNeuron; i++) {
			for (int j = 0; j < (inputDim + 1); j++) { //bias deðeri dahil edildi
				moment[i * (inputDim + 1) + j] = 0;
			}
		}
	}

	~Layer() {
		delete[] W;
		delete[] outputs;
		delete[] out_derived;
		delete[] delta;
	}
};