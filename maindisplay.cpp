#include "maindisplay.h"
#include "ui_maindisplay.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

MainDisplay::MainDisplay(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainDisplay), timer(new QTimer(this))
{
    ui->setupUi(this);  // ✅ Initializes UI

    connect(timer, &QTimer::timeout, this, &MainDisplay::updateTelemetryData);
    timer->start(1000); // ✅ Timer triggers every 1 second

    this->setWindowTitle("VegapodD1 Dashboard");
    this->resize(800, 600);
}

MainDisplay::~MainDisplay()
{
    delete ui;
}

void MainDisplay::updateTelemetryData() {
    // Simulating JSON telemetry data
    QJsonObject jsonData;
    jsonData["speed"] = QRandomGenerator::global()->bounded(800, 1200); // Random speed between 50-200 km/h

    // Convert JSON object to string
    QJsonDocument jsonDoc(jsonData);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);

    // Parse JSON string (simulating real network data reception)
    QJsonDocument receivedJson = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObject = receivedJson.object();

    if (jsonObject.contains("speed")) {
        int speedValue = jsonObject["speed"].toInt();
        ui->speedLabel->setText(QString("Speed: %1 km/h").arg(speedValue));  // ✅ Updates Label
        qDebug() << "Received JSON:" << jsonString;  // ✅ Debug log to check received data
        qDebug() << "Updated speed:" << speedValue;
    }
}
