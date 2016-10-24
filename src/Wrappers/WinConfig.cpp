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
	[This file] WinConfig: Configuration Window (Wrapper)
*****************************************************************************
	[Change log] (Convention: YYYY-MM-DD | author | comment)
	* 2016-09-09 | jfduval | Initial GPL-3.0 release
	*
****************************************************************************/

//****************************************************************************
// Include(s)
//****************************************************************************

#include "WinConfig.h"
#include <QMdiSubWindow>
#include <QDebug>
#include "w_planconfig.h"

//****************************************************************************
// Constructor & Destructor:
//****************************************************************************

WinConfig::WinConfig(QWidget *parent) :
  QMdiSubWindow(parent)
{
    my_w_config = new W_PlanConfig(this);
    this->setWidget(my_w_config);

    connect(my_w_config, SIGNAL(openCom(QString,int,int)), this,\
            SLOT(receiveOpenCom(QString,int,int)));
    connect(my_w_config, SIGNAL(closeCom()), this,\
            SLOT(receiveCloseCom()));
    connect(my_w_config, SIGNAL(openLogFile(uint8_t)), this,\
            SLOT(receiveOpenLogFile(uint8_t)));
    connect(my_w_config, SIGNAL(loadLogFile()), this,\
            SLOT(receiveLoadLogFile()));
    connect(my_w_config, SIGNAL(closeLogFile()), this,\
            SLOT(receiveCloseLogFile()));
}

WinConfig::~WinConfig()
{
    emit windowClosed();
    my_w_config->~W_PlanConfig();
}

//****************************************************************************
// Public function(s):
//****************************************************************************
W_PlanConfig::DataSource WinConfig::getDataSourceStatus(void)
{
    return my_w_config->getDataSourceStatus();
}

//****************************************************************************
// Public slot(s):
//****************************************************************************

void WinConfig::setComProgress(int val, int rst)
{
    my_w_config->setComProgress(val, rst);
}

void WinConfig::setLogFileStatus(QString status)
{
    my_w_config->setLogFileStatus(status);
}

//****************************************************************************
// Private function(s):
//****************************************************************************

//****************************************************************************
// Private slot(s):
//****************************************************************************

void WinConfig::receiveOpenCom(QString name, int tries, int delay)
{
    //qDebug() << "WinConfig receiveOpenCom() slot.";
    emit transmitOpenCom(name, tries, delay);
}

void WinConfig::receiveCloseCom(void)
{
    emit transmitCloseCom();
}

void WinConfig::receiveOpenLogFile(uint8_t item)
{
    emit transmitOpenLogFile(item);
}

void WinConfig::receiveLoadLogFile(void)
{
    emit transmitLoadLogFile();
}

void WinConfig::receiveCloseLogFile(void)
{
    emit transmitCloseLogFile();
}
