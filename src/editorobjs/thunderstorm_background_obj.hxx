//  $Id: thunderstorm_background_obj.hxx,v 1.1 2002/09/18 15:00:37 torangan Exp $
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

#ifndef HEADER_PINGUS_EDITOROBJS_THUNDERSTORM_BACKGROUND_OBJ_HXX
#define HEADER_PINGUS_EDITOROBJS_THUNDERSTORM_BACKGROUND_OBJ_HXX

#include "../editor/sprite_editorobj.hxx"

namespace WorldObjsData {
class ThunderstormBackgroundData;
}

namespace EditorObjs {

class ThunderstormBackgroundObj : public SpriteEditorObj
{
private:
  WorldObjsData::ThunderstormBackgroundData* const data;
  
public:
  ThunderstormBackgroundObj (WorldObjsData::ThunderstormBackgroundData* data_);
 ~ThunderstormBackgroundObj ();
 
  void write_xml (std::ostream& xml);
  
  EditorObj* duplicate ();
  
  std::string status_line ();
  
private:
  ThunderstormBackgroundObj (const ThunderstormBackgroundObj&);
  ThunderstormBackgroundObj operator= (const ThunderstormBackgroundObj&);
};

} // namespace EditorObjs

#endif

/* EOF */