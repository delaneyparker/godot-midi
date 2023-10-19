#ifndef MIDI_PLAYER_H
#define MIDI_PLAYER_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <atomic>

#include "midi_resource.h"

using namespace godot;

enum PlayerState
{
    Playing,
    Paused,
    Stopped
};

class MidiPlayer : public Node
{
    GDCLASS(MidiPlayer, Node);

protected:

    static void _bind_methods()
    {
        ClassDB::bind_method(D_METHOD("set_midi", "midi"), &MidiPlayer::set_midi);
        ClassDB::bind_method(D_METHOD("get_midi"), &MidiPlayer::get_midi);
        ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "midi"), "set_midi", "get_midi");

        ClassDB::bind_method(D_METHOD("play"), &MidiPlayer::play);
        ClassDB::bind_method(D_METHOD("stop"), &MidiPlayer::stop);
        ClassDB::bind_method(D_METHOD("pause"), &MidiPlayer::pause);
        ClassDB::bind_method(D_METHOD("get_state"), &MidiPlayer::get_state);

        ClassDB::bind_method(D_METHOD("get_current_time"), &MidiPlayer::get_current_time);
        ClassDB::bind_method(D_METHOD("set_current_time", "current_time"), &MidiPlayer::set_current_time);
        ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "current_time"), "set_current_time", "get_current_time");

        ADD_SIGNAL(MethodInfo("finished"));
        
        ADD_SIGNAL(MethodInfo("note"));
        ADD_SIGNAL(MethodInfo("meta"));
        ADD_SIGNAL(MethodInfo("system"));
    };

private:
    Ref<MidiResource> midi;

    std::atomic<PlayerState> state;
    double current_time;
    Array track_index_offsets;

public:
    virtual void _process(double delta) override;

    MidiPlayer();
    ~MidiPlayer();

    void play();
    void stop();
    void pause();

    int get_state()
    {
        return (int)this->state;
    };

    double get_current_time()
    {
        return this->current_time;
    };

    void set_current_time(double current_time)
    {
        this->current_time = current_time;
    };

    void set_midi(Ref<MidiResource> midi)
    {
        this->midi = midi;
    };

    Ref<MidiResource> get_midi()
    {
        return this->midi;
    };
};

#endif // MIDI_PLAYER_H