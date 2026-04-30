#include "view/RobotWindow.h"
#include "controller/RobotController.h"
#include "view/RobotGridWidget.h"

#include <QKeyEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

RobotWindow::RobotWindow()
    : QMainWindow(nullptr) {

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout* layout = new QVBoxLayout(central);

    grid = new RobotGridWidget(this);
    layout->addWidget(grid);

    statusLabel = new QLabel("Robot Ready", this);
    layout->addWidget(statusLabel);

    undoButton = new QPushButton("Undo", this);
    redoButton = new QPushButton("Redo", this);
    saveButton = new QPushButton("Save", this);
    loadButton = new QPushButton("Load", this);

    layout->addWidget(undoButton);
    layout->addWidget(redoButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);
}

void RobotWindow::setController(RobotController* controller) {
    this->controller = controller;
}

void RobotWindow::setRobotPosition(int x, int y) {
    if (grid) grid->setRobotPosition(x, y);
}

void RobotWindow::setUndoEnabled(bool enabled) {
    if (undoButton) undoButton->setEnabled(enabled);
}

void RobotWindow::setRedoEnabled(bool enabled) {
    if (redoButton) redoButton->setEnabled(enabled);
}

void RobotWindow::setStatusText(const QString& text) {
    if (statusLabel) statusLabel->setText(text);
}

QPushButton* RobotWindow::getUndoButton() const { return undoButton; }
QPushButton* RobotWindow::getRedoButton() const { return redoButton; }
QPushButton* RobotWindow::getSaveButton() const { return saveButton; }
QPushButton* RobotWindow::getLoadButton() const { return loadButton; }

void RobotWindow::keyPressEvent(QKeyEvent* event) {
    if (!controller) return;

    if (event->key() == Qt::Key_W) controller->moveUp();
    else if (event->key() == Qt::Key_S) controller->moveDown();
    else if (event->key() == Qt::Key_A) controller->moveLeft();
    else if (event->key() == Qt::Key_D) controller->moveRight();
}