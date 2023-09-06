// GetConsoleCPExp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <windows.h>

int main()
{
    std::cout << "Hello" << std::endl;
    std::cout << "こんにちは" << std::endl;
    std::cout << "안녕하세요" << std::endl;
    std::cout << "𠀋😀" << std::endl;

    std::wcout << L"Hello" << std::endl;
    std::wcout << L"こんにちは" << std::endl;
    std::wcout << L"안녕하세요" << std::endl;
    std::wcout << L"𠀋😀" << std::endl;

    //::SetConsoleOutputCP(65001);
    //UINT acp = ::GetACP();
    //UINT consoleCP = ::GetConsoleCP();
    //UINT consoleOutputCP = ::GetConsoleOutputCP();

    //std::cout << "ACP:" << acp << std::endl;
    //std::cout << "consoleCP:" << consoleCP << std::endl;
    //std::cout << "consoleOutputCP:" << consoleOutputCP << std::endl;

    ////std::ios_base::sync_with_stdio(false);
    ////std::locale default_loc("");
    ////std::locale::global(default_loc);
    ////std::locale ctype_default(std::locale::classic(), default_loc, std::locale::ctype);
    ////std::wcout.imbue(ctype_default);

    //std::wcout.imbue(std::locale(""));
    //// std::wcout.imbue(std::locale(".65001"));
    //std::wcout << L"あ𠀋😀字" << std::endl;
    return 0;
}
