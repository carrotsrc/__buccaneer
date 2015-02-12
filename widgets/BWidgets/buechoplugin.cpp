#include "buecho.h"
#include "buechoplugin.h"

#include <QtPlugin>

BuEchoPlugin::BuEchoPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void BuEchoPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool BuEchoPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *BuEchoPlugin::createWidget(QWidget *parent)
{
    return new BuEcho(parent);
}

QString BuEchoPlugin::name() const
{
    return QLatin1String("BuEcho");
}

QString BuEchoPlugin::group() const
{
    return QLatin1String("Buccaneer");
}

QIcon BuEchoPlugin::icon() const
{
    return QIcon();
}

QString BuEchoPlugin::toolTip() const
{
    return QLatin1String("Buccanner Rack Unit Echo");
}

QString BuEchoPlugin::whatsThis() const
{
    return QLatin1String("Widget for RuEcho");
}

bool BuEchoPlugin::isContainer() const
{
    return false;
}

QString BuEchoPlugin::domXml() const
{
    return QLatin1String("<widget class=\"BuEcho\" name=\"buEcho\">\n</widget>\n");
}

QString BuEchoPlugin::includeFile() const
{
    return QLatin1String("buecho.h");
}

