#pragma once
#include <iostream>


class Curve
{
    public:
        /**
         * Virtual function for calculating a 3D point on a curve for
         * the specified parameter t
         */
        virtual void getPoint(
            double t, 
            double& x, 
            double& y, 
            double& z
        ) const = 0;

        /**
         * Virtual function for calculating the first derivative (vector)
         * on the curve for a given parameter t
         */
        virtual void getDerivative(
            double t, 
            double& dx, 
            double& dy, 
            double& dz
        ) const = 0;

        /**
         * Virtual destructor for correct deletion of objects via
         * pointer to the base class
         */
        virtual ~Curve() {}
};
