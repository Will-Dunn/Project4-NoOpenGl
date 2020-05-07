//
// Created by William Dunn on 5/3/20.
//

#ifndef SVG_RENDERING_ALGOPATH_H
#define SVG_RENDERING_ALGOPATH_H

#include "AlgoLine.h"
#include "point.h"
#include <iostream>
#include <chrono>
using namespace std;
class Path{
public:
    //const int choice=1;
     long time=0;
    vector<point> points;
    vector<point> castPoints;
    vector<Line> Lines;
    vector<point> bezpoints;
    vector<point> starts;


    float Xs,Ys,Xe,Ye;//might need to add more
    point A,B,C,S;
    float X2,Y2;
    bool ct=true;
    int last=0;
    Path(float x1,float y1){
        Xs=x1;
        Ys=y1;
        Xe=x1;
        Ye=y1;
        point s(x1,y1);
        S.x=Xs;
        S.y=Ys;
        points.push_back(s);
    }
    //M
    void Move(float x, float y){
        Xs=x;
        Ys=y;
        S.x=Xs;
        S.y=Ys;
        points[last].x=x;
        points[last].y=y;




    }
    void move(float x, float y){
        //gonna need to make sure this has negatives in it
        Xs=Xs+x;
        Ys=Ys+y;
        S.x=Xs;
        S.y=Ys;
        points[last].x=Xs;
        points[last].y=Ys;


    }
    void L(float x, float y){
        Ye=y;
        Xe=x;

        point Point(Xe,Ye);
        starts.push_back(Point);
        //Line l1(Xs,Ys,x,y);
        Line l1(points[last].x,points[last].y,x,y);
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
       // points[0].x=Xs;
       // points[0].y=Ys;

    }
    void l(float x, float y){
        //Line l1(Xs,Ys,Xs+x,Ys+y);
        Line l1(points[last].x,points[last].y,points[points.size()-1].x+x,points[points.size()-1].y+y);
        Ye=Ys+y;
        Xe=Xs+x;

        if(ct){
            X2=Xe;
            Y2=Ye;
            //ct=!ct;
        }

        ct=!ct;
        point Point(Xe,Ye);
        starts.push_back(Point);
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
        //points[0].x=Xs;
        //points[0].y=Ys;

    }
    void H(float x){
        Ye=Ys;
        Xe=x;
        if(ct){
            X2=Xe;
            Y2=Ye;
            //ct=!ct;
        }

        ct=!ct;
        point Point(Xe,Ye);
        starts.push_back(Point);
        //Line l1(Xs,Ys,x,Ys);
        Line l1(points[points.size()-1].x,points[points.size()-1].y,x,points[points.size()-1].y);
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
       // points[0].x=Xs;
        //points[0].y=Ys;

    }
    void h(float x){
        Line l1(points[points.size()-1].x,points[points.size()-1].y,points[points.size()-1].x+x,points[points.size()-1].y);
        Ye=Ys;
        Xe=Xs+x;
        point Point(Xe,Ye);
        starts.push_back(Point);
        if(ct){
            X2=Xe;
            Y2=Ye;
            //ct=!ct;
        }

        ct=!ct;
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
        //points[0].x=Xs;
       // points[0].y=Ys;

    }
    void V(float y){
        //Line l1(Xs,Ys,Xs,y);
        Line l1(points[points.size()-1].x,points[points.size()-1].y,points[points.size()-1].x,y);
        Xe=Xs;
        Ye=y;
        point Point(Xe,Ye);
        starts.push_back(Point);
        if(ct){
            X2=Xe;
            Y2=Ye;
            //ct=!ct;
        }

        ct=!ct;
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
        //points[0].x=Xs;
        //points[0].y=Ys;

    }
    void v(float y){
        Line l1(points[points.size()-1].x,points[points.size()-1].y,points[points.size()-1].x,points[points.size()-1].y+y);
        Xe=Xs;
        Ye=Ys+y;
        point Point(Xe,Ye);
        starts.push_back(Point);
        if(ct){
            X2=Xe;
            Y2=Ye;
            //ct=!ct;
        }

        ct=!ct;
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
        Xs=Xe;
        Ys=Ye;
        S.x=Xs;
        S.y=Ys;
        //points[0].x=Xs;
       // points[0].y=Ys;

    }
    void Z(){
        //this is not working right
        //cout<<"close the path"<<endl;
        Line l1(Xs,Ys,Xe,Ye);
        l1.draw_line();
        for(int i=0;i<l1.points.size();i++){
            points.push_back(l1.points[i]);
            last++;
        }
    }


    //De Casteljau Algorimthim
    void Casteljau(vector<point> pts, float t){
        if(pts.size()==1){
          points.push_back(pts[0]);

        }
        else{
            vector<point> newpts;
            for(int i=0;i<pts.size()-1;i++){
                point c;
                c.x=(1-t)*pts[i].x+t*pts[i+1].x;
                c.y=(1-t)*pts[i].y+t*pts[i+1].y;
                newpts.push_back(c);
            }
            Casteljau(newpts,t);
        }
    }
    //invocation of Casteljau to start the algorithim
    void Casteljau(){
        //add the points read in from the svg file to your initial start vector
        vector<point> startPoints;
        startPoints.push_back(S);
        startPoints.push_back(A);
        startPoints.push_back(B);
        startPoints.push_back(C);
        auto start = std::chrono::system_clock::now();
        for(float t=0;t<1;t+=.01){
            Casteljau(startPoints,t);
        }
        auto end = std::chrono::system_clock::now();
        time+=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        S.x=C.x;
        S.y=C.y;
        return;

    }
    void Casteljau(vector<point> startPoints){
        //add the points read in from the svg file to your initial start vector

        auto start = std::chrono::system_clock::now();
        for(float t=0;t<1;t+=.01){
            Casteljau(startPoints,t);
        }
        auto end = std::chrono::system_clock::now();
       // cout<<"indi time: "<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
        time+=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        S.x=C.x;
        S.y=C.y;
        return;

    }
    //array of binomial values which will be indexed by value n, primary index, and k, secondary index
 vector<int> lookUp[100];
    float binomial(float n, float k){
        if(k==0||k==n){
            return 1;
        }

        return binomial(n-1,k-1)+binomial(n-1,k);
    }
    void weightedBasisCubic( float t, vector<point> w){

        //specific for cubic function or when used in C command.
        float t2=t*t;
        float t3=t2*t;
        float mt=1-t;
        float mt2=mt*mt;
        float mt3=mt2*mt;
        float X=0;
        float Y=0;
        //for(float k=0;k<=3;k++ ){
            //the total sum of all these equations will be the x and y cordinates of the new point
            //added points x is the sum for each control points, i, i.x *binomal(n,k)*(1-t)^(n-k)*t^k

            //cout<<"X: "<<(w[0].x*mt3+ 3 * w[1].x * mt2*t + 3* w[2].x * mt * t2+ w[3].x * t3)<<endl;
            //cout<<"W[0].x"<<w[0].x<<" w[1].x"<<w[1].x<<" w[2].x "<<w[2].x<<" w[3].x "<<w[3].x<<"\n t:"<<
            //t<<" mt: "<<mt<<" T3: "<<t3<< "Mt3 "<<mt3<<endl;
        X=(w[0].x*mt3+ 3 * w[1].x * mt2*t + 3* w[2].x * mt * t2+ w[3].x * t3);
        Y=(w[0].y*mt3+ 3 * w[1].y * mt2*t + 3* w[2].y * mt * t2+ w[3].y * t3);
            //cout<<"n: "<<n<<"k: "<<k<<endl;
            //added points y is the sum for each control points, i, i.y *binomal(n,k)*(1-t)^(n-k)*t^k
            //Y+=w[k].y*lookUp[n][k]*pow((1-t),(n-k))*pow(t,k);

        //temporary fix to update the curser location
        S.x=C.x;
        S.y=C.y;
        point temp=point(X,Y);
        //cout<<temp<<endl;
        //only add the point if it is a valid location on the screen
        if(X<=500&&X>=0&&Y<=700&&Y>=0){
            points.push_back(temp );}
    }
    void weightedBasis(int n, float t, vector<point> w){
        float sumX=0;
        float sumY=0;
        for(float k=0;k<=n;k++ ){
            //the total sum of all these equations will be the x and y cordinates of the new point
            //added points x is the sum for each control points, i, i.x *binomal(n,k)*(1-t)^(n-k)*t^k
            sumX+=w[k].x*lookUp[n][k]*pow((1-t),(n-k))*pow(t,k);
            //cout<<"n: "<<n<<"k: "<<k<<endl;
            //added points y is the sum for each control points, i, i.y *binomal(n,k)*(1-t)^(n-k)*t^k
            sumY+=w[k].y*lookUp[n][k]*pow((1-t),(n-k))*pow(t,k);
        }
        //temporary fix to update the curser location
        S.x=C.x;
        S.y=C.y;
        //only add the point if it is a valid location on the screen
        if(sumX<=500&&sumX>=0&&sumY<=700&&sumY>=0){
        points.push_back( point(sumX,sumY));}
    }

    void Naive(){
        //cout<<"Runing Naive Solution"<<endl;
        vector<point> startPoints;
        startPoints.push_back(S);
        startPoints.push_back(A);
        startPoints.push_back(B);
        startPoints.push_back(C);
        //cout<<"S: "<<S<<"\nA: "<<A<<"\nB: "<<B<<"\nC: "<<C<<endl;
        //return;
        auto start = std::chrono::system_clock::now();
        //creates the look up table with the binomail values needed
        if(startPoints.size()>4) {
            for (int i = 0; i < startPoints.size(); i++) {
                vector<int> n;
                for (int k = 0; k < i; k++) {
                    n.push_back(binomial(i, k));

                }
                cout<<i<<endl;
                //cout<<"N: "<<i<<" / "<<startPoints.size()<<endl;
                lookUp[i] = n;
            }
            for (float t = 0; t < 1; t += .01) {


                //runs computation to determine
                weightedBasis(startPoints.size() - 1, t, startPoints);
                //cout<<t<<endl;
            }
        }
       // cout<<"to comp"<<endl;
        else if(startPoints.size()==4)
        for(float t=0;t<1;t+=.01){


            //runs computation to determine
            weightedBasisCubic(t,startPoints);
            //cout<<t<<endl;
        }
        auto end = std::chrono::system_clock::now();
        //cout<<"indi time: "<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
        time+=chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    }
    void Naive(vector<point>startPoints){

        cout<<startPoints[0]<<endl;
        auto start = std::chrono::system_clock::now();
        //creates the look up table with the binomail values needed
        if(startPoints.size()>4) {
            for (int i = 0; i < startPoints.size(); i++) {
                vector<int> n;
                for (int k = 0; k < i; k++) {
                    n.push_back(binomial(i, k));

                }
                //cout<<"N: "<<i<<" / "<<startPoints.size()<<endl;
                lookUp[i] = n;
            }
            for (float t = 0; t < 1; t += .01) {


                //runs computation to determine
                weightedBasis(startPoints.size() - 1, t, startPoints);
                //cout<<t<<endl;
            }
        }
            // cout<<"to comp"<<endl;
        else if(startPoints.size()==4){
            for(float t=0;t<1;t+=.01){


                //runs computation to determine
                weightedBasisCubic(t,startPoints);
                //cout<<t<<endl;
            }
        }
        auto end = std::chrono::system_clock::now();
        time+=chrono::duration_cast<chrono::nanoseconds >(end-start).count();

    }
void drawCurve(int choice){
        if(choice==1){

        Naive();

    }
        else{
            Casteljau();
        }

    }


void drawCurve(vector<point> Points, int choice){
    if(choice==1){

        Naive(Points);
        //();
    }
    else{
        Casteljau(Points);
    }

}

};
#endif //SVG_RENDERING_ALGOPATH_H