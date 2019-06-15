#include "bowser.hh"

#include <QApplication>
#include <QtCore/QUrl>
#include <QtCore/QPointer>
#include <QtGui/QIcon>
#include <QtNetwork/QAuthenticator>


::std::unique_ptr<bowser_t>
bowser_t::init()
{
    return ::std::make_unique<bowser_t>();
}

void
bowser_t::setup()
{
    QCoreApplication::setOrganizationName("QtExamples");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    int argc = 1;
    char* argv[1] = {"bowser"};
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(QStringLiteral(":AppLogoColor.png")));
}

void
bowser_t::run()
{
}
