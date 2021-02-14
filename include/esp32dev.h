#pragma once

#include <Adafruit_RA8875.h>
#include <ConfigManager.h>
#include <RTClib.h>
#include <TouchScreen.h>

#include "hal.h"

namespace dbuddy {
    class ESP32Dev : public Hal {
    public:
        ESP32Dev(Adafruit_RA8875 * tft, TouchScreen * ts, uint8_t interrupt) : Hal(), tft(tft), ts(ts), interrupt(interrupt) {}

        void init() final;

        void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
        bool input_read(lv_indev_drv_t *, lv_indev_data_t *) final;

        int get_year() const final;
        int get_month() const final;
        int get_day() const final;
        int get_hours() const final;
        int get_minutes() const final;
        int get_seconds() const final;

        RTC_DS3231 * get_rtc() const { return rtc; }
        ConfigManager * get_manager() const { return configManager; }
    private:
        Adafruit_RA8875 * tft;
        TouchScreen * ts;

        uint8_t interrupt;

        RTC_DS3231 * rtc = new RTC_DS3231();
        ConfigManager * configManager = new ConfigManager();
    };
}