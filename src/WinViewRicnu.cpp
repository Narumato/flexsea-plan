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
	[This file] WinViewRicnu: RIC/NU Kneww View Window (Wrapper)
*****************************************************************************
	[Change log] (Convention: YYYY-MM-DD | author | comment)
	* 2016-09-12 | jfduval | New file
	*
****************************************************************************/

//****************************************************************************
// Include(s)
//****************************************************************************

#include "WinViewRicnu.h"
#include <QMdiSubWindow>
#include "w_ricnu.h"

//****************************************************************************
// Constructor & Destructor:
//****************************************************************************

WinViewRicnu::WinViewRicnu(QWidget *parent) :
  QMdiSubWindow(parent)
{
    my_w_ricnu = new W_Ricnu(this);
    this->setWidget(my_w_ricnu);
}

WinViewRicnu::~WinViewRicnu()
{
    emit windowClosed();
    my_w_ricnu->~W_Ricnu();
}

//****************************************************************************
// Public function(s):
//****************************************************************************

//****************************************************************************
// Public slot(s):
//****************************************************************************

void WinViewRicnu::refreshDisplayExecute(void)
{
    my_w_ricnu->refresh();
}

//****************************************************************************
// Private function(s):
//****************************************************************************

//****************************************************************************
// Private slot(s):
//****************************************************************************

