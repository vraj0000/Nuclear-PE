#include<stdio.h>
#include"../../include/nuclear/nuclear.h"
#include"app.h"

class bullistic : public Application
{
    private:
        enum ShotType
        {
            UNUSED = 0,
            PISTOL,
            ARTILLERY,
            FIREBALL,
            LASER
        };

        struct ammoround
        {
            nuclear::particle firearm;
            ShotType type;
            unsigned startTime;
        };
        const static unsigned ammoRounds = 16;
        ammoround ammo[ammoRounds];
        ShotType currentShotType;

    public:
    bullistic();
    virtual void key(int key);
    virtual void update();

        
};

bullistic::bullistic()
: currentShotType(LASER)
{
    printf("Creating ballistic \n");
    // Make all shots unused
    for (ammoround *shot = ammo; shot < ammo+ammoRounds; shot++)
    {
        shot->type = UNUSED;
    }
}

void bullistic::key (int key)
{
    printf("Entering Key in Ballistic %d\n", key);

    switch(key)
    {
    case 1: currentShotType = PISTOL; break;
    case 2: currentShotType = ARTILLERY; break;
    case 3: currentShotType = FIREBALL; break;
    case 4: currentShotType = LASER; break;
    }
    printf("exiting Key in Ballistic %d \n", currentShotType);
}

void bullistic::update ()
{
    nuclear::real duration = 0.017;
    for (ammoround *shot = ammo; shot < ammo+ammoRounds; shot++)
    {
        if (shot->type != UNUSED)
        {
            // Run the physics
            shot->firearm.integrate(duration);
            printf("%f %f %f %f \n", (shot->firearm.getPosition()).x, (shot->firearm.getPosition()).y, (shot->firearm.getPosition()).z, duration);

            // Check if the particle is now invalid
            if (shot->firearm.getPosition().y < 0.0f ||
                shot->firearm.getPosition().z > 200.0f)
            {
                // We simply set the shot type to be unused, so the
                // memory it occupies can be reused by another shot.
                shot->type = UNUSED;
            }
        }
    }
}

Application* getapp()
{
    printf("Getting ballistic \n");
    return new bullistic();
}
