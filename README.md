# TerraDuino
TerraDuino is a C++ based terrarium controller using an Arduino Mega 2560 microcontroller. It is developed using the [Sloeber IDE](http://eclipse.baeyens.it).

## Features
* 320x480 pixel display for status feedback, real-time temperature charts and configuration
* Real time clock for accurate time tracking without requiring any network or GPS
* Relay modules to switch on/off up to eight mains-powered sockets
* I/O panels for DHT22 temperature and humidity sensors
* Single rotary encoder complementing a user-friendly UI for easy but extensive configuration

## Project status
Most features are still missing and will be added over time. Bare with me, guys.

## User interface
Based on concepts of the Android platform TerraDuino consists of `Activities` and `Views`.

`Activities` are single, full-screen elements the user can interact with. They consist of multiple `Views` (or `Renderable` objects), each representing a UI block element.

## Controllers
Controllers take care of user input and presented screen elements.

Any object instance can register itself as the current `InputReceiver` to receive commands from the rotary encoder. The `ScreenController` manages a stack of activities and takes care of rendering UI elements.

## License
TerraDuino is licensed under the GNU General Public License v3.0.

See [LICENSE](LICENSE) for details.

## Disclaimer
This project is in no way related to https://github.com/TLINDEN/TerraDuino although it happens to share the same name by coincidence.
