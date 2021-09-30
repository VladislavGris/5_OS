@echo off

echo -- строка параметорв: %*
echo -- режим: %1
echo -- имя файла: %2

if "%1" == "" (
    echo ---+ %~n0 режим файл
    echo ---++ режим = {создать, удалить}
    echo ---++ файл = имя файла
    goto end
)
if "%2" == "" (
    echo ---+ не задано имя файла
    goto end
)
set /a flag = 0
if "%1" == "удалить" (
    set /a flag = 1
)
if "%1" == "создать" (
    set /a flag = 1
)
if %flag% == 0 (
    echo ---+ режим задан не корректно
    goto end
)
if exist %2 (
    if "%1" == "удалить" (
        del %2
        echo ---+ файл %2 удален
    ) else (
        echo ---+ файл %2 уже существует
    )
) else (
    if "%1" == "удалить" (
        echo ---+ файл %2 не найден
    ) else (
        copy NUL %2
        echo ---+ файл %2 создан
    )
)
:end