rem : cd to the dir in which the bat file resides
cd /d %~dp0

rem :delete the Lib dir 
rd /s /q 	.\Lib\
mkdir 		.\Lib\
copy 		..\..\..\..\..\Products\eBankMidwareV2\Trunk\Output\Windows\Lib\*.lib Lib\
copy 		..\..\..\..\..\Products\eBankMidwareV2\Trunk\Output\Windows\Lib\*.pdb Lib\

rem : bin dir
rd /s /q 	.\Bin\
mkdir		.\Bin\
xcopy /e /h ..\..\..\..\..\Products\eBankMidwareV2\Trunk\Output\Windows\Bin\MidwareProxy*.exe Bin\

rem :delete the Lib dir
rd /s /q 	.\Include\
mkdir 		.\Include\
xcopy /e /h ..\..\..\..\..\Products\eBankMidwareV2\Trunk\Modules\Include Include\
