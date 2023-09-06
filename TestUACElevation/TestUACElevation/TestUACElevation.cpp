// TestUACElevation.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

void putByJson(BOOL isAdministrator, TOKEN_ELEVATION elevation, TOKEN_ELEVATION_TYPE elevationType)
{
    printf("{ \"isAdministratord\": %s", (isAdministrator) ? "true" : "false");
    printf(", \"isElevated\": %s", (elevation.TokenIsElevated) ? "true" : "false");
    const char* pElevationTypeStr = NULL;
    switch (elevationType)
    {
    case TokenElevationTypeDefault:
        pElevationTypeStr = "default";
        break;
    case TokenElevationTypeFull:
        pElevationTypeStr = "full";
        break;
    case TokenElevationTypeLimited:
        pElevationTypeStr = "limited";
        break;
    default:
        pElevationTypeStr = "unknown";
    }
    printf(", \"elevationType\": \"%s\" }\n", pElevationTypeStr);
}

void putByCode(BOOL isAdministrator, TOKEN_ELEVATION elevation, TOKEN_ELEVATION_TYPE elevationType)
{
    printf("%s", (isAdministrator) ? "1" : "0");
    printf("\t%s", (elevation.TokenIsElevated) ? "1" : "0");
    const char* pElevationTypeStr = NULL;
    switch (elevationType)
    {
    case TokenElevationTypeDefault:
        pElevationTypeStr = "1";
        break;
    case TokenElevationTypeFull:
        pElevationTypeStr = "2";
        break;
    case TokenElevationTypeLimited:
        pElevationTypeStr = "3";
        break;
    default:
        pElevationTypeStr = "0";
    }
    printf("\t%s\n", pElevationTypeStr);
}

BOOL isAdminitrator()
{
    SID_IDENTIFIER_AUTHORITY authority = SECURITY_NT_AUTHORITY;
    PSID adminGroup = NULL;
    BOOL isMember;

    if (!::AllocateAndInitializeSid(
        &authority, 2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0, &adminGroup))
    {
        return FALSE;
    }

    if (!::CheckTokenMembership(NULL, adminGroup, &isMember))
    {
        ::FreeSid(adminGroup);
        return FALSE;
    }


    ::FreeSid(adminGroup);

    return isMember;
}

int main(int argc, char *argv[])
{
    HANDLE hToken;
    TOKEN_ELEVATION elevation;
    TOKEN_ELEVATION_TYPE elevationType;
    DWORD cb;

    ::OpenProcessToken(GetCurrentProcess(), GENERIC_READ, &hToken);

    ::GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &cb);

    ::GetTokenInformation(hToken, TokenElevationType, &elevationType, sizeof(elevationType), &cb);

    BOOL isAdministratorFlag = isAdminitrator();

    if (argc >= 2 && strcmp(argv[1], "json") == 0)
    {
        putByJson(isAdministratorFlag, elevation, elevationType);
    }
    else
    {
        putByCode(isAdministratorFlag, elevation, elevationType);
    }

    ::CloseHandle(hToken);

    return 0;
}
