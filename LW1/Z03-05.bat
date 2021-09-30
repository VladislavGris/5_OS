@echo off
echo -- строка параметорв: %*
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3

if "%3" == "+" (
    set /a result = %1 + %2
)
if "%3" == "-" (
    set /a result = %1 - %2
)
if "%3" == "*" (
    set /a result = %1 * %2
)
if "%3" == "/" (
    set /a result = %1 / %2
)
echo результат: %result%