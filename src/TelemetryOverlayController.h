#pragma once
#include <QObject>
#include "Vehicle.h"

class TelemetryOverlayController : public QObject {
    Q_OBJECT
    Q_PROPERTY(double roll READ roll NOTIFY attitudeChanged)
    Q_PROPERTY(double pitch READ pitch NOTIFY attitudeChanged)
    Q_PROPERTY(double yaw READ yaw NOTIFY attitudeChanged)

public:
    TelemetryOverlayController(QObject* parent = nullptr);
    void setVehicle(Vehicle* vehicle);

    double roll() const { return _roll; }
    double pitch() const { return _pitch; }
    double yaw() const { return _yaw; }

signals:
    void attitudeChanged();

private slots:
    void _updateAttitude(double roll, double pitch, double yaw);

private:
    Vehicle* _vehicle = nullptr;
    double _roll = 0;
    double _pitch = 0;
    double _yaw = 0;
};
