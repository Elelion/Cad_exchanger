#pragma once
#include "Curve.cpp"


class Helix : public Curve
{
    private:
        double radius;
        double step;

    public:
        /**
         * Constructor that accepts the radius of the spiral and 
         * the pitch of the spiral
         */
        Helix(double r, double s) : radius(r), step(s) {}

        /**
         * Implementation of a virtual function for calculating a 3D point 
         * on a spiral for a given parameter t
         */
        void getPoint(double t, double& x, double& y, double& z) const override {
            // Parametric equations of a spiral in 3D space
            x = radius * cos(t);
            y = radius * sin(t);

            // Along the Z axis, the spiral rises with a constant step
            z = step * t; 
        }

        /**
         * Implementation of a virtual function for calculating the first
         * the derivative (vector) on the spiral for a given parameter t
         */
        void getDerivative(
            double t, 
            double& dx, 
            double& dy, 
            double& dz
        ) const override {
            // The first derivative of the spiral vector
            dx = -radius * sin(t);
            dy = radius * cos(t);

            // The derivative Z is equal to the constant pitch of the spiral
            dz = step; 
        }
};
