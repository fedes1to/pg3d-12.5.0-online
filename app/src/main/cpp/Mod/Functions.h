#ifndef FUNCTIONS_H
#define FUNCTIONS_H

monoString* CreateIl2cppString(const char* str)
{
    static monoString* (*CreateIl2cppString)(const char* str) =
    (monoString* (*)(const char* str))(getAbsoluteAddress(LibraryToLoad, offsets->createString));
    return CreateIl2cppString(str);
}

// void (*SetWeapon)(void *instance, int weapon);
void (*addCoins)(int count, bool needIndication, int accrualType);
void (*addGems)(int count, bool needIndication, int accrualType);
void (*addEventCurrency)(int count, bool needIndication, int accrualType);
void (*addTickets)(int count, bool needIndication, int accrualType);
void (*setInt)(monoString* key, int val, bool directWriteForCurrencyMigration);

void Functions() // pointers **
{
    // SetWeapon = (void(*)(void *, int)) offsets->isSetWeapon;
    addCoins = (void(*)(int, bool, int)) (getAbsoluteAddress(LibraryToLoad, offsets->addCoins));
    addGems = (void(*)(int, bool, int)) (getAbsoluteAddress(LibraryToLoad, offsets->addGems));
    addEventCurrency = (void(*)(int, bool, int)) (getAbsoluteAddress(LibraryToLoad, offsets->addEventCurrency));
    addTickets = (void(*)(int, bool, int)) (getAbsoluteAddress(LibraryToLoad, offsets->addTickets));
    setInt = (void(*)(monoString*, int, bool)) (getAbsoluteAddress(LibraryToLoad, offsets->setInt));
}

#endif