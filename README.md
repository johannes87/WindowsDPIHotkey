Set Windows DPI ("Make everything bigger" in system settings) with keyboard shortcuts.

Tested in Windows 10 Version 2004

# Installation
- Create a directory "bin" in your Users folder (/Users/YourName), and put SetDPI.exe there
	- Alternatively, compile SetDPI.cpp with Visual Studio. Community 2019 works.
- Install [AutoHotkey](https://www.autohotkey.com/)
- Copy `Startup.ahk` to your autostart folder

# Usage

The default hotkeys are CTRL+ALT+j, CTRL+ALT+k and CTRL+ALT+l for 100DPI, 175DPI and 200DPI, respectively.

Modify `Startup.ahk` if you want to change this.

# Notes

Doesn't work with a multi-monitor setup.
Check out the repository https://github.com/lihas/windows-DPI-scaling-sample for more information
Most of the code is based on this repository. Thanks for the research!
