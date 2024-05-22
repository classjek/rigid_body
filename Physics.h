#ifndef PHYSICS_H
#define PHYSICS_H

#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include "RigidBody.h"

// Function to update the position of a rigid body using the explicit Euler method
void explicitEuler(RigidBody& body, double dt);
Eigen::Matrix3d cross_matrix(const Eigen::Vector3d& omega);
Eigen::Matrix3d exp_rotation(const Eigen::Vector3d& omega, const Eigen::Matrix3d& orientation, double rad);

#endif // PHYSICS_H
