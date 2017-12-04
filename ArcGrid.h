#pragma once

#include "ofMain.h"
#include "FboSource.h"

class ArcGrid : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void setName(string _name);
        void sas4(int phase);
        void arcs(ofColor arcColor, int rotation, float arcDiameter);

        float counter;
};
