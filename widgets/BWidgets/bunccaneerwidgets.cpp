#include "buflacloadplugin.h"
#include "bualsaplugin.h"
#include "buechoplugin.h"
#include "bunccaneerwidgets.h"

BunccaneerWidgets::BunccaneerWidgets(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new BuFlacLoadPlugin(this));
    m_widgets.append(new BuAlsaPlugin(this));
    m_widgets.append(new BuEchoPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> BunccaneerWidgets::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(bunccaneerwidgetsplugin, BunccaneerWidgets)
#endif // QT_VERSION < 0x050000
