#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <Eigen/Dense>

// change to Eigen::Vector3d
struct Vector3 {
    double x, y, z; 
    Vector3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}
};

struct RigidBody {
    Vector3 position;  // Position vector
    Vector3 velocity;  // Velocity vector
    Eigen::Matrix3d rotation = Eigen::Matrix3d::Identity();

    // Constructor to initialize position and velocity
    RigidBody(const Vector3& position, const Vector3& velocity)
        : position(position), velocity(velocity) {}
};

#endif // RIGIDBODY_H
