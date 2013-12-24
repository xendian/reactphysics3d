/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2013 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

#ifndef REACTPHYSICS3D_FLUID_H
#define REACTPHYSICS3D_FLUID_H

// Libraries
#include "../mathematics/Vector3.h"
#include <vector>

/// Namespace ReactPhysics3D
namespace reactphysics3d {

// Structure FluidParticle
/**
 * This structure represents particle of a fluid.
 */
struct FluidParticle {

    // -------------------- Attributes -------------------- //

    /// Position of the particle
    Vector3 position;

    /// Velocity of the particle
    Vector3 velocity;

};

// Class Fluid
/**
 * This class represents a fluid made of several particles.
 */
class Fluid {

    private:

        // -------------------- Attributes -------------------- //

        /// World-space fluid dimensions in the x, y, z directions
        Vector3 mDimension;

        /// Center position of the fluid in world-space coordinates
        Vector3 mPosition;

        /// Number of partices in the fluid
        uint32 mNbParticles;

        /// True if the simulation of this fluid is enabled, false otherwise
        bool mIsActive;

        /// Array with all the partices of the fluid
        // TODO : Do not use a std::vector here but replace with C-array using rp3d memmory
        //        allocator
        std::vector<FluidParticle> mParticles;

        /// Mass of each particle in the fluid
        // TODO : Initialize this value
        decimal mMassParticle;

    public:

        // -------------------- Methods -------------------- //

        /// Constructor
        Fluid(Vector3 position, Vector3 dimension);

        /// Destructor
        ~Fluid();

        /// Return the number of particles in the fluid
        uint32 getNbParticles() const;

        // -------------------- Friendship -------------------- //

        friend class FluidSolver;

};

// Return the number of particles in the fluid
inline uint32 Fluid::getNbParticles() const {
    return mNbParticles;
}

}

#endif
