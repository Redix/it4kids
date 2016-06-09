#include "scriptdock.h"

#include "dragableelement.h"
#include "mainwindow.h"

extern MainWindow* sMainWindow;

ScriptDock::ScriptDock(Type type, Sprite *sprite, DragableElement* parent) :
    DockingArea(sprite), _type(type), _parent(parent)
{
}

void ScriptDock::connect(DragableElement *upper, DragableElement *lower)
{
    _dockedElem = lower;
    lower->setCurrentDock(this);
    lower->setPrevElem(upper);
    if(_type != Inner)
        upper->setNextElem(lower);
}

void ScriptDock::dock(DragableElement* elem)
{
    ScriptDock *otherDock;

    if(_type == Upper && !elem->getNextElem())
    {
        otherDock = elem->getDock(Lower);
        if(!otherDock)
            return;
        otherDock->connect(elem, _parent);
        _parent->rearrangeUpperElems();
    }
    else if((_type == Lower || _type == Inner) && !elem->getPrevElem())
    {
        otherDock = elem->getDock(Upper);
        if(!otherDock)
            return;
        connect(_parent, elem);
        elem->getRoot()->rearrangeLowerElems();
    }
    else
        return;

    otherDock->deactivate();
    deactivate();

    if(elem->getRoot()->getType() == DragableElement::Hat)
        sMainWindow->reloadCode();
}

void ScriptDock::undock()
{
    if((_type != Lower && _type != Inner) || !_dockedElem)
        return;

    _dockedElem->getDock(Upper)->activate();
    _dockedElem->setPrevElem(0);
    _dockedElem->setCurrentDock(0);
    _dockedElem = 0;
    if(_type != Inner)
        _parent->setNextElem(0);

    activate();
    _parent->getRoot()->rearrangeLowerElems();
    if(_parent->getRoot()->getType() == DragableElement::Hat)
        sMainWindow->reloadCode();
}

ScriptDock::~ScriptDock()
{
}