//
// Created by William Dunn on 4/30/20.
//

#ifndef HELLOOPENGL_ALGOLINE_H
#define HELLOOPENGL_ALGOLINE_H

#include <vector>
#include "point.h"
#include <iostream>
using namespace std;
class Line{
public:
    //choice = 1 is naive choice= 0 is more complicated
    static const int choice=1;
    float Xs;
    float Ys;
    float Xe;
    float Ye;
    vector<point> points;
    Line(float x1,float y1, float x2, float y2){
        Xs=x1;
        Ys=y1;
        Xe=x2;
        Ye=y2;
    }

    void naive_Line(){
        //vector<point> points;
        //for each x in x1-x2;
        //cout<<"X1: "<<Xs<<" Y1: "<<Ys<<" X2: "<<Xe<<" Y2: "<<Ye<<endl;
        //instead of writing a new line drawing system for when you are going backwards or down just swap the numbers

        float X2=Xe;
        float X1=Xs;
        float dx = Xe - Xs;
        float  dy = Ye - Ys;
        float slope;
        float y;
        if(dx!=0){
            slope=(float)dy/(float)dx;}
        else{
            slope=0;
        }
        if(Xs>Xe){

            for(float x=Xe;x<Xs;x+=.1){
                y = Ye+slope*(x-X2);
                // cout<<"X: "<<x<<" Y: "<<y<<endl;
                //draw_pixel(x,y);
                point temp(x,y);
                points.push_back(temp);
            }

        }
        else if( dx!=0){
            for(float x=Xs;x<Xe;x+=.1){
                //cout<<x<<endl;
                y = Ys+slope*(x-X1);
                // cout<<"X: "<<x<<" Y: "<<y<<endl;
                //draw_pixel(x,y);
                point temp(x,y);
                points.push_back(temp);
            }
        }

        //cout<<"x1: "<<Xs<<" x2: "<<Xe<<" y: "<<Ys<<" Y2: "<<Ye<<endl;
        //if(x2<x1){
        //  Xe=Xs;
        //Xs=X2;

        // }
        //cout<<"slope: "<<slope<<endl;
        else if(dx==0 &&Ye>Ys){
            float x=Xs;
            //cout<<"here"<<endl;
            for(float y=Ys;y<Ye;y+=.1){
                //cout<<"X: "<<x<<" Y: "<<y<<endl;
                //draw_pixel(x,y);
                point temp(x,y);
                points.push_back(temp);
            }
        }
        else{
            float x=Xs;
            //cout<<"here"<<endl;
            for(float y=Ye;y<Ys;y+=.1){
                //cout<<"X: "<<x<<" Y: "<<y<<endl;
                //draw_pixel(x,y);
                point temp(x,y);
                points.push_back(temp);
            }
        }


        //return points;
    }
    void bresenham_Line(){
        //vector<point> points;
        int dx = Xe - Xs;
        int dy = Ye - Ys;
        int slope=2*dy;
        int ErrorInSlope=slope-dx;
        int y= Ys;
        for(int x=Xs ;  x<= Xe;x+=.1){
            point temp(x,y);
            points.push_back(temp);
            ErrorInSlope += slope;
            if(ErrorInSlope >=0){
                y++;
                ErrorInSlope -= 2* dx;
            }
        }

    }
    void draw_line(){
        if(choice==0){
            bresenham_Line();
        }
        else{
            naive_Line();

        }
    }
    void printCORDS(){
        cout<<"Xs: "<<Xs<<" Ys: "<<Ys<<" Xe: "<<Xe<<" Ye: "<<Ye<<endl;
    }
};
#endif //HELLOOPENGL_ALGOLINE_H
