# jcWB
An ultra light weight cross-platform web browser using FLTK and C++.  The idea is to not attempt to replace Edge, Chrome, Firefox etc. as a 1st class browser for current platforms, but give a fast and lightweight current browser for older platforms such as SGI/IRIX.

## Project Goals
* Very little footprint to afford a fast browsing experience on lowerend machines
* Minimal featureset to focus on browsing only

## Compiling
* Requires FLTK (www.fltk.org), make sure to have libX11 (sudo apt-get install libx11-dev)
* Requires Curl (https://curl.haxx.se/download.html)

## Roadmap
### 0.1 Release
* Basic UI for the Browser (Window, Menu, Action Buttons)
* Rendering Text Files and HTML Text Content

### 0.2 Release
* Support for Tabs
* HTML 2.0 Compliant Rendering

### 0.3 Release
* Bookmark Support
* HTML 3.2 Compliant Rendering

### 0.4 Release
* Ability to Save Page Content to Disk
* HTML 4.0 Compliant Rendering

### 0.5 Release
* Initial rendering of CSS

### 0.6 Release
* CSS rendering

### 0.7 Release
* Initial work on JavaScript

### 0.8 Release
* JavaScript Support
