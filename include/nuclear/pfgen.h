/**
 * @file pfgen.h
 * @author vraj
 * @brief This is a particle force generator that can
 * be asked to add force to one or more particle.
 * 
 * It is using interface in C++.
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"core.h"
#include"particle.h"

namespace nuclear {
    
    class ParticleForceGenerator
    {
        public:

            virtual void updateForce (particle *particle, real duration) ;
    };
}