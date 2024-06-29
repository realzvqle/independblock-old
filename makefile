



window:
	cl src/*.c externel/raylib/raylibdll.lib externel/raylib/raylib.lib /Fe:main.exe 
	rm *.obj
	main.exe