# AIO_ESP_32_FEED_READ
Reading an Adafruit IO on an ESP_32

The INO was taken from https://github.com/adafruit/Adafruit_IO_Arduino/tree/master/examples/adafruitio_21_feed_read and adjusted a little bit. The example was for a shared file. This example only reads via MQTT, so data must change to see it. You will need the config.h file with your key and wifi set up.

I needed to install the Adafruit Mqtt and the Arduino HTTP client as dependencies with the Adafruit IO library.
