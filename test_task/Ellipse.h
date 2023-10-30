#pragma once
#include "Curve.cpp"


class Ellipse : public Curve 
{
    private:
        double xAxisRadius;
        double yAxisRadius;

    public:
        /**
         * Constructor that accepts ellipse radii along the X and Y axes
         */
        Ellipse(double x, double y) : xAxisRadius(x), yAxisRadius(y) {}

        /**
         * Implementation of a virtual function for calculating a 3D point 
         * on an ellipse for a given parameter t
         */
        void getPoint(double t, double& x, double& y, double& z) const override {
            // Parametric equations of an ellipse in the XoY plane
            x = xAxisRadius * cos(t);
            y = yAxisRadius * sin(t);

            // Since the ellipse is in the XoY plane, Z = 0
            z = 0.0; 
        }

        /** 
         * Implementation of a virtual function for calculating the first 
         * derivative (vectors) on an ellipse for a given parameter t
         */
        void getDerivative(
            double t, 
            double& dx, 
            double& dy, 
            double& dz
        ) const override {
            // The first derivative of the ellipse vector is a vector 
            // directed along the ellipse
            dx = -xAxisRadius * sin(t);
            dy = yAxisRadius * cos(t);

            // The derivative of Z is 0, since Z is always 0 in the XoY plane
            dz = 0.0; 
        }
};
