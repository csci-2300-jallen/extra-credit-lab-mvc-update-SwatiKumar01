#pragma once

class QKeyEvent;

class Robot;
class RobotWindow;

class RobotController {
public:
    RobotController(Robot* model, RobotWindow* view);

    void initialize();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void undo();
    void redo();
    void saveHistory();
    void loadHistory();
    bool handleKeyPress(QKeyEvent* event);

private:
    void refreshView();
    void connectButtons();

    Robot* model;
    RobotWindow* view;
};
