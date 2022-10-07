/**
 * @file particle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef nuclear_PARTICLE_H
#define nuclear_PARTICLE_H

#include "core.h"
 
 namespace nuclear {

    /**
    * A particle is the simplest object that can be simulated in the
    * physics system.
    *
    * It has position data (no orientation data), along with
    * velocity. It can be integrated forward through time, and have
    * linear forces, and impulses applied to it. The particle manages
    * its state and allows access through a set of methods.
    */

    class particle
    {
        protected:

            /**
            * Holds the linear position of the particle in
            * world space.
            */
            Vector3 position;

            /**
            * Holds the linear velocity of the particle in
            * world space.
            */
            Vector3 velocity;

            /**
            * Holds the acceleration of the particle. This value
            * can be used to set acceleration due to gravity (its primary
            * use), or any other constant acceleration.
            */
            Vector3 acceleration;
            /**
             * The accumulated force to be applied at next simulation
             * step and is zeroed at evert integration step. 
             */
            Vector3 forceAccum;

            /**
            * Holds the amount of damping applied to linear
            * motion. Damping is required to remove energy added
            * through numerical instability in the integrator.
            */
            real damping;

            /**
            * Holds the inverse of the mass of the particle. It
            * is more useful to hold the inverse mass because
            * integration is simpler, and because in real time
            * simulation it is more useful to have objects with
            * infinite mass (immovable) than zero mass
            * (completely unstable in numerical simulation).
            */
            real inverseMass;
        
        public:

            /**
            * Integrates the particle forward in time by the given amount.
            * This function uses a Newton-Euler integration method, which is a
            * linear approximation to the correct integral. For this reason it
            * may be inaccurate in some cases.
            */
            void integrate(real duration);
            
            /** Claers the forces and reset the integrator**/
            void clearAccumulator ();
            
            /**
             * @brief Set the Mass object
             * 
             * @param mass 
             */
            void setMass(const real mass);

            /**
             * @brief Set the Inverse Mass object
             * 
             * @param inverseMass 
             */
            void setInverseMass(const real inverseMass);

            /**
             * @brief Set the Damping object
             * 
             * @param damping 
             */
            void setDamping(const real damping);

            /**
             * @brief Set the Position object
             * 
             * @param position 
             */
            void setPosition(const Vector3 &position);

            /**
             * @brief Set the Position object
             * 
             * @param x 
             * @param y 
             * @param z 
             */
            void setPosition(const real x, const real y, const real z);

            /**
             * Fills the given vector with the position of the particle.
             *
             * @param position A pointer to a vector into which to write
             * the position.
             */
            void getPosition(Vector3 *position) const;

            /**
             * Gets the position of the particle.
             *
             * @return The position of the particle.
             */
            Vector3 getPosition() const;
            
            /**
             * @brief Set the Velocity object
             * 
             * @param velocity 
             */
            void setVelocity(const Vector3 &velocity);

            /**
             * @brief Set the Velocity object
             * 
             * @param x 
             * @param y 
             * @param z 
             */
            void setVelocity(const real x, const real y, const real z);

            /**
             * @brief Set the Acceleration object
             * 
             * @param acceleration 
             */
            void setAcceleration(const Vector3 &acceleration);

            /**
             * @brief Set the Acceleration object
             * 
             * @param x 
             * @param y used for -g force for gravity pull.
             * @param z 
             */
            void setAcceleration(const real x, const real y, const real z);
            /**
             * Clears the forces applied to the particle. This will be
             * called automatically after each integration step.
             */
            

            /**
             * Add given force to be applied to next iteration.
             */
            void addForce(const Vector3 &force);
           
    };
 }

 #endif nuclear_PARTICLE_H