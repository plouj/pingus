//  $Id: Console.hh,v 1.6 2000/06/14 21:09:55 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef CONSOLE_HH
#define CONSOLE_HH

#include <string>
#include <vector>
#include <ClanLib/core.h>
#include "Display.hh"

class Console : public DisplayHook
{
private:
  class Endl {};
  CL_Font* font;
  bool is_init;
  int  current_pos;
  vector<string> output_buffer;
  string current_line;
  int number_of_lines;

  void draw();
  void add_line(string);
public:
  static Endl endl;

  Console();
  virtual ~Console();

  void init();
  virtual void on_event();

  void set_height(int);
  int  get_height();

  Console& operator<<(const Console::Endl&);
  Console& operator<<(string);
  Console& operator<<(int);
  void printf(char* format, ...);
  void puts(string);
  void newline();
};

extern Console console;

#endif

/* EOF */
