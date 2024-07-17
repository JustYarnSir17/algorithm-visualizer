#include "AlgorithmVisualizer.h"
#include <algorithm>
#include <iostream>

AlgorithmVisualizer::AlgorithmVisualizer() : currentAlgorithm(Algorithm::BubbleSort), sorted(false) {
	initializeData();
}

void AlgorithmVisualizer::initializeData() {
	data = { 150, 100, 200, 50, 250, 75, 125, 175 };
	sorted = false;
}

void AlgorithmVisualizer::setAlgorithm(Algorithm algo) {
	currentAlgorithm = algo;
	initializeData();
}

void AlgorithmVisualizer::update() {
	if (!sorted) {
		switch (currentAlgorithm) {
		case Algorithm::BubbleSort:
			bubbleSortStep();
			break;
		case Algorithm::QuickSort:
			quickSortStep();
			break;
		case Algorithm::InsertionSort:
			insertionSortStep();
			break;
		case Algorithm::SelectionSort:
			selectionSortStep();
			break;
		}
	}
}


void AlgorithmVisualizer::bubbleSortStep() {
    static size_t i = 0, j = 0;
    if (i < data.size()) {
        if (j < data.size() - i - 1) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
            j++;
        }
        else {
            j = 0;
            i++;
        }
    }
    else {
        sorted = true;
    }
}

int AlgorithmVisualizer::partition(int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

void AlgorithmVisualizer::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void AlgorithmVisualizer::quickSortStep() {
    static int low = 0, high = data.size() - 1;
    quickSort(low, high);
    sorted = true;
}

void AlgorithmVisualizer::insertionSortStep() {
    static size_t i = 1;
    if (i < data.size()) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
        i++;
    }
    else {
        sorted = true;
    }
}

void AlgorithmVisualizer::selectionSortStep() {
    static size_t i = 0;
    if (i < data.size()) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
        i++;
    }
    else {
        sorted = true;
    }
}