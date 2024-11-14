Welcome to the Group 5 - Go Game.

Here are a few things to know when developing:
1. Do not modify SDL_Plotter.h or SDL_Plotter.cpp.
--Dr. Booth will use an unmodified version of these files, so our development should reflect that.

2. Use a new specific branch for your development. When you are done, create a pull request for your branch into main.

3. Each branch name should reflect the task on linear.
Ex: Linear task(GO-123) "Test Function" would have "feature/go-123-test-function" as its branch name

_____________________________________________________________________________

Settings.txt
-Default version is created at the start of the application
-Options stage modifies it using the createSettingsFile() in helpers.h
-playMatch() in stages.h extracts the information
