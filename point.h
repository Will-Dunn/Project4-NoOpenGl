//
// Created by William Dunn on 4/30/20.
//

#ifndef HELLOOPENGL_POINT_H
#define HELLOOPENGL_POINT_H
class point{
public:
    float x;
    float y;
    point(){
        x=0;
        y=0;
    }
    point(float X, float Y){
        x=X;
        y=Y;
    }
    friend ostream & operator<< (ostream &out,const point& val){
        //this es not work properly I dont know why I tried to fix it, i could not but i worked aroung it

        out<<"("<<val.x<<" , "<<val.y<<")";

        return out;
    }
};
#endif //HELLOOPENGL_POINT_H
