@echo off




cl src/*.c externel/raylib/raylibdll.lib externel/raylib/raylib.lib /Fe:main.exe 
del *.obj
start main.exe