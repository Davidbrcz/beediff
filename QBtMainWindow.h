#ifndef INCLUDED_QBtMainWindow_h
#define INCLUDED_QBtMainWindow_h
/********************************************************************
 * Copyright (C) Piotr Pszczolkowski
 *-------------------------------------------------------------------
 * This file is part of Beesoft Differ.
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
 * File         : QBtMainWindow.h
 * Author       : Piotr Pszczolkowski
 * Contact      : piotr@beesoft.org
 * Creation date: 27.01.2008
 *******************************************************************/

/*------- include files:
-------------------------------------------------------------------*/
#include <QMainWindow>

/*------- forward declarations:
-------------------------------------------------------------------*/
class QMenu;
class QAction;
class QLabel;
class QToolBar;
class QBtWorkspace;

/*------- class declaration:
-------------------------------------------------------------------*/
class QBtMainWindow : public QMainWindow
{
   Q_OBJECT

//******* CONSTRUCTION / DESTRUCTION *******
public:
   QBtMainWindow();
   ~QBtMainWindow();
private:
   QBtMainWindow( const QBtMainWindow& );
   QBtMainWindow& operator=( const QBtMainWindow& );

//******* CONSTANTS *******
private:
   //------- menu -------
   static const char* const SYSTEM;
   static const char* const OPERATIONS;
   static const char* const HELP;
   //------- system -------
   static const char* const SYNC;
   static const char* const SYNC_KEY;
   static const char* const NUMERATION;
   static const char* const NUMERATION_KEY;
   static const char* const SAVE;
   static const char* const SAVE_SKEY;
   static const char* const CONFIGURE;
   static const char* const CONFIGURE_SKEY;
   static const char* const EXIT;
   static const char* const EXIT_SKEY;
   //------- operations -------
   static const char* const MERGE_TO_LEFT;
   static const char* const MERGE_TO_RIGHT;
   static const char* const DEL_ON_LEFT;
   static const char* const DEL_ON_RIGHT;
   //------- help -------
   static const char* const ABOUT;
   static const char* const ABOUT_QT;
   //------- other -------
   static const char* const STAT_TOTAL;
   static const char* const STAT_CHG;
   static const char* const STAT_ADD;
   static const char* const STAT_DEL;
   //------- icons -------
   static const QString SYNC_ICON;
   static const QString NUMERATION_ICON;
   static const QString DISK_ICON;
   static const QString CONFIG_ICON;
   static const QString EXIT_ICON;
   static const QString MERGE2LFT_ICON;
   static const QString MERGE2RGT_ICON;
   static const QString DELLFT_ICON;
   static const QString DELRGT_ICON;
   static const QString ABOUT_ICON;
   static const QString ABOUT_QT_ICON;

//******* MEMBERS *******
private:
   //------- menu -------
   QMenu*    const system_;
   QMenu*    const operations_;
   QMenu*    const help_;
   //------- tab bars -------
   QToolBar* const system_bar_;
   QToolBar* const operations_bar_;
   //------- system -------
   QAction* const sync_;
   QAction* const numeration_;
   QAction* const save_;
   QAction* const configure_;
   QAction* const exit_;
   //------- operations -------
   QAction*  const merge_to_left_;
   QAction*  const merge_to_right_;
   QAction*  const del_on_left_;
   QAction*  const del_on_right_;
   //------- help -------
   QAction*  const about_;
   QAction*  const about_qt_;

   QBtWorkspace* const workspace_;
   QLabel      * const stat_total_;
   QLabel      * const stat_chg_;
   QLabel      * const stat_add_;
   QLabel      * const stat_del_;

//******* METHODS *******
private:
   void showEvent      ( QShowEvent* );
   void closeEvent     ( QCloseEvent* );
   void customEvent    ( QEvent* );
   void create_menu    ();
   void create_tbar    ();
   void create_sbar    () const;
   void set_sbar_widget( const QString&, QLabel* ) const;
   void update_actions ();
   void retranslate    ();
   void save_config    () const;
   void restore_config ();
private slots:
   void sync           ( bool );
   void numeration     ( bool );
   void del_on_left    ();
   void del_on_right   ();
   void merge_to_left  ();
   void merge_to_right ();
   void save           ();
   void configure      ();
   void quit           ();
   void about          ();
   void about_qt       ();
   void stat_total     ( int );
   void stat_chg       ( int );
   void stat_add       ( int );
   void stat_del       ( int );
};

#endif // INCLUDED_QBtMainWindow_h
