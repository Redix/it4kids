#ifndef PARAMDIRECTION_H
#define PARAMDIRECTION_H

#include <QComboBox>

#include "param.h"

class ParamDirection : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamDirection(QWidget* parent);
    ~ParamDirection();

protected:
    QString getString() const;
};

#endif // PARAMDIRECTION_H