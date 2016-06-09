#include "predicatede.h"
#include "param/paramdock.h"

PredicateDE::PredicateDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
    DragableElement(identifier, text, color, DragableElement::Predicate, sprite, parent)
{
    _currentDock = 0;
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(10, 0, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

void PredicateDE::resize()
{
    bool visible = isVisible();
    if(!visible) show();

    getLayoutSize();
    _path = QPainterPath();
    _path.moveTo(0, (_height+4)/2);
    _path.lineTo(10, 0);
    _path.lineTo(_width+5, 0);
    _path.lineTo(_width+15, (_height+4)/2);
    _path.lineTo(_width+5, _height+4);
    _path.lineTo(10, _height+4);
    _path.lineTo(0, (_height+4)/2);
    _layout.setSizeConstraint(QLayout::SetNoConstraint);
    setFixedSize(_width+20, _height+4);

    if(!visible) hide();
}

void PredicateDE::removeChildDragElems()
{
    _sprite->removeElement(this);
    delete this;
}

DragableElement* PredicateDE::getCurrentElement(Sprite *sprite, QWidget *parent)
{
    return copyParams(new PredicateDE(_identifier, _text, _color, sprite, parent));
}

PredicateDE::~PredicateDE()
{

}