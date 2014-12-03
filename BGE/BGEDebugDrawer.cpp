#include "BGEDebugDrawer.h"
#include "LineDrawer.h"

using namespace BGE;

BGEDebugDrawer::BGEDebugDrawer()
{

}

BGEDebugDrawer::~BGEDebugDrawer()
{

}

void BGEDebugDrawer::drawLine(const btVector3 &from, const btVector3 &to, const btVector3 &color)
{

	glm::vec3 glmFrom;
	glmFrom.x = from.getX();
	glmFrom.y = from.getY();
	glmFrom.z = from.getZ();

	glm::vec3 glmTo;
	glmTo.x = to.getX();
	glmTo.y = to.getY();
	glmTo.z = to.getZ();

	glm::vec3 glmColor;
	glmColor.x = color.getX();
	glmColor.y = color.getY();
	glmColor.z = color.getZ();

	BGE::LineDrawer::DrawLine(glmFrom, glmTo, glmColor);

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

