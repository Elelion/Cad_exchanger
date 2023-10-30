#pragma once
#include "Curve.cpp"


class Circle : public Curve
{
    private:
        double radius;

    public:
        /**
         * Constructor that accepts the radius of a circle
         */
        Circle(double r) : radius(r) {}

        /**
         * Implementation of a virtual function for calculating a 3D 
         * point on a circle for a given parameter t
         */
        void getPoint(
            double t, 
            double& x, 
            double& y, 
            double& z
        ) const override {
            // Parametric equations of a circle in the XoY plane
            x = radius * cos(t);
            y = radius * sin(t);

            // Since the circle is in the XoY plane, Z = 0
            z = 0.0; 
        }

        /**
         * Implementation of a virtual function for calculating the 
         * first derivative (vectors) on a circle for a given parameter t
         */
        void getDerivative(
            double t, 
            double& dx, 
            double& dy, 
            double& dz
        ) const override {
            // The first derivative of the circle vector is a vector
            // directed along the circle
            dx = -radius * sin(t);
            dy = radius * cos(t);

            // The derivative of Z = 0, since Z is always 0 in the XoY plane
            dz = 0.0; 
        }

        double getRadius() {
            return radius;
        }

        /**
         * Redefinition of the < operator for comparison by radii
         * Now the Circle class will have a < operator that compares
         * Circle objects by their radii.
         */
        bool operator<(const Circle& other) const {
            return radius < other.radius;
        }
};
