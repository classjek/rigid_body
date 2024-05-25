#include "Physics.h"

// Input degree and output corresponding radian
double toRadians(double degrees){
    return degrees * M_PI / 180.0; 
}

// Explicit Euler method for calculating position
// Could lead to stability problems -> Look into it
void explicitEuler(RigidBody& body, double dt) {
    // Update position based on current velocity
    body.position.x += body.velocity.x * dt;
    body.position.y += body.velocity.y * dt;
    body.position.z += body.velocity.z * dt;
}

// Cross Product Matrix
// Note that it is skew-symmetric
Eigen::Matrix3d cross_matrix(const Eigen::Vector3d& omega){
    Eigen::Matrix3d cross_product_matrix; 
    cross_product_matrix << 0, -omega.z(), omega.y(),
                        omega.z(), 0, -omega.x(), 
                        -omega.y(), omega.x(), 0;
    return cross_product_matrix; 
}

// Use fact that for a unit vector u, A the cross product matrix of said unit vector, and angle t in radians
//     e^tA represents the rotation matrix about the line throuhg the origin in the direction u by t 
Eigen::Matrix3d exp_rotation(const Eigen::Vector3d& omega, const Eigen::Matrix3d& orientation, double rad){
    // Normalize omega  
    Eigen::Vector3d omega_norm = omega.normalized();

    Eigen::Matrix3d omega_cross_matrix = cross_matrix(omega_norm);
    // Multiply cross product matrix by angle of rotation
    omega_cross_matrix *= rad;

    Eigen::Matrix3d rotation_matrix = omega_cross_matrix.exp();
    Eigen::Matrix3d updated_orientation = rotation_matrix * orientation; 

    return updated_orientation;    
}



