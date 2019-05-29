G-Code
====================
```
; Factory Settings
M502

; Steps/mm (from calibration measurements)
M92 E100.2
M92 X80.38 Y80.32 Z402.85

; Z-Probe Offset (mm)
M851 Z-1.32
; Bed-Leveling Fade Height (mm)
M420 Z10.00

; Save Settings
M500
```

Slicer Settings
====================
* Z-Seam Alignment: `Sharpest Corner` (or `Random` for round objects)
* Combing Mode: `Not in Skin` (to hide visible structures if filament is a bit translucent as my grey one)
* PLA
  * *Initial* Layer Horizontal Expansion: `-0.1` mm (compensate for "elephant's foot")
  * Flow (%): `90` (after calibration with PLA - seems to be the opposite of the adjustment of extruder steps?!)
* PETG
  * **Blue Tape!** - PETG geht von Buildtak nur ganz schwer ab und es bleiben Spuren / Beschädigungen auf dem Buildtak zurück!
    * nur bei kleinen Teilen bzw. sehr wenig Auflagefläche mit Buildtak (und möglichst auch nicht direkt in der Mitte), da Brim aus PETG schwer vom Object zu entfernen ist (es bricht nicht einfach ab wie bei PLA, sondern hängt sehr fest dran)
  * **Line Width: `0.5` mm**
    * Wall Thickness: `1` mm
  * *Initial* Layer Horizontal Expansion: `-0.2` mm (aber Vorsicht bei sehr kleinen Teilen - die haften dann mangels unterstem Layer schlecht oder gar nicht mehr)
  * Default Printing Temperature: `230` °C
  * **Flow: `100` %**
    * Initial Layer Flow: `90` % (damit es nicht so matscht)
  * Print Speed: `60` mm/s (sollte Default sein), für noch bessere Qualität ggfs. auf `45` oder `30` mm/s reduzieren (macht zeitlich nicht viel aus)
    * Initial Layer Speed: `15` mm/s (hält besser)
  * Support (geht sonst so schlecht ab)
    * X/Y Distance: `1` mm
    * Z Distance: `0.2` mm
  * Wenn es Probleme gibt (z. B. wenn die Fäden nicht aneinander haften und es sehr hässliches Stringing gibt): **Print Speed runter (z.B. auf 15 mm/s) und Flow hoch (z.B. auf 110%)**

Machine Start G-Code
====================
(eigentlich nicht mehr notwendig, da UBL im EEPROM gespeichert ist und automatisch eingeschaltet wird nach Boot)
```
; Ender 3 Custom Start G-code
G28 ; Home all axes

G29 ; ABL (BLTouch)

G92 E0 ; Reset Extruder
G1 Z2.0 F3000 ; Move Z Axis up little to prevent scratching of Heat Bed

; Short delay to allow nozzle cleaning
G1 Z30
M117 Clean nozzle!
G4 S10
M117

G1 X0.1 Y20 Z0.3 F5000.0 ; Move to start position
G1 X0.1 Y200.0 Z0.3 F1500.0 E15 ; Draw the first line
G1 X0.4 Y200.0 Z0.3 F5000.0 ; Move to side a little
G1 X0.4 Y20 Z0.3 F1500.0 E30 ; Draw the second line
G92 E0 ; Reset Extruder
G1 Z2.0 F3000 ; Move Z Axis up little to prevent scratching of Heat Bed
; End of custom start GCode
```

Links
====================
* Extruder Calibration: https://mattshub.com/2017/04/19/extruder-calibration/  
"Load a 25 mm cube into your slicer and set the infill to 0%, perimeters to 1, and top solid layers to 0. 
You'll also want to print it at a fine resolution – I chose 0.15 mm. Print it out and then use digital calipers 
to measure the thickness of the walls. Your aim is to get this to be the same as your extrusion width set in your 
slicer. Adjust your new extrusion multiplier to: (extrusion width / measured wall thickness) × extrusion multiplier."
* 25 mm Cube: https://www.thingiverse.com/thing:2267549/files


Bed Leveling
====================

Einschalten
----------
(eigentlich nicht notwendig, da Status im EEPROM gespeichert wird)
```
G29 L0
M420 S1
```

Leveln
----------
```
M104 S200
M190 S60
G28
G29 P0 T
G29 P1 T
G29 P3 T
G29 S0

G26 B60 H200 Q5
````

Bed Topography Report
----------
```
M420 V

    (  1,229)                                      (229,229)
        0       1       2       3       4       5       6
 6 | +0.323  +0.202  +0.080  +0.135  +0.169  +0.204  +0.239
   |
 5 | +0.284  +0.182  +0.080  +0.102  +0.130  +0.157  +0.184
   |
 4 | +0.239  +0.162  +0.085  +0.070  +0.090  +0.110  +0.130
   |
 3 | +0.259  +0.154  +0.050  +0.008  +0.058  +0.107  +0.157
   |
 2 | +0.224  +0.125  +0.025  +0.018  +0.083  +0.147  +0.212
   |
 1 | +0.251  +0.169  +0.087  +0.063  +0.117  +0.172  +0.226
   |
 0 |[+0.279] +0.214  +0.150  +0.107  +0.152  +0.197  +0.241
        0       1       2       3       4       5       6
    (  1,  1)                                      (229,  1)
```
