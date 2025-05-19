import QtQuick
import QtQuick.Controls
import QGroundControl.FactSystem 2.0    // если доступно; убедитесь, что версия совпадает

Rectangle {
    id: parameterOverlay
    width: 220
    height: 50
    color: "#66000000"    // полупрозрачный черный фон
    radius: 5

    // Свойство для хранения объекта факта. Предполагается, что активный транспортное средство доступно через multiVehicleManager.
    property var attitudeFact: QGroundControl.multiVehicleManager.activeVehicle ?
                                QGroundControl.multiVehicleManager.activeVehicle.getFact("ATTITUDE") : null

    Text {
        id: attitudeText
        anchors.centerIn: parent
        text: attitudeFact ? "ATTITUDE: " + attitudeFact.value.toFixed(2) : "Нет данных"
        color: "white"
        font.pixelSize: 16
    }

    // Обновление текста при изменении значения факта.
    Connections {
        target: attitudeFact
        onValueChanged: {
            attitudeText.text = "ATTITUDE: " + attitudeFact.value.toFixed(2)
        }
    }
}
