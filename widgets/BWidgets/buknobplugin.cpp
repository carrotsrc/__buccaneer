#include "buknob.h"
#include "buknobplugin.h"

#include <QtPlugin>

BuKnobPlugin::BuKnobPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void BuKnobPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool BuKnobPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *BuKnobPlugin::createWidget(QWidget *parent)
{
    return new BuKnob(parent);
}

QString BuKnobPlugin::name() const
{
    return QLatin1String("BuKnob");
}

QString BuKnobPlugin::group() const
{
    return QLatin1String("Buccaneer");
}

QIcon BuKnobPlugin::icon() const
{
    return QIcon();
}

QString BuKnobPlugin::toolTip() const
{
    return QLatin1String("Buccaneer Unit Knobs");
}

QString BuKnobPlugin::whatsThis() const
{
    return QLatin1String("Widget for Buccaneer");
}

bool BuKnobPlugin::isContainer() const
{
    return false;
}

QString BuKnobPlugin::domXml() const
{
    return QLatin1String("<widget class=\"BuKnob\" name=\"buKnob\">\n</widget>\n");
}

QString BuKnobPlugin::includeFile() const
{
    return QLatin1String("buknob.h");
}

