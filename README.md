# HobbyGameEngine

## 免責事項 
このソフトウェアの使用または使用不可によって、いかなる問題が生じた場合も、著作者はその責任を負いません。バージョンアップや不具合に対する対応の責任も負わないものとします。

## 実行環境
|OS|ビルドツール|コンパイル|
|:---:|:---:|:---:|
|Windows10|CMake|gcc(MinGW64を利用)|

## ThirdParty
- SDL3.0
    - https://github.com/libsdl-org/SDL
    
## ビルド環境構築
- CMakeをインストール
- MinGW64をインストール
- 両方とも以下の動画を参考にしてインストールした
    - https://www.youtube.com/watch?v=dDnfXOz8kY4

## ビルド方法
- VSCodeでビルドする方法
    - 利用したVSCode拡張機能
        - c/c++
            - c/c++とcmakeをvscodeで扱うための拡張機能
                - https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
        - デバッグ
            - VSCodeでデバッグするための拡張機能  
                - https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb
    1. コンパイルするキットをスキャン
        - CMake: Scan for kits
            - コンパイルするキットを一覧を選択するようにした
    1. コンパイルするキットを選択
        - CMake: Select a kit
            - コンパイルするキットを選択
            - GCCのを選ぶ
    1.  ビルド環境構築
        - CMake: Delete Catch and Reconfigure 
        - buildディレクトリをが作成される
    1. SDLのビルド
        - SDL3-sharedをターゲットビルド
        - 最初に一回やるだけでいい
    1. HobbyEngineのビルド
        - HobbyGameをターゲットビルド
    1. 作成したSDLのdllファイルを実行ファイルから参照できるようにインストールする
        - CMake: Installを実行
    1. Gameのビルド
        - Gameにビルドターゲットを設定
        - CMake: Buildを実行
    1. Gameのデバッグ実行
        - CMake: Debugを実行

## 実装して参考にしたサイト
- gccコンパイラでのインクルードガードの方法
    - #pragma one
    - ヘッダーファイルの先頭に上記を入れる事で対応できる
- cmake --install
    - これをやるとcmakeの管理ディレクトリにビルドしたファイルがインストールする
        - インストール先は変える事が出来る
            - https://ryostudy.com/2023/01/21/cmake%e3%81%a7sdl2%e3%82%92%e4%bd%bf%e3%81%86/
    - インストールするとfind_pakcageで関連づける事が出来る
- cmakeの変数名の意味について
    - name_SOURCE_DIRとかが参考になった
        - nameはプロジェクト名とすればプロジェクトのトップのソースディレクトリになるのを知った
        - https://qiita.com/osamu0329/items/7de2b190df3cfb4ad0ca
- cmakeのif分について
    - ファイルが存在するかどうかの書き方で参考になった
            - EXISTS <path> の式で判定できる
        - https://qiita.com/mrk_21/items/49d8802dc63a2791bcc3
- cmakeのConfigファイルの扱い
    - CMakeのコンフィグファイルで定義した内容をヘッダーファイルに出力する方法
        - https://leico.github.io/TechnicalNote/CMake/step2
- SDLの環境構築で参考
    - exeと同じディレクトリにSDLのdllファイルを置かないといけない事に気づいた
        - https://ryostudy.com/2023/01/21/cmake%e3%81%a7sdl2%e3%82%92%e4%bd%bf%e3%81%86/ 
- cmakeで静的ライブラリを作成する方法
    - 静的ライブラリのインクルードファイルの取り込みやインクルードファイルの依存先で公開する方法などこのサイトがなければライブラリの作成は出来なかった
    - cmakeについて基本の使い方の説明があるので一通りみるのをおすすめ
        - https://kamino.hatenablog.com/entry/cmake_tutorial2
- SDLの扱いについて説明している神サイト
    - https://lazyfoo.net/tutorials/SDL/index.php
    
