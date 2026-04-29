#pragma once

#include <QMainWindow>

class RobotController;
class RobotGridWidget;
class QLabel;
class QPushButton;

class RobotWindow : public QMainWindow {
public:
    RobotWindow();

    void setRobotPosition(int x, int y);
    void setController(RobotController* controller);
    void setUndoEnabled(bool enabled);
    void setRedoEnabled(bool enabled);
    void setStatusText(const QString& text);

    QPushButton* getUndoButton() const;
    QPushButton* getRedoButton() const;
    QPushButton* getSaveButton() const;
    QPushButton* getLoadButton() const;

private:
    RobotGridWidget* grid;
    QLabel* statusLabel;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    RobotController* controller = nullptr;

protected:
    void keyPressEvent(QKeyEvent* event) override;
};
