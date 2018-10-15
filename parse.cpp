//File parsing example

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "image.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>


#define STB_IMAGE_IMPLEMENTATION //only place once in one .cpp file
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION //only place once in one .cpp files
#include "stb_image_write.h"

using namespace std;

int main(){
  FILE *fp;
  long length;
  char line[1024]; //Assumes no line is longer than 1024 characters!
  int width = 640;
  int height = 480;
  float r,g,b=0;
  float px,py,pz=0;
  float dx,dy=0;
  float dz=1;
  float ux=1,uy=0,uz=1,ha=45;


  string fileName = "spheres1.scn";

  // open the file containing the scene description
  fp = fopen(fileName.c_str(), "r");

  // check for errors in opening the file
  if (fp == NULL) {
    printf("Can't open file '%s'\n", fileName.c_str());
	return 0;  //Exit
  }

  // determine the file size (this is optional -- feel free to delete the 4 lines below)
  fseek(fp, 0, SEEK_END); // move position indicator to the end of the file;
  length = ftell(fp);  // return the value of the current position
  printf("File '%s' is %ld bytes long.\n\n",fileName.c_str(),length);
  fseek(fp, 0, SEEK_SET);  // move position indicator to the start of the file

  //Loop through reading each line
  while( fgets(line,1024,fp) ) { //Assumes no line is longer than 1024 characters!
    if (line[0] == '#'){
      printf("Skipping comment: %s", line);
      continue;
    }

    char command[100];
    int fieldsRead = sscanf(line,"%s ",command); //Read first word in the line (i.e., the command type)

    if (fieldsRead < 1){ //No command read
     //Blank line
     continue;
    }

    if (strcmp(command, "sphere")==0){ //If the command is a sphere command
       float x,y,z,r;
       sscanf(line,"sphere %f %f %f %f", &x, &y, &z, &r);
       printf("Sphere as position (%f,%f,%f) with radius %f\n",x,y,z,r);
    }//camera -6 2 -4 .77 0 .64 0 1 0 35
    if (strcmp(command, "camera")==0){ //If the command is a camera command
       sscanf(line,"camera %f %f %f %f %f %f %f %f %f ", &px, &py, &pz, &dx,&dy,&dz,&ux,&uy,&uz,&ha);
    }
    else if (strcmp(command, "background")==0){ //If the command is a background command
       sscanf(line,"background %f %f %f", &r, &g, &b);
    }
    else if (strcmp(command, "output_image")==0){ //If the command is an output_image command
       char outFile[1024];
       sscanf(line,"output_image %s", outFile);
       printf("Render to file named: %s\n", outFile);
    }
	else if (strcmp(command, "film_resolution") == 0) { //If the command is an output_image command
		sscanf(line, "film_\resolution %d%d",&width,&height);
	}
	else if (strcmp(command, "camera") == 0) { //If the command is an output_image command


	}
    else {
      printf("WARNING. Do not know command: %s\n",command);
    }
  }
  Image picture = Image(width, height);
  picture.changebackground(r,g,b);
  printf("Background color of (%f,%f,%f)\n",r,g,b);
  printf("camera %f,%f,%f,%f,%f,%f,%f,%f,%f ", px, py, pz, dx,dy,dz,ux,uy,uz,ha);

  picture.Write("RATRACY.JPG");

  return 0;
}
