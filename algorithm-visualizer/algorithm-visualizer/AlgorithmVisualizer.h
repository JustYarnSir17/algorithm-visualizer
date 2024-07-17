#ifndef ALGORITHM_VISUALIZER_H
#define ALGORITHM_VISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>

enum class Algorithm {
    BubbleSort,
    QuickSort,
    InsertionSort,
    SelectionSort
};

class AlgorithmVisualizer {
public:
    AlgorithmVisualizer();
    void update();
    void render(sf::RenderWindow& window);  // ¼±¾ð
    void setAlgorithm(Algorithm algo);

private:
    std::vector<int> data;
    Algorithm currentAlgorithm;
    void initializeData();
    void bubbleSortStep();
    void quickSortStep();
    void insertionSortStep();
    void selectionSortStep();
    int partition(int low, int high);
    void quickSort(int low, int high);
    bool sorted;
};

#endif // ALGORITHM_VISUALIZER_H
