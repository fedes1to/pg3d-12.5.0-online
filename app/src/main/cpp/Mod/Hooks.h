#ifndef HOOKS_H
#define HOOKS_H

#include "Functions.h"

/*
void (*old_PlayerUpdate)(void *instance);
void PlayerUpdate (void *instance)
{
    if(instance != nullptr)
    {
        void *isLocalPlayer = *(void **)((uint64_t) instance + offsets->isLocalPlayer);

        *(int *)((uint64_t) instance + offsets->isKills) = 99999;

        *(int *)((uint64_t) instance + offsets->isDeaths) = 99999;

        if(isLocalPlayer != nullptr)
        {

            void *isFPSMovement = *(void **)((uint64_t) isLocalPlayer + offsets->isFPSMovement);

            SetWeapon(isLocalPlayer, 2); // Vector SMG

            if(isFPSMovement != nullptr)
            {
                *(bool *)((uint64_t) isFPSMovement + offsets->isFly) = true;
            }

        }

    }

    return old_PlayerUpdate(instance);
}
*/

void (*old_UIRoot)(void *instance);
void UIRoot (void *instance)
{
    if(instance != nullptr)
    {
        // set cloud here
        useCloud(ServerSettings(), CreateIl2cppString("1f1bb08d-1c91-443e-b7d2-e4300850c1cf"), 0);
        setInt(CreateIl2cppString("currentLevel1"), 0, false);
        setInt(CreateIl2cppString("currentLevel70"), 1, true);
        setInt(CreateIl2cppString("currentLevel"), 70, true);
        addCoins(9999, true, 0);
        addGems(9999, true, 0);
        addTickets(9999, true, 0);
        addEventCurrency(9999, true, 0);
    }
    return old_UIRoot(instance);
}

void Hooks()
{
    // ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->isPlayerUpdate), (void *) &PlayerUpdate, (void **) &old_PlayerUpdate);
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->UIRoot), (void *) &UIRoot, (void **) &old_UIRoot);
}

#endif
