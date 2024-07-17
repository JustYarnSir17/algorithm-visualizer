#include <SFML/Graphics.hpp>
#include "AlgorithmVisualizer.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

	AlgorithmVisualizer visualizer;
	visualizer.setAlgorithm(Algorithm::BubbleSort);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1)
                    visualizer.setAlgorithm(Algorithm::BubbleSort);
                else if (event.key.code == sf::Keyboard::Num2)
                    visualizer.setAlgorithm(Algorithm::QuickSort);
                else if (event.key.code == sf::Keyboard::Num3)
                    visualizer.setAlgorithm(Algorithm::InsertionSort);
                else if (event.key.code == sf::Keyboard::Num4)
                    visualizer.setAlgorithm(Algorithm::SelectionSort);
            }
        }

        visualizer.update();
        window.clear();
        visualizer.render(window);
        window.display();
    }

    return 0;
}
