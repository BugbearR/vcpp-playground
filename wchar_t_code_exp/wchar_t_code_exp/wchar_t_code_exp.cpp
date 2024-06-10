#include <iostream>

void dump(const char* p)
{
    char c;
    for (const char* pw = p; (c = *pw) != '\0'; pw++)
    {
        std::cout << (int)c << " ";
    }
    std::cout << std::endl;
}

void dump(const wchar_t* p)
{
    wchar_t c;
    for (const wchar_t* pw = p; (c = *pw) != L'\0'; pw++)
    {
        std::cout << (int)c << " ";
    }
    std::cout << std::endl;
}

int main()
{
    dump("Hello");
    dump("こんにちは");
    dump("안녕하세요");
    dump("𠀋😀");

    dump(L"Hello");
    dump(L"こんにちは");
    dump(L"안녕하세요");
    dump(L"𠀋😀");
    return 0;
}
