rem @echo off

set TARGOS=win32
set MACH=i386
set LIBEXECDIR="\"C:/pcc/libexec\""

set BASEDIR=..\..
set MIPDIR=%BASEDIR%\mip
set CPPDIR=%BASEDIR%\cc\cpp
set CCOMDIR=%BASEDIR%\cc\ccom
set CCDIR=%BASEDIR%\cc\cc
set OSDIR=%BASEDIR%\os\%TARGOS%
set MACHDIR=%BASEDIR%\arch\%MACH%
set BISON_SIMPLE=bison.simple

set CPPFLAGS=-DWIN32 -DTARGOS=%TARGOS% -Dos_%TARGOS% -Dmach_%MACH% -DLIBEXECDIR=%LIBEXECDIR%

cl %CPPFLAGS% /I%CCDIR% /I. /I%MACHDIR% /I%MIPDIR% %CCDIR%\cc.c %MIPDIR%\compat.c

bison -y -t -d --no-lines %CPPDIR%\cpy.y
flex %CPPDIR%\scanner.l
cl %CPPFLAGS% /I%CPPDIR% /I%OSDIR% /I%MACHDIR% /I%MIPDIR% %CPPDIR%\cpp.c %MIPDIR%\compat.c y.tab.c lex.yy.c "C:\Program Files\UnxUtils\lib\libfl.lib"


cl -DMKEXT %CPPFLAGS% /I%CCOMDIR% /I%OSDIR% /I%MACHDIR% /I%MIPDIR% %MIPDIR%\mkext.c %MACHDIR%\table.c %MIPDIR%\common.c
mkext
bison -y -t -d --no-lines %CCOMDIR%\cgram.y
move y.tab.c cgram.c
move y.tab.h cgram.h
flex %CCOMDIR%\scan.l
move lex.yy.c scan.c

cl /Feccom.exe %CPPFLAGS% /I%CCOMDIR% /I%OSDIR% /I%MACHDIR% /I%MIPDIR% %CCOMDIR%\main.c %MIPDIR%\compat.c scan.c cgram.c external.c %CCOMDIR%\optim.c %CCOMDIR%\pftn.c %CCOMDIR%\trees.c %CCOMDIR%\inline.c %CCOMDIR%\symtabs.c %CCOMDIR%\gcc_compat.c %CCOMDIR%\init.c %MACHDIR%\local.c %MACHDIR%\code.c %CCOMDIR%\stabs.c %MIPDIR%\match.c %MIPDIR%\reader.c %MIPDIR%\optim2.c %MIPDIR%\regs.c %MACHDIR%\local2.c %MACHDIR%\order.c %MACHDIR%\table.c %MIPDIR%\common.c "C:\Program Files\UnxUtils\lib\libfl.lib"

md "C:\pcc"
md "C:\pcc\bin"
md "C:\pcc\libexec"
copy cc.exe "C:\pcc\bin"
copy cpp.exe "C:\pcc\libexec"
copy ccom.exe "C:\pcc\libexec"
