#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class quad {
protected:
	double ans;
	bool ifcorrect;
public:
	quad(){} 
	virtual double area() const = 0; virtual void print() const = 0;
	virtual void change(double a, bool b) {
		ans = a;
		ifcorrect = b;
	}
	virtual double answer() {
		return ans;
	}
	virtual bool Ifcorrect() {
		return ifcorrect;
	}
};
class para : public quad {
protected:
	double width, height;
public:
	para(double w = 1, double h = 1) : width(w), height(h){} 
	double area() const {
		return width * height;
	}
	void print() const 	{
		cout << "parallelogram: width = " << width << ", height = " << height << ", area=";
	}
};
class trapezoid : public quad {
private:
	double topline, baseline, height;
public:
	trapezoid(double t = 1, double b = 1, double h = 1) :topline(t), baseline(b), height(h) {}
	double area() const final 	{
		return (baseline + topline) * height / 2;
	}
	void print() const {
		cout << "trapezoid: width1 = " << baseline << ", width2 = " << topline << ", height = " << height << ", area=";
	}
};
class rect : public para {
public:
	rect(double w = 1, double h = 1) : para(w, h) {} 
	void print() const {
		cout << "rectangle: width = " << width << ", height = " << height << ", area=";
	}
};
class diamond : public para {
public:
	diamond(double w = 1, double h = 1) : para(w, h) {}
	double area() const final {
		return (width * height) / 2;
	}
	void print() const {
		cout << "diamond: diagnal1 = " << width << ", diagnal2 = " << height << ", area=";
	}
};
class square final : public rect {
public:
	square(double w = 1) : rect(w, w) {}
	void print() const 	{
		cout << "square: width= " << width << ", area=";
	}
};