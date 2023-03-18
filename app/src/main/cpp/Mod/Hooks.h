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

void (*old_InternetChecker)(void *instance);
void InternetChecker (void *instance) {
    if(instance != nullptr) {
        LOGDEBUG("Changing Currency");
        setInt(CreateIl2cppString("currentLevel1"), 0, false);
        setInt(CreateIl2cppString("currentLevel70"), 1, false);
        setInt(CreateIl2cppString("currentLevel"), 70, false);
        setInt(CreateIl2cppString("Coins"), 13371337, false);
        setInt(CreateIl2cppString("GemsCurrency"), 69420, false);
    }
    return old_InternetChecker(instance);
}

monoString* (*old_SelectPhotonAppId)(void* HiddenSettings);
monoString* SelectPhotonAppId (void* HiddenSettings) {
    return CreateIl2cppString("1f1bb08d-1c91-443e-b7d2-e4300850c1cf");
}

void Hooks()
{
    // ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->isPlayerUpdate), (void *) &PlayerUpdate, (void **) &old_PlayerUpdate);
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->SelectPhotonAppId), (void *) &SelectPhotonAppId, (void **) &old_SelectPhotonAppId);
    ARMPatch::hook((void *) getAbsoluteAddress(LibraryToLoad, offsets->InternetChecker), (void *) &InternetChecker, (void **) &old_InternetChecker);
}

#endif
