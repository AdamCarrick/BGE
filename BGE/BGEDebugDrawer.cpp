#include "BGEDebugDrawer.h"
#include "LineDrawer.h"
#include "Utils.h"

using namespace BGE;

BGEDebugDrawer::BGEDebugDrawer()
{

}

BGEDebugDrawer::~BGEDebugDrawer()
{

}

void BGEDebugDrawer::drawLine(const btVector3 &from, const btVector3 &to, const btVector3 &color)
{


	BGE::LineDrawer::DrawLine(BtToGLVector(from), BtToGLVector(to), BtToGLVector(color));

}


void BGEDebugDrawer::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color){}
void BGEDebugDrawer::reportErrorWarning(const char* warningString){}
void BGEDebugDrawer::draw3dText(const btVector3& location, const char* textString){}

void BGEDebugDrawer::setDebugMode(int debugMode)
{
	mDebugModes = (DebugDrawModes)debugMode;
}

int BGEDebugDrawer::getDebugMode() const
{
	return mDebugModes;
}

