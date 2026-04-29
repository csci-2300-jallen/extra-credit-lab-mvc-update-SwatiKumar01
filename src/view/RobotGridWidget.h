#pragma once

#include <QPixmap>
#include <QWidget>

class QLabel;

class RobotGridWidget : public QWidget {
public:
    RobotGridWidget(QWidget* parent = nullptr);

    void setRobotPosition(int newX, int newY);

private:
    void updateRobotIcon();
    void resizeEvent(QResizeEvent* event) override;

    static const int gridSize = 5;
    int x = 2;
    int y = 2;
    QPixmap robotIcon;
    QLabel* cells[gridSize][gridSize];
};
