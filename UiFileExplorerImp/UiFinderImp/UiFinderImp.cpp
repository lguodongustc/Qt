#include "UiFinderImp.h"
#include "ui_UiFinderImp.h"

UiFinderImp::UiFinderImp(QWidget* p_Parent)
    : QDialog(p_Parent)
    , m_Ui(new Ui::UiFinderImp)
{
    m_Ui->setupUi(this);


}

UiFinderImp::~UiFinderImp()
{

}
