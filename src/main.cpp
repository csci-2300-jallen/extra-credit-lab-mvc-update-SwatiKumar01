#include <QApplication>
#include <QInputDialog>
#include <QString>

#include "controller/RobotController.h"
#include "model/Robot.h"
#include "view/RobotWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString robotName = QInputDialog::getText(
        nullptr,
        "Robot Name",
        "Name:"
    );

    if (robotName.isEmpty()) {
        robotName = "Robot";
    }

    Robot model(robotName.toStdString());
    RobotWindow view;
    RobotController controller(&model, &view);

    controller.initialize();
    view.show();

    return app.exec();
}
