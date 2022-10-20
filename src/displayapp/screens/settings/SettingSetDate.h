#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/datetime/DateTimeController.h"
#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"
#include "displayapp/widgets/Counter.h"
#include "displayapp/screens/Label.h"
#include "displayapp/screens/ScreenList.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class SettingSetDate : public Screen {
      public:
        SettingSetDate(DisplayApp* app, Pinetime::Controllers::DateTime& dateTimeController,
        Pinetime::Controllers::Settings& settingsController);
        ~SettingSetDate() override;

        bool OnTouchEvent(TouchEvents event) override;
        //SettingSetDate void
        void HandleButtonPress();
        void CheckDay();
        //SettingSetTime void
        void SetTime();
        void UpdateScreen();

      private:
        Controllers::DateTime& dateTimeController;
        Controllers::Settings& settingsController;
        //SettingSetDate labels
        lv_obj_t* btnSetTime;
        lv_obj_t* lblSetTime;
        //SettingSetTime labels 
        lv_obj_t* lblampm;
        lv_obj_t* btnSetTime;
        lv_obj_t* lblSetTime;
        //SettingSetDate Widgets
        Widgets::Counter dayCounter = Widgets::Counter(1, 31, jetbrains_mono_bold_20);
        Widgets::Counter monthCounter = Widgets::Counter(1, 12, jetbrains_mono_bold_20);
        Widgets::Counter yearCounter = Widgets::Counter(1970, 9999, jetbrains_mono_bold_20);
        //SettingSetTime Widgets
        Widgets::Counter hourCounter = Widgets::Counter(0, 23, jetbrains_mono_42);
        Widgets::Counter minuteCounter = Widgets::Counter(0, 59, jetbrains_mono_42);

        ScreenList<2> screens;
        std::unique_ptr<Screen> CreateScreen1();
        std::unique_ptr<Screen> CreateScreen2();
      };
    }
  }
}
