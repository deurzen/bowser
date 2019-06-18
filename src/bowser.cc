#include "bowser.hh"

#include "common.hh"
#include "util.hh"
#include "cxxopts.hh"

#include <QtCore/QUrl>
#include <QtCore/QPointer>
#include <QtGui/QIcon>
#include <QtNetwork/QAuthenticator>
#include <QWebEngineSettings>
#include <QWidget>


::std::unique_ptr<bowser_t>
bowser_t::init(int argc, char** argv)
{
    ::QCoreApplication::setOrganizationName(BROWSER_NAME.c_str());
    ::QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    ::QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    ::QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    return ::std::make_unique<bowser_t>(argc, argv);
}

void
bowser_t::setup()
{
    app.setApplicationName(BROWSER_NAME.c_str());
    app.setDesktopFileName(("org." + BROWSER_NAME + "." + BROWSER_NAME).c_str());
    app.setApplicationVersion(BROWSER_VERSION.c_str());
    app.setQuitOnLastWindowClosed(false);
}

void
bowser_t::run()
{
    QWidget window;
    window.resize(800, 600);
    window.setWindowTitle(BROWSER_NAME.c_str());
    window.show();

    app.exec();
}
