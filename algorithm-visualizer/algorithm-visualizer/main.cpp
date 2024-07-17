#include <SFML/Graphics.hpp>
#include "AlgorithmVisualizer.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

	AlgorithmVisualizer visualizer;
	visualizer.setAlgorithm(Algorithm::BubbleSort);


}
