#ifndef OFFSETS_H
#define OFFSETS_H

struct Offsets
{
    /* These are just examples
    DWORD isPlayerUpdate = 0xF80A78; // Update (Player)
    DWORD isFPSMovement  = 0x14; // fpsMovement (LocalPlayer)
    */

    // antiban
    DWORD createString = 0x159903C;
    DWORD cheatDetectedBanner = 0x1064BB0;
    DWORD clearProgress = 0x1064BB8;
    DWORD showClearProgress = 0x1064C80;
    DWORD awakeCheat = 0x1064FF4;
    DWORD updateCheat = 0x1065354;
    DWORD get_cheaterConfig = 0xEBBF84;
    DWORD set_cheaterConfig = 0xEBEE70;
    DWORD checkSig = 0x13D022C;
    DWORD coinThreshold = 0x13D0234;
    DWORD gemThreshold = 0x13D023C;

    // removed weapons
    DWORD removedWeaponNames = 0xACC234;
    DWORD removedWeaponString = 0xAF647C;

    // currency
    DWORD addCoins = 0xB01E10;
    DWORD addGems = 0xB01F7C;
    DWORD addTickets = 0xB018D8;
    DWORD addEventCurrency = 0xB01AEC;
    DWORD setInt = 0xCA07C0;

    // misc
    DWORD polygonEnabled = 0xA8DF54;
    DWORD SetApp = 0x71DCEC;
    DWORD InternetChecker = 0x188716C;
    DWORD SelectPhotonAppId = 0xCD8798;
    DWORD IsDeveloperBuild = 0x12A4C8C;
};

Offsets *offsets;

#endif
