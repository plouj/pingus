//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#include "../display/display.hpp"
#include "../display/scene_context.hpp"
#include "solid_color_background.hpp"

namespace WorldObjs {

SolidColorBackground::SolidColorBackground(const FileReader& reader)
{
  reader.read_color("color", color);
}

void
SolidColorBackground::draw (SceneContext& gc)
{
  gc.color().fill_screen(color);
}

} // namespace WorldObjs

/* EOF */
