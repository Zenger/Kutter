@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\Qt\Static\qtbase\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\Qt\Static\qtbase\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\Qt\Static\qtbase\plugins
)
C:\Qt\Static\qtbase\bin\uic.exe %*
EndLocal
