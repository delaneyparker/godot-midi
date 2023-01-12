@tool
extends EditorImportPlugin

enum Presets { DEFAULT }

func _get_importer_name():
	return "com.nlaha.godotmidi"

func _get_visible_name():
	return "Godot Midi"

func _get_recognized_extensions() -> PackedStringArray:
	return PackedStringArray(["mid", "midi"])

func _get_save_extension():
	return "res"

func _get_resource_type():
	return "Animation"

func _get_preset_count():
	return Presets.size()
	
func _get_priority():
	return 1.0
	
func _get_option_visibility(option, name, options):
	return true
	
func _get_import_options(name, preset):
	return []

func _get_preset_name(i):
	return "Default"

func _get_import_order():
	return 0

func _import(source_file, save_path, options, r_platform_variants, r_gen_files):
	var midi = Midi.new();
	var global_file = ProjectSettings.globalize_path(source_file)

	var save_file = "%s.%s" % [save_path, _get_save_extension()]
	midi.load_from_file(global_file, save_file)
	
	return OK
