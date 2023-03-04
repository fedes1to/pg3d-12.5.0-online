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

void (*old_expControllerAwake)(void *instance);
void expControllerAwake (void *instance)
{
    if(instance != nullptr)
    {
        addExperience(instance, (int*)(99999));
        addCoins((int*)(99999), (bool*)(true), (int*)(0));
        addGems((int*)(99999), (bool*)(true), (int*)(0));
        addTickets((int*)(99999), (bool*)(true), (int*)(0));
        addEventCurrency((int*)(99999), (bool*)(true), (int*)(0));
    }
    return old_expControllerAwake(instance);
}

void (*old_ServerSettings)(void *instance);
void ServerSettings (void *instance)
{
    if(instance != nullptr)
    {
        useCloud(instance, CreateIl2cppString("7f6f3946-7574-4fe5-8f76-44063c43a103"), (int*)(0));
    }
    return old_ServerSettings(instance);
}

void Hooks()
{
    // ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->isPlayerUpdate), (void *) &PlayerUpdate, (void **) &old_PlayerUpdate);
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->expControllerAwake), (void *) &expControllerAwake, (void **) &old_expControllerAwake);
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->ServerSettings), (void *) &ServerSettings, (void **) &old_ServerSettings);
}

#endif
