## SDL2 Game Setup

### Windows & mingw

1. Download and extract [SDL2-devel-2.30.2-mingw.zip](https://github.com/libsdl-org/SDL/releases/tag/release-2.30.2).
2. Move folder `SLD2` from downloaded `release-2.30.2/i686-w64-mingw32/include` to project `SDL2Game/include` path.
3. Move all files from `release-2.30.2/i686-w64-mingw32/lib` directory to project `SDL2Game/lib` path.
4. Follow the steps to install [MSYS2](https://www.msys2.org/).
5. Remember to install gcc and make:

    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc make
    ```

6. Add to Environment Variable Path value `C:\msys64\ucrt64\bin`.
7. Start the project by going to the `SDL2Game` folder building the project via `make` and running exec file.

    ```bash
    cd SDL2Game/
    make
    ./main.exe
    ```
