/********************************************************************
 * Copyright (C) Piotr Pszczolkowski
 *-------------------------------------------------------------------
 * This file is part of Beesoft Differ
 *
 * Beesoft Differ is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Beesoft Differ is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Beesoft Differ; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *-------------------------------------------------------------------
 * Project      : Beesoft Differ
 * File         : beediff.cpp
 * Author       : Piotr Pszczolkowski
 * Contact      : piotr@beesoft.org
 * Creation date: 27.01.2008
 *******************************************************************/

/*------- include files:
-------------------------------------------------------------------*/
#include "QBtShared.h"
#include "QBtMainWindow.h"
#include <QApplication>
#include <QIcon>

//*******************************************************************
// main
//*******************************************************************
int main( int in_argc, char** in_argv )
{
   Q_INIT_RESOURCE( beediff );

   QApplication::setOrganizationName  ( QBtShared::ORGANISATION );
   QApplication::setOrganizationDomain( QBtShared::ORGANISATION );
   QApplication::setApplicationName   ( QBtShared::PROGRAM_NAME );

   QApplication beediff( in_argc, in_argv );
   beediff.setWindowIcon( QIcon( ":/img/beediff.png" ) );

   QBtMainWindow window;
   window.show();
   
   return beediff.exec();
}
// end of main

