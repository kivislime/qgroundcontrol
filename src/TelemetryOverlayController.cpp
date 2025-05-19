// TelemetryOverlayController.cpp
#include "TelemetryOverlayController.h"

TelemetryOverlayController::TelemetryOverlayController(QObject* parent) : QObject(parent) {}

void TelemetryOverlayController::setVehicle(Vehicle* vehicle) {
    if (_vehicle) {
        disconnect(_vehicle, &Vehicle::attitudeChanged, this, &TelemetryOverlayController::_updateAttitude);
    }
    _vehicle = vehicle;
    if (_vehicle) {
        connect(_vehicle, &Vehicle::attitudeChanged, this, &TelemetryOverlayController::_updateAttitude);
    }
}

void TelemetryOverlayController::_updateAttitude(double roll, double pitch, double yaw) {
    _roll = roll;
    _pitch = pitch;
    _yaw = yaw;
    emit attitudeChanged();
}
