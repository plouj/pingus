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

#include "pingus/global_event.hpp"

#include <iostream>

#include "engine/display/screenshot.hpp"
#include "engine/screen/screen_manager.hpp"
#include "pingus/config_manager.hpp"
#include "pingus/globals.hpp"
#include "pingus/screens/addon_menu.hpp"
#include "pingus/screens/option_menu.hpp"

GlobalEvent global_event;

GlobalEvent::GlobalEvent ()
{
}

void
GlobalEvent::on_button_press(const SDL_KeyboardEvent& event)
{
  Uint8 *keystate = SDL_GetKeyState(NULL);

  switch (event.keysym.sym)
  {
    case SDLK_F10:
      config_manager.set_print_fps(!config_manager.get_print_fps());
      break;

    case SDLK_RETURN:
      if (!keystate[SDLK_LALT] && !keystate[SDLK_RALT])
        break;
      // FALL THROUGH
    case SDLK_F11:
      config_manager.set_fullscreen(!config_manager.get_fullscreen());
      break;

    case SDLK_F5:
      if (!dynamic_cast<OptionMenu*>(ScreenManager::instance()->get_current_screen().get()))
        ScreenManager::instance()->push_screen(new OptionMenu());
      break;

    case SDLK_F6:
      if (globals::maintainer_mode)
        if (!dynamic_cast<AddOnMenu*>(ScreenManager::instance()->get_current_screen().get()))
          ScreenManager::instance()->push_screen(new AddOnMenu());
      break;

    case SDLK_F12:
    {
      std::string filename;
      filename = Screenshot::make_screenshot();
    }
    break;

    case SDLK_c:
      if (globals::maintainer_mode)
        globals::draw_collision_map = !globals::draw_collision_map;
      break;

    case SDLK_k:
      if (globals::maintainer_mode)
      {
        std::cout << "Low level screen clear triggered" << std::endl;
        SDL_Surface* screen = SDL_GetVideoSurface();
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 0));
        SDL_Flip(screen);
      }
      break;

    case SDLK_m:
      if (keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL])
      {
        std::cout << "Maintainer Mode: " << globals::maintainer_mode << std::endl;
        globals::maintainer_mode = !globals::maintainer_mode;
      }
      break;

    case SDLK_g:
      if (keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL])
      {
        config_manager.set_mouse_grab(!config_manager.get_mouse_grab());
      }
      break;

    default:
      // console << "GlobalEvent: Unknown key pressed: " << key.id;
      break;
  }
}

void
GlobalEvent::on_button_release(const SDL_KeyboardEvent& event)
{
}

/* EOF */
