#ifndef MAINDISPLAY_H
#define MAINDISPLAY_H

#include <QMainWindow>
#include <QTimer>
#include <QJsonDocument>

#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainDisplay;
}
QT_END_NAMESPACE

class MainDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDisplay(QWidget *parent = nullptr);
    ~MainDisplay();

public slots:
    void updateTelemetryData();  // ✅ Updates telemetry data every second

private:
    Ui::MainDisplay *ui;  // ✅ Pointer to UI
    QTimer *timer;
};

#endif // MAINDISPLAY_H
