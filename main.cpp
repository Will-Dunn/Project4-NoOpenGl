//code for initilizing window and drawing pixels was taken from badprog.com and then adapted to help fit my needs
//algorithims for line drawing are my own based on online research
//Goal is for this program to render the rose svg file
//#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

const int width=400;
const int height=700;
 int choice=1;
float slope;
int r=-1;
const bool bigline=false;

#include "point.h"
#include "AlgoLine.h"
#include "AlgoPath.h"
vector<point> Points;
vector<Line> lines;
vector <Path> paths;
char* f;
long totalTime;
char grid[height][width];

void draw_pixel(int x, int y) {

    //glBegin(GL_POINTS);
    //glVertex2f(x, (y));
    grid[y][x]='*';
    //for bigger line thickness
    /*if(bigline){
        for(int i=0;i<100;i++){
        glVertex2f(x+i, y);
        glVertex2i(x-i, y);
        glVertex2i(x, y+i);
        glVertex2i(x, y-i);}

    }

    glEnd();*/
}



void rect(int x,int y,int w,int h){
    int x2= x+w;

    int y2= (y+h);
    y=y;
    Line b(x,y,x2,y);
    b.draw_line();
    lines.push_back(b);
    Line r(x2,y,x2,y2);
    r.draw_line();
    lines.push_back(r);
    Line t(x,y2,x2,y2);
    t.draw_line();
    lines.push_back(t);
    Line l(x,y,x,y2);
    l.draw_line();
    lines.push_back(l);


};


void parsesvg(){

/*ParseSVG loosely parses SVG files and send them to various algorithims to draw lines
* This code probably is the most inefficent thing ever but I could not find a svg parser online that did not just immediatly render the image instead of just
*/
    ifstream file(f);
    string line;
    string li="line";
    //string d="d=";
    string id="id";
    getline(file,line);
    while (!file.eof()){

        if(line.find("path")!= string::npos) {


            Path path(0,0);
            Points.clear();
            while (!file.eof()) {//start file loop
                //M is Move to, picks up the pen and moves cordinates to new location
                if (line.find("M") != string::npos && line.find(id) == string::npos) {
                    float x;
                    float y;

                    //stringstream temp(line);
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x = stof(temp);
                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y = stof(temp);
                    path.Move(x,y);
                    //point t(x, y);
                    //Points.push_back(t);

                }
                //m is Move by, picks up the pen and moves cordinates to new location by dx dy
                if (line.find("m") != string::npos && line.find(id) == string::npos) {
                    float x;
                    float y;

                    //stringstream temp(line);
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x = stof(temp);
                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y = stof(temp);
                    path.move(x,y);
                    //point t(x, y);
                    //Points.push_back(t);

                }
                if (line.find("L") != string::npos && line.find(id) == string::npos) {
                    float x;
                    float y;

                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x = stof(temp);
                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y = stof(temp);
                    path.L(x,y);

                }
                if (line.find("l") != string::npos && line.find(id) == string::npos) {
                    float x;
                    float y;
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);
                    x = stof(temp);
                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);
                    y =  stof(temp);
                    path.l(x,y);

                }
                if (line.find("H") != string::npos && line.find(id) == string::npos) {
                    float x;
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x = stof(temp);

                    path.H(x);

                }
                if (line.find("h") != string::npos && line.find(id) == string::npos&& line.find("path") == string::npos) {
                    float x;


                    //stringstream temp(line);
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x = stof(temp);
                    /*start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])) {
                        end++;
                    }
                    temp = line.substr(start, end - start);


                    y = height - stoi(temp);*/
                    path.h(x);

                }
                if (line.find("V") != string::npos && line.find(id) == string::npos) {
                    int x;
                    int y;

                    //stringstream temp(line);
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    y =stof(temp);

                    path.V(y);

                }
                if (line.find("v") != string::npos && line.find("<") == string::npos) {
                    int x;
                    int y;

                    //stringstream temp(line);
                    int start = 0;
                    int end = 0;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    y = stof(temp);

                    path.v(y);

                }
                if (line.find("Z") != string::npos) {
                    path.Z();
                    //break;
                }
                if(line.find("style")!= string::npos){

                    paths.push_back(path);
                    break;
                }
                else if (line.find("c") != string::npos ) {

                    int start = 0;
                    int end = 0;


                    float x1,y1,x2,y2,x3,y3;
                    //int y;

                    //stringstream temp(line);
                    start = start;
                    end = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x1 = stof(temp);
                    if(line[start-1]=='-'){

                        x1=-x1;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y1 = stof(temp);
                    if(line[start-1]=='-'){

                        y1=-y1;
                    }
//height-
                    point t(path.S.x+x1, path.S.y+y1);
                    //Points.push_back(t);
                    start = end + 1;

                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    x2 = stof(temp);
                    if(line[start-1]=='-'){

                        x2=-x2;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y2 = stof(temp);
                    if(line[start-1]=='-'){
                        y2=-y2;
                    }

                    point t1(path.S.x+x2, path.S.y+y2);

                    start = end + 1;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    x3 = stof(temp);
                    if(line[start-1]=='-'){

                        x3=-x3;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y3 = stof(temp);
                    if(line[start-1]=='-'){
                        y3=-y3;
                    }

                    point t2(path.S.x+x3, path.S.y+y3);
                    path.A=t;
                    path.B=t1;
                    path.C=t2;
                    vector<point> te;
                    path.drawCurve(choice);
                    totalTime+=path.time;
                    paths.push_back(path);

                }
                else if (line.find("C") != string::npos ) {

                    int start = 0;
                    int end = 0;


                    float x1,y1,x2,y2,x3,y3;
                    //int y;

                    //stringstream temp(line);
                    start = start;
                    end = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    string temp = line.substr(start, end - start);

                    x1 = stof(temp);
                    if(line[start-1]=='-'){

                        x1=-x1;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);

                    y1 = stof(temp);
                    if(line[start-1]=='-'){

                        y1=-y1;
                    }

                    point t(path.S.x+x1,path.S.y+ y1);

                    start = end + 1;

                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);


                    x2 = stof(temp);
                    if(line[start-1]=='-'){

                        x2=-x2;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);



                    y2 = stof(temp);
                    if(line[start-1]=='-'){
                        y2=-y2;
                    }

                    point t1(path.S.x+x2, path.S.y+y2);

                    start = end + 1;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);


                    x3 = stof(temp);
                    if(line[start-1]=='-'){

                        x3=-x3;
                    }

                    start = end;
                    while (!isdigit(line[start])) {
                        start++;
                    }

                    end = start;
                    while (isdigit(line[end])||line[end]=='.') {
                        end++;
                    }
                    temp = line.substr(start, end - start);


                    y3 = stof(temp);
                    if(line[start-1]=='-'){
                        y3=-y3;
                    }

                    point t2(path.S.x+x3, path.S.y+y3);
                    path.A=t;
                    path.B=t1;
                    path.C=t2;
                    vector<point> te;
                    path.drawCurve(choice);
                    totalTime+=path.time;
                    paths.push_back(path);

                }


                getline(file, line);}




        }
        if(line.find("rect")!= string::npos){
            int x;
            int y;
            int w;
            int h;
            while (!file.eof()){

                if(line.find("x")!= string::npos&&line.find(id)== string::npos){
                    //cout<<line<<endl;
                    //stringstream temp(line);
                    int start=0;
                    int end=0;
                    while (line[start]!='"'){
                        start++;
                    }
                    start+=1;
                    end=start;
                    while (line[end]!='"'){
                        end++;
                    }
                    string temp=line.substr(start,end-start);
                    //cout<<temp<<endl;
                    x=stoi(temp);}
                else if(line.find("y")!= string::npos&&line.find(id)== string::npos){
                    //cout<<line<<endl;
                    //stringstream temp(line);
                    int start=0;
                    int end=0;
                    while (line[start]!='"'){
                        start++;
                    }
                    start+=1;
                    end=start;
                    while (line[end]!='"'){
                        end++;
                    }
                    string temp=line.substr(start,end-start);
                    //cout<<temp<<endl;
                    y=stoi(temp);}

                else if(line.find("width")!= string::npos){

                    //stringstream temp(line);
                    int start=0;
                    int end=0;
                    while (line[start]!='"'){
                        start++;
                    }
                    start+=1;
                    end=start;
                    while (line[end]!='"'){
                        end++;
                    }
                    string temp=line.substr(start,end-start);

                    w=stoi(temp);

                }
                else if(line.find("height")!= string::npos&&line.find(id)== string::npos){

                    //stringstream temp(line);
                    int start=0;
                    int end=0;
                    while (line[start]!='"'){
                        start++;
                    }
                    start+=1;
                    end=start;
                    while (line[end]!='"'){
                        end++;
                    }
                    string temp=line.substr(start,end-start);

                    h=stoi(temp);
                    break;}



                getline(file,line);
                //stringstream data(line);
            }
            rect(x,y,w,h);

        }
        line="";
        getline(file,line);

    }
    cout<<"finished Parsing"<<endl;
}
void mySVGDisplay() {
    parsesvg();
    cout<<"TIME: "<<totalTime<<endl;
    for(int i=0;i<lines.size();i++){
        for(int p=0;p<lines[i].points.size();p++){
            draw_pixel(lines[i].points[p].x,lines[i].points[p].y);
        }
    }
    for(int i=0;i<paths.size();i++){
        for(int p=0;p<paths[i].points.size();p++){
            draw_pixel(paths[i].points[p].x,paths[i].points[p].y);
        }
    }

    //glFlush();
}
void customCurves(int S){
    float x=rand()%500;
    float y=rand()%700;
    Path T(x,y);
    Path D(x,y);
    vector<point> pts;
    for(int i =0;i<S;i++){
        pts.push_back(point(rand()%500,rand()%700));
        //cout<<"runs"<<endl;
    }

    T.drawCurve(pts,1);
    D.drawCurve(pts,0);
    totalTime+=T.time;
    cout<<"Naive: "<<T.time<< " VS De Casteljau's "<<D.time<<"diffrence: "<<D.time-T.time<<endl;
    paths.push_back(D);

}
void myDisplay() {
    //parsesvg();
    string inp;
    cout<<"enter curve size: "<<endl;
    cin>>inp;
    int curveSize=stoi(inp);
    customCurves(curveSize);
    cout<<"TIME: "<<totalTime<<endl;
    for(int i=0;i<lines.size();i++){
        for(int p=0;p<lines[i].points.size();p++){
            draw_pixel(lines[i].points[p].x,lines[i].points[p].y);
        }
    }
    for(int i=0;i<paths.size();i++){
        for(int p=0;p<paths[i].points.size();p++){
            draw_pixel(paths[i].points[p].x,paths[i].points[p].y);
        }
    }

    //glFlush();
}
int main(int argc, char **argv) {
    f=argv[1];
    cout<<argc<<endl;
    //parsesvg();
    //to run custom graphs  change argument 3 to y
    if(argc>4){
    if(argv[3][0]=='y') {
        string inp;
        cout << "enter 1 for naive or 0 for complex" << endl;
        cin >> inp;
        choice = stoi(inp);
        cout << "enter  1 for svg/ 2 for random curve of user defined size" << endl;
        cin >> inp;

        int choice2 = stoi(inp);

        if (choice2 == 1) {


            //glutInit(&argc, argv);
            //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

            //glutInitWindowSize(width, height);

            //glutInitWindowPosition(0, 0);
            //glutCreateWindow("Algo Project 4");
            //myInit();
            mySVGDisplay();
            //glutDisplayFunc();
            //glutMainLoop();
        } else if (choice2 == 2) {


            /*glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

            glutInitWindowSize(width, height);

            glutInitWindowPosition(0, 0);
            glutCreateWindow("Algo Project 4");
            myInit();
            glutDisplayFunc(myDisplay);
            glutMainLoop();*/
            myDisplay();
        }
        fstream file(argv[1]);
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]!='*'){
                    grid[i][j]=' ';
                }
                file<<grid[i][j];
            }
            file<<endl;
        }
    }}
    else{

        choice=1;
        mySVGDisplay();
        fstream file(argv[2]);
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]!='*'){
                    grid[i][j]=' ';
                }
                file<<grid[i][j];
            }
            file<<endl;
        }
        choice=0;
        mySVGDisplay();
        fstream file1(argv[3]);
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]!='*'){
                    grid[i][j]=' ';
                }
                file1<<grid[i][j];
            }
            file1<<endl;
        }
    }

   // else{
    /*        //parsesvg();
        for(int i=0;i<paths.size();i++){
            cout<<"points on curve "<<i<<": ";
            for(int p=0;p<paths[i].points.size();p++){
                cout<<paths[i].points[p]<<" , ";
            }
            cout<<endl;
        }

    }*/


    return 1;
}
