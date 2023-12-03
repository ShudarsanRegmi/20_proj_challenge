@echo off

echo Compiling hangman.c...
gcc -c hangman.c -o hangman.o

if %errorlevel% neq 0 (
  echo Error compiling hangman.c
  goto end
)

echo Compiling essentialfunc.c...
gcc -c essentialfunc.c -o essentialfunc.o

if %errorlevel% neq 0 (
  echo Error compiling essentialfunc.c
  goto end
)

echo Compiling main.c...
gcc -c main.c -o main.o

if %errorlevel% neq 0 (
  echo Error compiling main.c
  goto end
)

echo Linking object files...
gcc hangman.o essentialfunc.o main.o -o main.exe

if %errorlevel% neq 0 (
  echo Error linking object files
  goto end
)

echo Installation successful!

del hangman.o essentialfunc.o main.o
timeout /t 3

:end
