#pragma once

#include "ofxSvgCommand.h"

class ofxSvgLineTo : public ofxSvgCommand {
public:
	ofxPoint2f point;
	ofxSvgLineTo(ofPoint point, bool relative = true) {
		this->point.set(point);
		this->relative = relative;
	}
	void draw(ofxSvgPathContext& context) const {
		ofxPoint2f& lastPoint = context.lastPoint;
		if(relative) {
			ofVertex(lastPoint.x + point.x, lastPoint.y + point.y);
			/*
			ofLine(
				lastPoint.x, lastPoint.y,
				lastPoint.x + point.x, lastPoint.y + point.y);*/
			lastPoint += point;
		} else {
			ofLine(
				lastPoint.x, lastPoint.y,
				point.x, point.y);
			lastPoint.set(point);
		}
	}
	ostream& put(ostream &out) const {
		if(relative)
			out << "l";
		else
			out << "L";
		out << point.x << "," << point.y;
		return out;
	}
};