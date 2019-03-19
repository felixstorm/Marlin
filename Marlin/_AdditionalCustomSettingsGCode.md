G-Code
==========
```
; Factory Settings
M502

; Steps/mm (from calibration measurements)
M92 E100.2
M92 X80.38 Y80.32 Z402.85

; Z-Probe Offset (mm)
M851 Z-1.70
; Bed-Leveling Fade Height (mm)
M420 Z10.00

; PLA PreHeat-Temperatures
M145 S0 H200 B60 F255

; Save Settings
M500
```

Slicer Settings
==========
* **Initial** Layer Horizontal Expansion: -0.1 (compensate for "elephant's foot")
* Flow: 90% (after calibration, seems to be the opposite of the adjustment of extruder steps?!)
* Combing Mode: Not in Skin (to hide visible structures if filament is a bit translucent as my grey one)


Links
==========
* Extruder Calibration: https://mattshub.com/2017/04/19/extruder-calibration/  
"Load a 25 mm cube into your slicer and set the infill to 0%, perimeters to 1, and top solid layers to 0. 
You'll also want to print it at a fine resolution – I chose 0.15 mm. Print it out and then use digital calipers 
to measure the thickness of the walls. Your aim is to get this to be the same as your extrusion width set in your 
slicer. Adjust your new extrusion multiplier to: (extrusion width / measured wall thickness) × extrusion multiplier."
* 25 mm Cube: https://www.thingiverse.com/thing:2267549/files
