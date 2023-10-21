# Godot Midi

## Overview

This plugin aims to make rythm game development and music syncing easier than ever before. Simply import a midi file like you would any other godot asset, this can then be paired with a "MidiPlayer" node that sends out signals every time a midi event is fired. This project is a work in progress and is lacking some features, so feel free to contribute any code or ideas over on the pull requests page.

## Compatibility

This is a GDExtension addon and is only compatible with Godot version 4.1.2 and higher.

https://user-images.githubusercontent.com/10292944/212436300-37939dc6-e345-4300-8543-a16e4a451f3f.mp4

## Installation

1. Download the latest release over at https://github.com/nlaha/godot-midi-4.0/releases

2. Extract it to your `res://` folder such that both addons and bin are in the root of your project

3. Enable the plugin in the godot project settings menu

## Usage

1. Import a midi file by adding it to your project folder

2. Add a "MidiPlayer" node to your scene

3. Set the midi resource you want the MidiPlayer to play

4. Connect to the "note" signal in a GDScript

   ```gdscript

   func _ready():
    midi_player.note.connect(my_note_callback)
    midi_player.play()

   func my_note_callback(event, track):
       if (event['subtype'] == MIDI_MESSAGE_NOTE_ON): # note on
           # do something on note on
       elif (event['subtype'] == MIDI_MESSAGE_NOTE_OFF): # note off
           # do something on note off

       print("[Track: " + str(track) + "] Note played: " + str(event['note']))


   ```

Open the demo project for an included music visualizer script!
