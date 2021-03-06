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

#include <stdlib.h>

#include "axis.hpp"
#include "axis_factory.hpp"
#include "button.hpp"
#include "button_factory.hpp"
#include "pingus_error.hpp"
#include "pointer.hpp"
#include "pointer_factory.hpp"
#include "scroller_factory.hpp"
#include "scrollers/axis_scroller.hpp"
#include "scrollers/inverted_scroller.hpp"
#include "scrollers/joystick_scroller.hpp"
#include "scrollers/mouse_scroller.hpp"
#include "scrollers/multiple_scroller.hpp"
#include "scrollers/pointer_scroller.hpp"

namespace Input {

using namespace Scrollers;

Scroller*
ScrollerFactory::create(const FileReader& reader)
{
  if (reader.get_name() == "axis-scroller")
    return axis_scroller(reader);

  else if (reader.get_name() == "inverted-scroller")
    return inverted_scroller(reader);

  else if (reader.get_name() == "joystick-scroller")
    return joystick_scroller(reader);

  else if (reader.get_name() == "mouse-scroller")
    return mouse_scroller(reader);

  else if (reader.get_name() == "multiple-scroller")
    return multiple_scroller(reader);

  else if (reader.get_name() == "pointer-scroller")
    return pointer_scroller(reader);

  else
    throw std::runtime_error(std::string("Unknown scroller type: ") + reader.get_name());

  return 0; // never reached
}

Scroller*
ScrollerFactory::axis_scroller(const FileReader& reader)
{
  float speed;
  if (!reader.read_float("speed", speed))
    throw std::runtime_error("AxisScroller without speed parameter");

  std::vector<Axis*> axes;
  const std::vector<FileReader>& sections = reader.get_sections();
  for(std::vector<FileReader>::const_iterator i = sections.begin() + 1;
      i != sections.end(); ++i)
    axes.push_back(AxisFactory::create(*i));
    
  return new AxisScroller(axes, speed);
}

Scroller*
ScrollerFactory::inverted_scroller(const FileReader& reader)
{
  bool invert_x;
  if (!reader.read_bool("invert-x", invert_x))
    throw std::runtime_error("InvertedScroller without invert X parameter");

  bool invert_y;
  if (!reader.read_bool("invert-y", invert_y))
    throw std::runtime_error("InvertedScroller without invert Y parameter");

  Scroller* scroller;
  scroller = create(reader);

  return new InvertedScroller(scroller, invert_x, invert_y);
}

Scroller*
ScrollerFactory::joystick_scroller(const FileReader& reader)
{
  int id;
  if (!reader.read_int("id", id))
    throw std::runtime_error("JoystickScroller without id parameter");

  float speed;
  if (!reader.read_float("speed", speed))
    throw std::runtime_error("JoystickScroller without speed parameter");

  return new JoystickScroller(id, speed);
}

Scroller*
ScrollerFactory::mouse_scroller (const FileReader& reader)
{
  int id = 0;
  reader.read_int("id", id);
  return new MouseScroller(id);
}

Scroller*
ScrollerFactory::multiple_scroller(const FileReader& reader)
{
  std::vector<Scroller*> scrollers;

  const std::vector<FileReader>& sections = reader.get_sections();
  for(std::vector<FileReader>::const_iterator i = sections.begin();
      i != sections.end(); ++i)
  {
    scrollers.push_back(create(*i));
  }

  return new MultipleScroller(scrollers);
}

Scroller*
ScrollerFactory::pointer_scroller(const FileReader& reader)
{
  Pointer* pointer;
  Button*  button;
  
  const std::vector<FileReader>& sections = reader.get_sections();
  
  if (sections.size() != 2)
    throw std::runtime_error("ScrollerFactory isn't <pointer><button>");

  pointer = PointerFactory::create(sections[0]);
  button  = ButtonFactory::create(sections[1]);

  return new PointerScroller(pointer, button);
}

} // namespace Input

/* EOF */
