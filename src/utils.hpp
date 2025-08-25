using namespace geode::prelude;

CCNode* findChildByID(CCNode* parent, const char* id) {
    if (!parent) return nullptr;
    if (parent->getID() == id) return parent;

    CCArray* children = parent->getChildren();
    if (!children) return nullptr;

    CCObject* obj = nullptr;
    CCARRAY_FOREACH(children, obj) {
        if (auto node = dynamic_cast<CCNode*>(obj)) {
            if (auto found = findChildByID(node, id))
                return found;
        }
    }
    return nullptr;
}