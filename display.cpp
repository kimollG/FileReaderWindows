#include "display.h"
#include "QImage"
Display::Display()
{
    data=NULL;
}
Display::Display(ModelData &data)
{
    this->data=&data;
}
void Display::Draw()
{
    QPixmap map();

}

