#include "bualsa.h"
#include "bualsaplugin.h"

#include <QtPlugin>

BuAlsaPlugin::BuAlsaPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void BuAlsaPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool BuAlsaPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *BuAlsaPlugin::createWidget(QWidget *parent)
{
    return new BuAlsa(parent);
}

QString BuAlsaPlugin::name() const
{
    return QLatin1String("BuAlsa");
}

QString BuAlsaPlugin::group() const
{
    return QLatin1String("Buccaneer");
}

QIcon BuAlsaPlugin::icon() const
{
    return QIcon();
}

QString BuAlsaPlugin::toolTip() const
{
    return QLatin1String("Buccanner Rack Unit Alsa");
}

QString BuAlsaPlugin::whatsThis() const
{
    return QLatin1String("Widget for RuAlsa");
}

bool BuAlsaPlugin::isContainer() const
{
    return false;
}

QString BuAlsaPlugin::domXml() const
{
    return QLatin1String("<widget class=\"BuAlsa\" name=\"buAlsa\">\n</widget>\n");
}

QString BuAlsaPlugin::includeFile() const
{
    return QLatin1String("bualsa.h");
}

