#include <assert.h>
#include "../include/nuclear/particle.h"

using namespace nuclear;


/*
 * --------------------------------------------------------------------------
 * FUNCTIONS DECLARED IN HEADER:
 * --------------------------------------------------------------------------
 */

void particle::integrate(real duration)
{
    // We don’t integrate things with infinite mass.
    if (inverseMass <= 0.0f) return;

    assert(duration > 0.0);

    // Update linear position.
    position.addScaledVector(velocity, duration);

    // Work out the acceleration from the force.
    // (We’ll add to this vector when we come to generate forces.)
    Vector3 resultingAcc = acceleration;

    // Update linear velocity from the acceleration.
    velocity.addScaledVector(resultingAcc, duration);

    // Impose drag.
    velocity *= real_pow(damping, duration);
    
    // Clear the forces.
    clearAccumulator();
}

void particle::setMass(const real mass)
{
    assert(mass != 0);
    particle::inverseMass = ((real)1.0)/mass;
}

void particle::setInverseMass(const real inverseMass)
{
    particle::inverseMass = inverseMass;
}

void particle::setDamping(const real damping)
{
    particle::damping = damping;
}

void particle::setPosition(const Vector3 &position)
{
    particle::position = position;
}

void particle::setPosition(const real x, const real y, const real z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void particle::getPosition(Vector3 *position) const
{
    *position = particle::position;
}

Vector3 particle::getPosition() const
{
    return position;
}

void particle::setVelocity(const Vector3 &velocity)
{
    particle::velocity = velocity;
}

void particle::setVelocity(const real x, const real y, const real z)
{
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void particle::setAcceleration(const Vector3 &acceleration)
{
    particle::acceleration = acceleration;
}

void particle::setAcceleration(const real x, const real y, const real z)
{
    acceleration.x = x;
    acceleration.y = y;
    acceleration.z = z;
}

void particle::clearAccumulator()
{
    forceAccum.clear();
}

void particle::addForce(const Vector3 &force)
{
    forceAccum += force;
}