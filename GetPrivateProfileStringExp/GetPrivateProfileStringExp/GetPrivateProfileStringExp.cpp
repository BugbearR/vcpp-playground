// GetPrivateProfileStringExp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// #include <WinBase.h>

#include <cstdlib>
#include <iostream>
#include <codecvt>

#include <windows.h>

int wmain(int argc, wchar_t *argv[])
{
    if (argc < 2)
    {
        return EXIT_FAILURE;
    }
    UINT cp = GetConsoleCP();
    UINT outputCp = GetConsoleOutputCP();
    // std::locale utf8(std::locale::classic(), new std::codecvt_utf8_utf16<WCHAR, 0x10ffff, std::codecvt_mode::generate_header>());
    std::wcout.imbue(std::locale(".65001"));
    std::cout << "ConsoleCP:" << cp << std::endl;
    std::cout << "ConsoleOutputCP:" << outputCp << std::endl;

    for (int i = 0; argv[1][i] != L'\0'; i++) {
        std::cout << std::hex << (int)(argv[1][i]) << std::endl;
    }
    // std::wcout.imbue(std::locale("C.UTF-8"));
    std::wcout << argv[1] << std::endl;

    return EXIT_SUCCESS;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
