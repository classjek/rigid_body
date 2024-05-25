#include <iostream>
#include <chrono>
#include <cmath>
#include "RigidBody.h"
#include "Physics.h"


int main() {
    // Example of initializing a RigidBody
    RigidBody body(Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0));
    double dt = 0.01; // step size = 0.01 seconds

    // Get start time
    auto startTime = std::chrono::high_resolution_clock::now();

    double simulate_time = 10;
    int iterations = simulate_time / dt; 

    // Simulation loop (for example, simulate for 10 seconds)
    // for (int t = 0; t < iterations; t += 1) {
    //     explicitEuler(body, dt);

    //     // Print the position and velocity at each step
    //     if ( t % 100 == 0){
    //         std::cout << "Time: " << t * dt << "s, Position: (" << body.position.x << ", " 
    //               << body.position.y << ", " << body.position.z << "), Velocity: ("
    //               << body.velocity.x << ", " << body.velocity.y << ", " 
    //               << body.velocity.z << ")" << std::endl;
    //     }


    //     // Wait for next time-step 
    //     auto now = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(now - startTime).count();
    //     while (elapsed < (t * dt) + dt) {
    //         now = std::chrono::high_resolution_clock::now();
    //         elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(now - startTime).count();
    //     }
    // }

    // Eigen::Matrix3d identityMatrix = Eigen::Matrix3d::Identity();
    //std::cout << "3x3 Identity Matrix:\n" << body.rotation << std::endl;
    //Eigen::Vector3d omega(1.0, 2.0, 3.0);
    //std::cout << "cross matrix:\n" << cross_matrix(omega);
    std::cout << body.rotation << '\n';

    // Rotate about the x axis by 2 radians
    Eigen::Vector3d twist(1.0, 0.0, 0.0);
    std:: cout << exp_rotation(twist, body.rotation, 1.5708) << '\n';
    std::cout << toRadians(180) << " " << toRadians(360) << " " << toRadians(90) << '\n';


    return 0;
}

