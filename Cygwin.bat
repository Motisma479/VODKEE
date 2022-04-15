@echo off
setlocal enableextensions
set TERM=
cd /d "%~dp0bin" && .\bash --login -i && cd ../../VODKEE-V.0.1/ && make && ./Vodkee.exe
