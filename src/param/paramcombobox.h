#ifndef PARAMCOMBOBOX_H
#define PARAMCOMBOBOX_H

#include "param.h"

class ParamComboBox : public ParamBaseStr
{
public:
    ParamComboBox(QWidget* parent);
    virtual ~ParamComboBox();

    bool setValue(const QString &);
    QWidget* getWidget();

protected:
    QString getString() const;

    class QComboBox* _comboBox;
};

#endif // PARAMCOMBOBOX_H
