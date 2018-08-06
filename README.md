# TerraDuino
TerraDuino is a C++ based terrarium controller based on an Arduino microcontroller and the [Sloeber IDE](http://eclipse.baeyens.it).

# Features
* 320x480 pixel display for status feedback, real-time temperature charts and configuration
* Real time clock for accurate time tracking without requiring any network or GPS
* Relay modules to switch on/off up to eight mains-powered sockets
* I/O panels for DHT22 temperature and humidity sensors
* Single rotary encoder complementing a user-friendly UI for easy but extensive configuration

# Project status
Most features are still missing and will be added over time. Bare with me, guys.

# User interface
Based on concepts of the Android platform TerraDuino consists of *Activities* and *Views*.

An *Activity* is a single full-screen element the user can interact with. It consists of multiple *Views* (or rather *Renderable* objects), each representing a logical UI block element.

# Controllers
Controllers take care of user input and presented screen elements.

Any class instance can register itself as the current *InputReceiver* to receive commands from the rotary encoder. The *ScreenController* manages a stack of activities and takes care of rendering UI elements.

# Disclaimer
This project is in no way related to https://github.com/TLINDEN/TerraDuino although it happens to share the same name by coincidence.
