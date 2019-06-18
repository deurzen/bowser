#include "bowser.hh"

#include "common.hh"
#include "util.hh"
#include "cxxopts.hh"

#include <QApplication>
#include <QtCore/QUrl>
#include <QtCore/QPointer>
#include <QtGui/QIcon>
#include <QtNetwork/QAuthenticator>
#include <QWebEngineSettings>


::std::unique_ptr<bowser_t>
bowser_t::init(int argc, char** argv)
{
    return ::std::make_unique<bowser_t>(argc, argv);
}

void
bowser_t::setup()
{
    parser.parse();
    ::QCoreApplication::setOrganizationName(BROWSER_NAME.c_str());
    ::QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    ::QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    ::std::tie(argc, args) = parser.getargs();
    QApplication app(argc, args.data());
    app.setApplicationName(BROWSER_NAME.c_str());
    app.setDesktopFileName(("org." + BROWSER_NAME + "." + BROWSER_NAME).c_str());
    app.setApplicationVersion(BROWSER_VERSION.c_str());
    app.setQuitOnLastWindowClosed(false);

    ::QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
}

void
bowser_t::run()
{
}
