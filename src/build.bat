if exist "./build" (
    del /s /q "./build" & echo build directory cleared.
) else (
    mkdir build & echo build directory created.
)
if not exist "./build" (
    echo build directory is not created, return from bat. & exit
)
cd build
cmake .. -G "MinGW Makefiles"
make

pause
