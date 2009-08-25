/*
 * =====================================================================================
 * 
 *       Filename:  ppschannel.h
 * 
 *    Description:  support ordinarily pps stream like pps://xxx
 * 
 *        Version:  1.0
 *        Created:  2007年12月02日 09时12分37秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 * 
 * =====================================================================================
 */

#ifndef  PPSCHANNEL_FILE_HEADER_INC
#define  PPSCHANNEL_FILE_HEADER_INC

#include "channel.h"
class GMplayer;
class PPSChannel:public Channel
{
	public:
		PPSChannel(MainWindow* parent_);
		~PPSChannel(){}
		bool init();
		void refresh_list();
		typedef sigc::signal<void> type_signal_stop;
		type_signal_stop signal_stop_refresh()
		{ return signal_stop_refresh_; }

		typedef sigc::signal<void> type_signal_start;
		type_signal_start signal_start_refresh()
		{ return signal_start_refresh_; }	
	protected:
		LivePlayer* get_player(const std::string& stream,TypeChannel page);
		void  addLine(int users,const Glib::ustring& name,const std::string& sream,const Glib::ustring& groupname);
	private:

		void wait_wget_exit(GPid pid, int);
		type_signal_stop  signal_stop_refresh_;
		type_signal_start signal_start_refresh_;

		int wget_pid;
		bool refresh;

};

#endif   /* ----- #ifndef PPSCHANNEL_FILE_HEADER_INC  ----- */

