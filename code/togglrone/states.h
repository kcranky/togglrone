#ifndef STATES_H
#define STATES_H


enum state {
  ST_STARTUP,
  ST_PROJECTS, // Shows the projects
  ST_ITEMS,    // Shows the previously tracked items in a give project
  ST_TRACKING, // The tracking time screen
  ST_ERROR     // System error screen
};

extern state currentState;
extern int totalProjects;

//void setState(state st);
//const state getState();

void enterProjects();
void enterItems(int const& project);

#endif
