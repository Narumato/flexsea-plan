/****************************************************************************
	[Project] FlexSEA: Flexible & Scalable Electronics Architecture
	[Sub-project] 'plan-gui' Graphical User Interface
	Copyright (C) 2016 Dephy, Inc. <http://dephy.com/>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************
	[Lead developper] Jean-Francois (JF) Duval, jfduval at dephy dot com.
	[Origin] Based on Jean-Francois Duval's work at the MIT Media Lab 
	Biomechatronics research group <http://biomech.media.mit.edu/>
	[Contributors] 
*****************************************************************************
	[This file] mainwindow.h: Main GUI Window - connects all the modules
	together
*****************************************************************************
	[Change log] (Convention: YYYY-MM-DD | author | comment)
	* 2016-09-09 | jfduval | Initial GPL-3.0 release
    * 2016-09-12 | jfduval | create() RIC/NU view
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WinViewExecute.h"
#include "WinSlaveComm.h"
#include "WinConfig.h"
#include "WinAnyCommand.h"
#include "WinConverter.h"
#include "WinView2DPlot.h"
#include "WinControlControl.h"
#include "WinViewRicnu.h"
#include "flexsea_generic.h"
#include "serialdriver.h"
#include "datalogger.h"
#include "main.h"

namespace Ui {
class MainWindow;
}

//MDI Objects: set maximums # of child
#define EX_VIEW_WINDOWS_MAX         5
#define CONFIG_WINDOWS_MAX          1
#define SLAVECOMM_WINDOWS_MAX       1
#define ANYCOMMAND_WINDOWS_MAX      1
#define CONVERTER_WINDOWS_MAX       1
#define CONTROL_WINDOWS_MAX         1
#define PLOT2D_WINDOWS_MAX          2
#define RICNU_VIEW_WINDOWS_MAX      1

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Objects & Windows:
    //==================

    //Execute View:
    int exViewObjectCount;
    WinViewExecute *myViewEx[EX_VIEW_WINDOWS_MAX];

    //Config objects:
    int configObjectCount;
    WinConfig *myConfig[CONFIG_WINDOWS_MAX];

    //Slave Comm:
    int slaveCommObjectCount;
    WinSlaveComm *mySlaveComm[SLAVECOMM_WINDOWS_MAX];

    //AnyCommand:
    int anyCommandObjectCount;
    WinAnyCommand *myAnyCommand[ANYCOMMAND_WINDOWS_MAX];

    //Converter:
    int converterObjectCount;
    WinConverter *myConverter[CONVERTER_WINDOWS_MAX];

    //Control:
    int controlObjectCount;
    WinControlControl *myControl[CONTROL_WINDOWS_MAX];

    //2D Plot:
    int plot2DObjectCount;
    WinView2DPlot *my2DPlot[PLOT2D_WINDOWS_MAX];

    //RIC/NU View:
    int ricnuViewObjectCount;
    WinViewRicnu *myViewRicnu[RICNU_VIEW_WINDOWS_MAX];

    //FlexSEA Generic:
    FlexSEA_Generic myFlexSEA_Generic;

    //Serial Port Driver:
    SerialDriver *mySerialDriver;

    //DataLogger:
    DataLogger *myDataLogger;

public slots:

    //MDI Windows (create):
    void createViewExecute(void);
    void createView2DPlot(void);
    void createControlControl(void);
    void createConfig(void);
    void createSlaveComm(void);
    void createAnyCommand(void);
    void createViewRicnu(void);
    void createConverter(void);

    //MDI Windows (closed):
    void closeViewExecute(void);
    void closeView2DPlot(void);
    void closeControlControl(void);
    void closeConfig(void);
    void closeSlaveComm(void);
    void closeAnyCommand(void);
    void closeViewRicnu(void);
    void closeConverter(void);

    //Message boxes:
    void displayAbout();
    void displayDocumentation();
    void displayLicense();
    void setStatusBar(QString msg);

signals:

};

#endif // MAINWINDOW_H