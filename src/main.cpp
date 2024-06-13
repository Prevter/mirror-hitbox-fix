#include <Geode/Geode.hpp>
#include <Geode/modify/CCDrawNode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/GameObject.hpp>

using namespace geode::prelude;

bool s_insideDebugUpdate = false;

class $modify(CCDrawNode) {
	bool drawPolygon(CCPoint *verts, unsigned int count, const ccColor4F &fillColor, float borderWidth, const ccColor4F &borderColor) {
        return CCDrawNode::drawPolygon(verts, count, fillColor, std::abs(borderWidth), borderColor);
    }
};

class $modify(GJBaseGameLayer) {
    void updateDebugDraw() {
        s_insideDebugUpdate = true;
        GJBaseGameLayer::updateDebugDraw();
        s_insideDebugUpdate = false;
    }
};

class $modify(GameObject) {
    void determineSlopeDirection() {
        if (s_insideDebugUpdate) return;
        GameObject::determineSlopeDirection();
    }
};
