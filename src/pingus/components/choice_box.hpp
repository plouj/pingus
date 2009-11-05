//  Pingus - A free Lemmings clone
//  Copyright (C) 2007 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_PINGUS_COMPONENTS_CHOICE_BOX_HPP
#define HEADER_PINGUS_COMPONENTS_CHOICE_BOX_HPP

#include <string>
#include <vector>
#include <boost/signal.hpp>
#include "engine/gui/rect_component.hpp"

/** */
class ChoiceBox : public GUI::RectComponent
{
private:
  int current_choice;
  std::vector<std::string> choices;
  
public:
  ChoiceBox(const Rect& rect);

  void draw(DrawingContext& gc);
  void on_primary_button_press(int x, int y);
  void update_layout() {}
  void add_choice(const std::string& str);
  void set_current_choice(int choice);
  
  boost::signal<void (std::string)> on_change;
  
private:
  ChoiceBox (const ChoiceBox&);
  ChoiceBox& operator= (const ChoiceBox&);
};

#endif

/* EOF */