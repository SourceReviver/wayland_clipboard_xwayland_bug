#include <QApplication>
#include <QLabel>
#include <QClipboard>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *label = new QLabel("Hello world!", nullptr);

    auto *clipboard = QGuiApplication::clipboard();

    QObject::connect(clipboard, &QClipboard::changed, [=](QClipboard::Mode mode) {
        if (mode == QClipboard::Clipboard) {
            label->setText(clipboard->text());
        }
        qDebug() << "Changed" << mode << clipboard->text(mode);
    });

    label->resize(400, 400);
    label->show();
    return QApplication::exec();
}
