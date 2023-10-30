#include <iostream>
#include <vector>
#include <ctime> // To initialize a random number generator
#include <cstdlib> // For the rand() and srand() functions
#include <cmath> // To use PI
#include <algorithm> // To use sort

#include "Curve.cpp"
#include "Circle.cpp"
#include "Ellipse.cpp"
#include "Helix.cpp"

# define M_PI 3.14159265358979323846 // pi

using namespace std;


int main()
{
    // TODO: step - 1

    cout << "-> Step - 1" << endl;

    Circle circle(1.0);
    Ellipse ellipse(1.0, 0.5);
    Helix helix(1.0, 0.1);

    double x = 0.0, y = 0.0, z = 0.0, dx = 0.0, dy = 0.0, dz = 0.0;
    double t = 0.0; // Setting the value of t

    // Calculate the points and derivatives for each curve at point t
    circle.getPoint(t, x, y, z);
    circle.getDerivative(t, dx, dy, dz);
    cout << "Circle: Point (" << x << ", " << y << ", " << z << "), \
        Derivative (" << dx << ", " << dy << ", " << dz << ")\n";

    ellipse.getPoint(t, x, y, z);
    ellipse.getDerivative(t, dx, dy, dz);
    cout << "Ellipse: Point (" << x << ", " << y << ", " << z << "), \
        Derivative (" << dx << ", " << dy << ", " << dz << ")\n";

    helix.getPoint(t, x, y, z);
    helix.getDerivative(t, dx, dy, dz);
    cout << "Helix: Point (" << x << ", " << y << ", " << z << "), \
        Derivative (" << dx << ", " << dy << ", " << dz << ")\n";

    // ------------------------------------------------------------------------

    // TODO: step - 2

    cout << "\n\n -> Step - 2" << endl;

    // Creating a container for storing pointers to curve objects
    vector<Curve*> curves; 

    // Initializing a random number generator
    srand(time(0)); 

    // Functions for generating random parameters
    auto getRandomRadius = []() -> double {
        // Генерация случайного радиуса от 1 до 10
        return (rand() % 10) + 1; 
    };

    auto getRandomStep = []() -> double {
        // Generating a random step from 0 to 0.4 with a step of 0.1
        return (rand() % 5) / 10.0; 
    };

    // Generating random objects and adding them to the container
    // The number of random objects we want to create
    const int numberOfCurves = 5; 

    for (int i = 0; i < numberOfCurves; ++i) {
        // Automatic curve type sampler (0 - Circle, 1 - Ellipse, 2 - Spiral)
        int choice = rand() % 3; 
        Curve* curve = nullptr;

        if (choice == 0) {
            curve = new Circle(getRandomRadius());
        }
        else if (choice == 1) {
            // For an ellipse, we use two random radii
            curve = new Ellipse(getRandomRadius(), getRandomRadius()); 
        }
        else {
            curve = new Helix(getRandomRadius(), getRandomStep());
        }

        curves.push_back(curve);
    }

    // ------------------------------------------------------------------------

    // TODO: step - 3

    cout << "\n\n -> Step - 3" << endl;

    // Passing through the container and calculating points and 
    // derivatives for t = PI/4
    const double tPi = M_PI / 4.0; // Setting t = PI/4
    cout << "tPi: " << tPi << endl;

    // set in step - 1
    // double x, y, z, dx, dy, dz;

    for (const auto& curve : curves) {
        curve->getPoint(t, x, y, z);
        curve->getDerivative(t, dx, dy, dz);

        cout << "Curve: ";
        if (dynamic_cast<Circle*>(curve) != nullptr) {
            cout << "Circle";
        }
        else if (dynamic_cast<Ellipse*>(curve) != nullptr) {
            cout << "Ellipse";
        }
        else if (dynamic_cast<Helix*>(curve) != nullptr) {
            cout << "Helix";
        }

        cout << ": Point (" << x << ", " << y << ", " << z << "), \
            Derivative (" << dx << ", " << dy << ", " << dz << ")\n";
    }

    // ------------------------------------------------------------------------

    // TODO: step - 4

    cout << "\n\n -> Step - 4-2" << endl;

    // The second container for storing pointers to Circle objects
    vector<Circle*> circles; 
    
    // Passing through the container and transferring pointers to objects
    // Circle to the second container
    for (auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve) != nullptr) {
            // Moving the pointer to the Circle object
            circles.push_back(static_cast<Circle*>(curve)); 
        }
    }

    // Passing through the second circles container and outputting
    // the radii of each Circle object
    for (const auto& circle : circles) {
        cout << "Circle Radius: " << circle->getRadius() << endl;
    }

    // ------------------------------------------------------------------------

    // TODO: step - 5

    cout << "\n\n -> Step - 5" << endl;

    sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b) {
        return *a < *b;
    });

    // Checking (output) of the sorted container
    cout << "Sorted Circles by Radius:\n";
    for (const auto& circle : circles) {
        cout << "Circle Radius: " << circle->getRadius() << endl;
    }

    // ------------------------------------------------------------------------

    // TODO: step - 6

    cout << "\n\n -> Step - 6" << endl;

    // Calculation of the total sum of the radii of all circles
    double totalRadiusSum = 0.0;

    for (const auto& circle : circles) {
        totalRadiusSum += circle->getRadius();
    }

    // Output of the total sum of radii
    cout << "Total Sum of Radii: " << totalRadiusSum << endl;

    // ------------------------------------------------------------------------

    // for step - 2
    // Freeing up memory after using objects in the container
    for (auto curve : curves) {
        delete curve;
    }
    curves.clear(); // Container Cleaning

    cout << "\n\nPress any key then Enter - for exit..." << endl;
    int userInputWait;
    cin >> userInputWait;

    return 0;
}
