#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/datetime/DateTimeController.h"
#include "displayapp/screens/Screen.h"
#include "displayapp/widgets/Counter.h"
#include "displayapp/screens/Label.h"
#include "displayapp/screens/ScreenList.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class SettingSetDate : public Screen {
      public:
        SettingSetDate(DisplayApp* app, Pinetime::Controllers::DateTime& dateTimeController);
        ~SettingSetDate() override;

        bool OnTouchEvent(TouchEvents event) override;
        
        void HandleButtonPress();
        void CheckDay();

      private:
        Controllers::DateTime& dateTimeController;

        lv_obj_t* btnSetTime;
        lv_obj_t* lblSetTime;

        Widgets::Counter dayCounter = Widgets::Counter(1, 31, jetbrains_mono_bold_20);
        Widgets::Counter monthCounter = Widgets::Counter(1, 12, jetbrains_mono_bold_20);
        Widgets::Counter yearCounter = Widgets::Counter(1970, 9999, jetbrains_mono_bold_20);

        ScreenList<2> screens;

        std::unique_ptr<Screen> CreateScreen1();
        std::unique_ptr<Screen> CreateScreen2();
      };
    }
  }
}
