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
 * File         : QBtMainWindow.cpp
 * Author       : Piotr Pszczolkowski
 * Contact      : piotr@beesoft.org
 * Creation date: 27.01.2008
 *******************************************************************/

/*------- include files:
-------------------------------------------------------------------*/
#include "QBtMainWindow.h"
#include "QBtWorkspace.h"
#include "QBtShared.h"
#include "QBtConfig.h"
#include "QBtConfigDialog.h"
#include "QBtEventsController.h"
#include "QBtSettings.h"
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>
#include <QCloseEvent>
#include <QtDebug>

/*------- local constants:
-------------------------------------------------------------------*/
const char* const QBtMainWindow::SYSTEM         = QT_TR_NOOP( "&System" );
const char* const QBtMainWindow::OPERATIONS     = QT_TR_NOOP( "&Operations" );
const char* const QBtMainWindow::HELP           = QT_TR_NOOP( "&Help" );
//------- SYSTEM -------
const char* const QBtMainWindow::SYNC           = QT_TR_NOOP( "&Synchronized scroll" );
const char* const QBtMainWindow::SYNC_KEY       = QT_TR_NOOP( "Ctrl+S" ); 
const char* const QBtMainWindow::NUMERATION     = QT_TR_NOOP( "&Numeration" );
const char* const QBtMainWindow::NUMERATION_KEY = QT_TR_NOOP( "Ctrl+N" ); 
const char* const QBtMainWindow::SAVE           = QT_TR_NOOP( "&Save" );
const char* const QBtMainWindow::SAVE_SKEY      = QT_TR_NOOP( "Ctrl+S" );
const char* const QBtMainWindow::CONFIGURE      = QT_TR_NOOP( "&Configure" );
const char* const QBtMainWindow::CONFIGURE_SKEY = QT_TR_NOOP( "Ctrl+C" );
const char* const QBtMainWindow::EXIT           = QT_TR_NOOP( "&Exit" );
const char* const QBtMainWindow::EXIT_SKEY      = QT_TR_NOOP( "Ctrl+Q" );
//------- OPERATIONS -------
const char* const QBtMainWindow::MERGE_TO_LEFT  = QT_TR_NOOP( "Merge all to &left" );
const char* const QBtMainWindow::MERGE_TO_RIGHT = QT_TR_NOOP( "Merge all to &right" );
const char* const QBtMainWindow::DEL_ON_LEFT    = QT_TR_NOOP( "Re&move all from left" );
const char* const QBtMainWindow::DEL_ON_RIGHT   = QT_TR_NOOP( "Remo&ve all from right" );
//------- HELP -------
const char* const QBtMainWindow::ABOUT          = QT_TR_NOOP( "&About..." );
const char* const QBtMainWindow::ABOUT_QT       = QT_TR_NOOP( "About &Qt..." );
//------- OTHER -------
const char* const QBtMainWindow::STAT_TOTAL     = QT_TR_NOOP( "Total: %1" );
const char* const QBtMainWindow::STAT_CHG       = QT_TR_NOOP( "Changed: %1" );
const char* const QBtMainWindow::STAT_ADD       = QT_TR_NOOP( "Added: %1" );
const char* const QBtMainWindow::STAT_DEL       = QT_TR_NOOP( "Deleted: %1");
//------- ICONS -------
const QString QBtMainWindow::SYNC_ICON       = ":/img/sync.png";
const QString QBtMainWindow::NUMERATION_ICON = ":/img/numbers.png";
const QString QBtMainWindow::DISK_ICON       = ":/img/floppy.png";
const QString QBtMainWindow::CONFIG_ICON     = ":/img/configure.png";
const QString QBtMainWindow::EXIT_ICON       = ":/img/exit.png";
const QString QBtMainWindow::MERGE2LFT_ICON  = ":/img/merge_to_left.png";
const QString QBtMainWindow::MERGE2RGT_ICON  = ":/img/merge_to_right.png";
const QString QBtMainWindow::DELLFT_ICON     = ":/img/del_on_left.png";
const QString QBtMainWindow::DELRGT_ICON     = ":/img/del_on_right.png";
const QString QBtMainWindow::ABOUT_ICON      = ":/img/beediff.png";
const QString QBtMainWindow::ABOUT_QT_ICON   = ":/img/qt.png";


//*******************************************************************
// QBtMainWindow                                         CONSTRUCTOR
//*******************************************************************
QBtMainWindow::QBtMainWindow() : QMainWindow()
//------- menu -------
, system_         ( new QMenu )
, operations_     ( new QMenu )
, help_           ( new QMenu )
//------- tab bar -------
, system_bar_     ( new QToolBar )
, operations_bar_ ( new QToolBar )
//------- system -------
, sync_           ( new QAction( QIcon( SYNC_ICON       ), QString(), this ) )
, numeration_     ( new QAction( QIcon( NUMERATION_ICON ), QString(), this ) )
, save_           ( new QAction( QIcon( DISK_ICON       ), QString(), this ) )
, configure_      ( new QAction( QIcon( CONFIG_ICON     ), QString(), this ) )
, exit_           ( new QAction( QIcon( EXIT_ICON       ), QString(), this ) )
//------- operations -------
, merge_to_left_  ( new QAction( QIcon( MERGE2LFT_ICON  ), QString(), this ) )
, merge_to_right_ ( new QAction( QIcon( MERGE2RGT_ICON  ), QString(), this ) )
, del_on_left_    ( new QAction( QIcon( DELLFT_ICON     ), QString(), this ) )
, del_on_right_   ( new QAction( QIcon( DELRGT_ICON     ), QString(), this ) )
//------- help -------
, about_          ( new QAction( QIcon( ABOUT_ICON    ), QString(), this ) )
, about_qt_       ( new QAction( QIcon( ABOUT_QT_ICON ), QString(), this ) )
, workspace_      ( new QBtWorkspace( this ) )
//------- other -------
, stat_total_     ( new QLabel )
, stat_chg_       ( new QLabel )
, stat_add_       ( new QLabel )
, stat_del_       ( new QLabel )
{
   save_->setEnabled( false );
   sync_->setCheckable( true );
   sync_->setChecked( QBtConfig::instance()->sync() );
   numeration_->setCheckable( true );
   numeration_->setChecked( QBtConfig::instance()->numeration() );
   
   del_on_left_->setEnabled( false );
   del_on_right_->setEnabled( false );
   merge_to_left_->setEnabled( false );
   merge_to_right_->setEnabled( false );
   
   stat_total_->setFrameShape( QFrame::Panel );
   stat_total_->setFrameShadow( QFrame::Sunken );
   stat_chg_->setFrameShape( QFrame::Panel );
   stat_chg_->setFrameShadow( QFrame::Sunken );
   stat_add_->setFrameShape( QFrame::Panel );
   stat_add_->setFrameShadow( QFrame::Sunken );
   stat_del_->setFrameShape( QFrame::Panel );
   stat_del_->setFrameShadow( QFrame::Sunken );
   
   setWindowTitle( QBtShared::program_name() );
   system_bar_->setObjectName( "system_bar" );
   operations_bar_->setObjectName( "operations_bar" );

   create_menu();
   create_tbar();
   create_sbar();
   update_actions();

   setCentralWidget( workspace_ );
   
   stat_total( 0 );
   stat_chg  ( 0 );
   stat_add  ( 0 );
   stat_del  ( 0 );

   connect( workspace_, SIGNAL( stat_total(int) ), this, SLOT( stat_total(int) ) );
   connect( workspace_, SIGNAL( stat_chg  (int) ), this, SLOT( stat_chg  (int) ) );
   connect( workspace_, SIGNAL( stat_add  (int) ), this, SLOT( stat_add  (int) ) );
   connect( workspace_, SIGNAL( stat_del  (int) ), this, SLOT( stat_del  (int) ) );

   QBtEventsController* const ec = QBtEventsController::instance();
   ec->append( this, QBtEvent::FILES_CHANGED );
   ec->append( this, QBtEvent::FILES_UNCHANGED );
   ec->append( this, QBtEvent::READY_TO_MERGE );
   ec->append( this, QBtEvent::CANT_MERGE );
}
// end of QBtMainWindow

//*******************************************************************
// ~QBtMainWindow                                         DESTRUCTOR
//*******************************************************************
QBtMainWindow::~QBtMainWindow()
{
   QBtEventsController::instance()->remove( this );
   save_config();
}
// end of ~QBtMainWindow

//*******************************************************************
// save_config                                               PRIVATE
//*******************************************************************
void QBtMainWindow::save_config() const
{
   QBtSettings stt;
   stt.save( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::POS_KEY, pos() );
   stt.save( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::SIZE_KEY, size() );
   stt.save( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::STATE_KEY, saveState() );
}
// end of save_config

//*******************************************************************
// restore_config                                            PRIVATE
//*******************************************************************
void QBtMainWindow::restore_config()
{
   QBtSettings stt;
   QVariant data;
    if( stt.read( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::POS_KEY, data ) ) {
      move( data.toPoint() );
   }
   if( stt.read( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::SIZE_KEY, data ) ) {
      resize( data.toSize() );
   }
   if( stt.read( QBtConfig::MAIN_WINDOW_GROUP + QBtConfig::STATE_KEY, data ) ) {
      restoreState( data.toByteArray() );
   }
}
// end of restore_config

//*******************************************************************
// showEvent                                       PRIVATE inherited
//*******************************************************************
void QBtMainWindow::showEvent( QShowEvent* const in_event )
{
   QMainWindow::showEvent( in_event );
   
   retranslate();
   QBtShared::resize( this, 90, 75 );
   restore_config();

   const QStringList args = QApplication::arguments();
   if( args.size() > 2 ) {
      workspace_->lft_read_file( args.at( 1 ) );
      workspace_->rgt_read_file( args.at( 2 ) );
   }
}
// end of showEvent

//*******************************************************************
// customEvent                                     PRIVATE inherited
//*******************************************************************
void QBtMainWindow::customEvent( QEvent* const in_event )
{
   QBtEvent* const event = dynamic_cast< QBtEvent* >( in_event );
   const int type = static_cast< int >( event->type() );

   switch( type ) {
      case QBtEvent::FILES_CHANGED:
         save_->setEnabled( true );
         break;
      case QBtEvent::FILES_UNCHANGED:
         save_->setEnabled( false );
         break;
      case QBtEvent::READY_TO_MERGE:
         del_on_left_->setEnabled( true );
         del_on_right_->setEnabled( true );
         merge_to_left_->setEnabled( true );
         merge_to_right_->setEnabled( true );
         break;
      case QBtEvent::CANT_MERGE:
         del_on_left_->setEnabled( false );
         del_on_right_->setEnabled( false );
         merge_to_left_->setEnabled( false );
         merge_to_right_->setEnabled( false );
         break;
   }
}
// end of customEvent

//*******************************************************************
// create_menu                                               PRIVATE
//*******************************************************************
void QBtMainWindow::create_menu()
{
   //------- menu -------
   menuBar()->addMenu( system_ );
   menuBar()->addMenu( operations_ );
   menuBar()->addMenu( help_   );
   
   //------- system -------
   system_->addAction( sync_ );
   system_->addAction( numeration_ );
   system_->addSeparator();
   system_->addAction( save_ );
   system_->addAction( configure_ );
   system_->addSeparator();
   system_->addAction( exit_ );
   //------- operations -------
   operations_->addAction( del_on_left_ );
   operations_->addAction( del_on_right_ );
   operations_->addSeparator();
   operations_->addAction( merge_to_left_ );
   operations_->addAction( merge_to_right_ );
   //------- help -------
   help_->addAction( about_ );
   help_->addAction( about_qt_ );
}
// end of create_menu

//*******************************************************************
// create_tbar                                               PRIVATE
//*******************************************************************
void QBtMainWindow::create_tbar()
{
   addToolBar( system_bar_ );
   addToolBar( operations_bar_ );
   
   system_bar_->addAction( exit_ );
   system_bar_->addSeparator();
   system_bar_->addAction( save_ );
   system_bar_->addAction( sync_ );
   system_bar_->addAction( numeration_ );

   operations_bar_->addAction( del_on_left_ );
   operations_bar_->addAction( del_on_right_ );
   operations_bar_->addSeparator();
   operations_bar_->addAction( merge_to_left_ );
   operations_bar_->addAction( merge_to_right_ );
}
// end of create_tbar

//*******************************************************************
// create_sbar                                               PRIVATE
//*******************************************************************
void QBtMainWindow::create_sbar() const
{
   set_sbar_widget( tr( STAT_TOTAL ), stat_total_ );
   set_sbar_widget( tr( STAT_CHG   ), stat_chg_   );
   set_sbar_widget( tr( STAT_ADD   ), stat_add_   );
   set_sbar_widget( tr( STAT_DEL   ), stat_del_   );
}
// end of create_sbar

//*******************************************************************
// set_sbar_widget                                           PRIVATE
//*******************************************************************
void QBtMainWindow::set_sbar_widget( const QString& in_text, QLabel* const in_widget ) const
{
   QStatusBar* const sbar = statusBar();
   
   const int dx = QFontMetrics( sbar->font() ).width( in_text.arg( "9999" ) );
   in_widget->setIndent( 3 );
   in_widget->setMinimumWidth( dx );
   in_widget->setMaximumWidth( dx );
   sbar->addPermanentWidget( in_widget );
}
// end of set_sbar_widget

//*******************************************************************
// update_actions                                            PRIVATE
//*******************************************************************
void QBtMainWindow::update_actions()
{
   //------- system -------
   connect( sync_      , SIGNAL( toggled(bool) ), this, SLOT( sync      (bool) ) );
   connect( numeration_, SIGNAL( toggled(bool) ), this, SLOT( numeration(bool) ) );
   connect( save_      , SIGNAL( triggered() ), this, SLOT( save     () ) );
   connect( configure_ , SIGNAL( triggered() ), this, SLOT( configure() ) );
   connect( exit_      , SIGNAL( triggered() ), this, SLOT( quit     () ) );

   //------- operations -------
   connect( del_on_left_   , SIGNAL( triggered() ), this, SLOT( del_on_left   () ) );
   connect( del_on_right_  , SIGNAL( triggered() ), this, SLOT( del_on_right  () ) );
   connect( merge_to_left_ , SIGNAL( triggered() ), this, SLOT( merge_to_left () ) );
   connect( merge_to_right_, SIGNAL( triggered() ), this, SLOT( merge_to_right() ) );
   
   //------- help -------
   connect( about_   , SIGNAL( triggered() ), this, SLOT( about     () ) );
   connect( about_qt_, SIGNAL( triggered() ), this, SLOT( about_qt  () ) );
}
// end of update_actions

//*******************************************************************
// retranslate                                               PRIVATE
//*******************************************************************
void QBtMainWindow::retranslate()
{
   system_->setTitle( tr( SYSTEM ) );
   operations_->setTitle( tr( OPERATIONS ) );
   help_->setTitle( tr( HELP ) );
   //------- system -------
   sync_->setText( tr( SYNC ) );
   sync_->setShortcut( tr( SYNC_KEY ) );
   numeration_->setText( tr( NUMERATION ) );
   numeration_->setShortcut( tr( NUMERATION_KEY ) );
   save_->setText( tr( SAVE ) );
   save_->setShortcut( tr( SAVE_SKEY ) );
   configure_->setText( tr( CONFIGURE ) );
   configure_->setShortcut( tr( CONFIGURE_SKEY ) );
   exit_->setText( tr( EXIT ) );
   exit_->setShortcut( tr( EXIT_SKEY ) );
   //------- operations -------
   del_on_left_->setText( tr( DEL_ON_LEFT ) );
   del_on_right_->setText( tr( DEL_ON_RIGHT ) );
   merge_to_left_->setText( tr( MERGE_TO_LEFT ) );
   merge_to_right_->setText( tr( MERGE_TO_RIGHT ) );
   //------- help -------
   about_->setText( tr( ABOUT ) );
   about_qt_->setText( tr( ABOUT_QT ) );
}
// end of retranslate

//*******************************************************************
// closeEvent                                      PRIVATE inherited
//*******************************************************************
void QBtMainWindow::closeEvent( QCloseEvent* const in_event )
{
   workspace_->save_on_exit() ? in_event->accept() : in_event->ignore();
}
// end of closeEvent


//###################################################################
//#                                                                 #
//#                           S L O T S                             #
//#                                                                 #
//###################################################################

//*******************************************************************
// sync                                                 PRIVATE slot
//*******************************************************************
void QBtMainWindow::sync( const bool in_state )
{
   QBtEventsController::instance()->send_event( QBtEvent::SYNC, in_state );
}
// end of sync

//*******************************************************************
// numeration                                           PRIVATE slot
//*******************************************************************
void QBtMainWindow::numeration( const bool in_state )
{
   QBtEventsController::instance()->send_event( QBtEvent::NUMERATION, in_state );
}
// end of numeration

//*******************************************************************
// del_on_left                                          PRIVATE slot
//*******************************************************************
void QBtMainWindow::del_on_left()
{
   workspace_->del_on_A();
}
// end of del_on_left

//*******************************************************************
// del_on_rigth                                         PRIVATE slot
//*******************************************************************
void QBtMainWindow::del_on_right()
{
   workspace_->del_on_B();
}
// end of del_on_rigth

//*******************************************************************
// merge_to_left                                        PRIVATE slot
//*******************************************************************
void QBtMainWindow::merge_to_left()
{
   workspace_->merge_to_A();
}
// end of merge_to_left

//*******************************************************************
// merge_to_rigth                                       PRIVATE slot
//*******************************************************************
void QBtMainWindow::merge_to_right()
{
   workspace_->merge_to_B();
}
// end of merge_to_rigth

//*******************************************************************
// save                                                 PRIVATE slot
//*******************************************************************
void QBtMainWindow::save()
{
   workspace_->save();
}
// end of save

//*******************************************************************
// configure                                            PRIVATE slot
//*******************************************************************
void QBtMainWindow::configure()
{
   QBtConfigDialog dialog( this );
   dialog.exec();
}
// end of configure

//*******************************************************************
// quit                                                 PRIVATE slot
//*******************************************************************
void QBtMainWindow::quit()
{
   if( workspace_->save_on_exit() ) QApplication::quit();
}
// end of quit

//*******************************************************************
// about                                                PRIVATE slot
//*******************************************************************
void QBtMainWindow::about()
{
   static const char* const text = QT_TR_NOOP(
      "<qt>"
      "<font color=blue>A program for file comparing.</font>"
      "<hr>"
      "Author: Piotr Pszczolkowski<br>"
      "Contact: piotr@beesoft.at<br>"
      "Home page: www.beesoft.at"
      "</qt>" );
   QMessageBox::about( this, QBtShared::program_name(), tr( text ) );
}
// end of about

//*******************************************************************
// about_qt                                             PRIVATE slot
//*******************************************************************
void QBtMainWindow::about_qt()
{
   QMessageBox::aboutQt( this );
}
// end of about_qt

//*******************************************************************
// stat_total                                           PRIVATE slot
//*******************************************************************
void QBtMainWindow::stat_total( const int in_value )
{
   stat_total_->setText( tr( STAT_TOTAL ).arg( QString::number( in_value ) ) );
}
// end of stat_total

//*******************************************************************
// stat_chg                                             PRIVATE slot
//*******************************************************************
void QBtMainWindow::stat_chg( const int in_value )
{
   stat_chg_->setText( tr( STAT_CHG ).arg( QString::number( in_value ) ) );
}
// end of stat_chg

//*******************************************************************
// stat_add                                             PRIVATE slot
//*******************************************************************
void QBtMainWindow::stat_add( const int in_value )
{
   stat_add_->setText( tr( STAT_ADD ).arg( QString::number( in_value ) ) );
}
// end of stat_add

//*******************************************************************
// stat_del                                             PRIVATE slot
//*******************************************************************
void QBtMainWindow::stat_del( const int in_value )
{
   stat_del_->setText( tr( STAT_DEL ).arg( QString::number( in_value ) ) );
}
// end of stat_del
