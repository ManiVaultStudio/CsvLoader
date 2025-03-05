#pragma once

#include <LoaderPlugin.h>

#include "InputDialog.h"

#include <QObject>
#include <QStringList>

#include <vector>

using namespace mv::plugin;

// =============================================================================
// View
// =============================================================================

class CsvLoader : public LoaderPlugin
{
    Q_OBJECT
public:
    CsvLoader(const PluginFactory* factory) : LoaderPlugin(factory) { }
    ~CsvLoader(void) override;

    void init() override;

    void loadData() Q_DECL_OVERRIDE;

public slots:
    void dialogClosed(QString dataSetName, bool hasHeaders, QString selectedDataElementType);

private:
    std::vector<QStringList> _loadedData;
};


// =============================================================================
// Factory
// =============================================================================

class CsvLoaderFactory : public LoaderPluginFactory
{
    Q_INTERFACES(mv::plugin::LoaderPluginFactory mv::plugin::PluginFactory)
    Q_OBJECT
    Q_PLUGIN_METADATA(IID   "nl.tudelft.CsvLoader"
                      FILE  "CsvLoader.json")

public:
    CsvLoaderFactory(void);

    ~CsvLoaderFactory(void) override {}

    /**
     * Produces the plugin
     * @return Pointer to the produced plugin
     */
    LoaderPlugin* produce() override;

    /**
     * Get the data types that the plugin supports
     * @return Supported data types
     */
    mv::DataTypes supportedDataTypes() const override;
};
