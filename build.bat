taskkill /F /IM cemu.exe
make all
pause
rmdir /q /s build
rmdir /q /s -p
del *.elf