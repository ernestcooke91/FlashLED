COPY "..\051REN Bootloader PeripheralControl\Obj\051REN_F1_BOOT.hex" "..\HEXFILES\" /Y
COPY ".\Obj\051REN_F1_APP.hex" "..\HEXFILES\" /Y
cd ..\HEXFILES
wscript .\F1-combineHexFiles.vbs