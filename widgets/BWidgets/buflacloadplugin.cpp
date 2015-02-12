#include "buflacload.h"
#include "buflacloadplugin.h"

#include <QtPlugin>

BuFlacLoadPlugin::BuFlacLoadPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void BuFlacLoadPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool BuFlacLoadPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *BuFlacLoadPlugin::createWidget(QWidget *parent)
{
    return new BuFlacLoad(parent);
}

QString BuFlacLoadPlugin::name() const
{
    return QLatin1String("BuFlacLoad");
}

QString BuFlacLoadPlugin::group() const
{
    return QLatin1String("Buccaneer");
}

QIcon BuFlacLoadPlugin::icon() const
{
    return QIcon();
}

QString BuFlacLoadPlugin::toolTip() const
{
    return QLatin1String("Buccanner Rack Unit FlacLoad");
}

QString BuFlacLoadPlugin::whatsThis() const
{
    return QLatin1String("Widget for RuFlacLoad");
}

bool BuFlacLoadPlugin::isContainer() const
{
    return false;
}

QString BuFlacLoadPlugin::domXml() const
{
    return QLatin1String("<widget class=\"BuFlacLoad\" name=\"buFlacLoad\">\n</widget>\n");
}

QString BuFlacLoadPlugin::includeFile() const
{
    return QLatin1String("buflacload.h");
}

