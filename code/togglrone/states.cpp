#include "states.h"
#include "hardware.h"

KVReturn projects;
int totalProjects;
state currentState;

void setState(state st){
  currentState = st;
}

const state getState(){
  return currentState;
}

void enterProjects(){
  setState(ST_PROJECTS);
  clearScreen();

  //get single workspace and print projects
  KVReturn workspaces = toggl.getWorkSpaces();
 
  if (workspaces.pairCount > 0) {    
      projects = toggl.getProjects(workspaces.KVPairs[0].id);
      totalProjects = projects.pairCount;
      if (totalProjects > 0) {
        tft.println("==Current Projects==");
        for (int i = 0; i < LINES_ON_SCREEN-1; i++) {
          tft.println("-" + projects.KVPairs[i].name);
          if (i == totalProjects) { // if we have less than 14 projects
            break;
          }    
        }
      }
      else {
        showError("No projects found");
      }  
  }
  else {
    showError("Unable to connect to network");
  }

  generateSelected(0);
  
  delete[] workspaces.KVPairs; // we're done with the workspace KVPairs
  
}

void enterItems(int const& project){
  // clear the screen
  // show recently tracked tasks within the selected project
}
