#include "bowser.hh"

#include "common.hh"
#include "util.hh"

#include <QtWebEngine>
#include <QWebEngineSettings>


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
    m_app->setApplicationName(BROWSER_NAME.c_str());
    m_app->setDesktopFileName(("org." + BROWSER_NAME + "." + BROWSER_NAME).c_str());
    m_app->setApplicationVersion(BROWSER_VERSION.c_str());
    m_app->setQuitOnLastWindowClosed(false);
    ::QtWebEngine::initialize();
}

void
bowser_t::run()
{
    m_app->exec();
}
