//  $Id: level_dot.hxx,v 1.2 2002/10/13 13:34:40 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HEADER_PINGUS_WORLDMAP_LEVEL_DOT_HXX
#define HEADER_PINGUS_WORLDMAP_LEVEL_DOT_HXX

#include <ClanLib/Display/Display/surface.h>
#include "dot.hxx"

namespace WorldMapNS {

/** */
class LevelDot : public Dot
{
private:
  CL_Surface green_dot_sur;
  CL_Surface red_dot_sur;

public:
  LevelDot(xmlDocPtr doc, xmlNodePtr cur);

  void draw(GraphicContext& gc);
  void update();

private:
  LevelDot (const LevelDot&);
  LevelDot& operator= (const LevelDot&);
};

} // namespace WorldMapNS

#endif

/* EOF */