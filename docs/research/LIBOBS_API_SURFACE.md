# libobs Public API Surface (Export Table)

> **Source:** `obs.dll` static export enumeration via REA (1,784 named exports).  
> **Method:** `inspect_native_exports` — reads PE export directory only. No decompilation.  
> **Address base:** Image base `0x180000000` (PE preferred base).  
> **Export directory:** RVA `0xFC2D0`, size `59,476` bytes, ordinal base `1`.

---

## Export Categories (Verified Names Only)

### Scene & SceneItem (92 exports)

```
obs_scene_add                      obs_scene_add_group
obs_scene_add_group2               obs_scene_atomic_update
obs_scene_create                   obs_scene_create_private
obs_scene_duplicate                obs_scene_enum_items
obs_scene_find_sceneitem_by_id     obs_scene_find_source
obs_scene_find_source_recursive    obs_scene_from_source
obs_scene_get_group                obs_scene_get_ref
obs_scene_get_source               obs_scene_insert_group
obs_scene_insert_group2            obs_scene_is_group
obs_scene_load_transform_states    obs_scene_prune_sources
obs_scene_release                  obs_scene_reorder_items
obs_scene_reorder_items2           obs_scene_save_transform_states
obs_sceneitem_addref               obs_sceneitem_defer_group_resize_begin
obs_sceneitem_defer_group_resize_end obs_sceneitem_defer_update_begin
obs_sceneitem_defer_update_end     obs_sceneitem_do_transition
obs_sceneitem_force_update_transform obs_sceneitem_get_alignment
obs_sceneitem_get_blending_method  obs_sceneitem_get_blending_mode
obs_sceneitem_get_bounds           obs_sceneitem_get_bounds_alignment
obs_sceneitem_get_bounds_crop      obs_sceneitem_get_bounds_type
obs_sceneitem_get_box_scale        obs_sceneitem_get_box_transform
obs_sceneitem_get_crop             obs_sceneitem_get_draw_transform
obs_sceneitem_get_group            obs_sceneitem_get_id
obs_sceneitem_get_info2            obs_sceneitem_get_order_position
obs_sceneitem_get_pos              obs_sceneitem_get_private_settings
obs_sceneitem_get_rot              obs_sceneitem_get_scale
obs_sceneitem_get_scale_filter     obs_sceneitem_get_scene
obs_sceneitem_get_source           obs_sceneitem_get_transition
obs_sceneitem_get_transition_duration obs_sceneitem_group_add_item
obs_sceneitem_group_enum_items     obs_sceneitem_group_get_scene
obs_sceneitem_group_remove_item    obs_sceneitem_group_ungroup
obs_sceneitem_group_ungroup2       obs_sceneitem_is_group
obs_sceneitem_locked               obs_sceneitem_release
obs_sceneitem_remove               obs_sceneitem_save
obs_sceneitem_select               obs_sceneitem_selected
obs_sceneitem_set_alignment        obs_sceneitem_set_blending_method
obs_sceneitem_set_blending_mode    obs_sceneitem_set_bounds
obs_sceneitem_set_bounds_alignment obs_sceneitem_set_bounds_crop
obs_sceneitem_set_bounds_type      obs_sceneitem_set_crop
obs_sceneitem_set_id               obs_sceneitem_set_info2
obs_sceneitem_set_locked           obs_sceneitem_set_order
obs_sceneitem_set_order_position   obs_sceneitem_set_pos
obs_sceneitem_set_rot              obs_sceneitem_set_scale
obs_sceneitem_set_scale_filter     obs_sceneitem_set_transition
obs_sceneitem_set_transition_duration obs_sceneitem_set_visible
obs_sceneitem_transition_load      obs_sceneitem_transition_save
obs_sceneitem_visible              obs_sceneitems_add
```

**Capabilities:** Full scene graph management — creation, grouping, transform (pos/rot/scale/crop), blending, Z-order, transitions, recursive search, atomic updates.

---

### Source (158 exports)

```
obs_source_active                  obs_source_add_active_child
obs_source_add_audio_capture_callback obs_source_add_audio_pause_callback
obs_source_add_caption_callback    obs_source_async_decoupled
obs_source_async_unbuffered        obs_source_audio_active
obs_source_audio_output_capture_device_changed obs_source_audio_pending
obs_source_backup_filters          obs_source_configurable
obs_source_copy_filters            obs_source_copy_single_filter
obs_source_create                  obs_source_create_private
obs_source_dec_active              obs_source_dec_showing
obs_source_default_render          obs_source_draw
obs_source_draw_set_color_matrix   obs_source_duplicate
obs_source_enable_push_to_mute     obs_source_enable_push_to_talk
obs_source_enabled                 obs_source_enum_active_sources
obs_source_enum_active_tree        obs_source_enum_filters
obs_source_enum_full_tree          obs_source_filter_add
obs_source_filter_count            obs_source_filter_get_index
obs_source_filter_remove           obs_source_filter_set_index
obs_source_filter_set_order        obs_source_frame_copy
obs_source_frame_init              obs_source_get_audio_mix
obs_source_get_audio_mixers        obs_source_get_audio_timestamp
obs_source_get_canvas_size         obs_source_get_color_matrix
obs_source_get_defaults            obs_source_get_display_name
obs_source_get_flags               obs_source_get_frame_rate
obs_source_get_height              obs_source_get_id
obs_source_get_last_error          obs_source_get_mixer
obs_source_get_mixers              obs_source_get_monitoring_type
obs_source_get_name                obs_source_get_output_flags
obs_source_get_proc_handler        obs_source_get_properties
obs_source_get_settings            obs_source_get_signal_handler
obs_source_get_type                obs_source_get_type_data
obs_source_get_width               obs_source_inc_showing
obs_source_load                    obs_source_monitoring_type_available
obs_source_mute                    obs_source_pause
obs_source_private                 obs_source_refs_get
obs_source_release                 obs_source_remove_active_child
obs_source_remove_audio_capture_callback obs_source_remove_audio_pause_callback
obs_source_remove_caption_callback obs_source_save
obs_source_save_transform          obs_source_set_async_decoupled
obs_source_set_async_unbuffered    obs_source_set_audio_capture_callback
obs_source_set_audio_pause_callback obs_source_set_caption_callback
obs_source_set_color_matrix        obs_source_set_defaults
obs_source_set_deinterlace_mode    obs_source_set_enabled
obs_source_set_filter_visibility   obs_source_set_monitoring_type
obs_source_set_mute                obs_source_set_name
obs_source_set_pause               obs_source_set_scale_filter
obs_source_set_sync_offset         obs_source_set_volume
obs_source_showing                 obs_source_start_audio_pause
obs_source_stop_audio_pause        obs_source_transition_load
obs_source_transition_save         obs_source_update
obs_source_update_properties       obs_source_valid
```

**Capabilities:** Source lifecycle (create/private/duplicate/release), async/decoupled modes, filter chain management, audio/video capture callbacks, rendering, properties/settings, monitoring, transitions.

---

### Filter (2 exports)

```
obs_filter_get_parent              obs_filter_get_target
```

**Note:** Filter logic is primarily exposed through `obs_source_*` functions (add/remove/enum filters). The two standalone functions only query parent/target.

---

### Audio (31 exports)

```
audio_output_active                audio_output_close
audio_output_connect               audio_output_disconnect
audio_output_get_block_size        audio_output_get_channels
audio_output_get_info              audio_output_get_planes
audio_output_get_sample_rate       audio_output_open
audio_resampler_create             audio_resampler_destroy
audio_resampler_resample           obs_add_raw_audio_callback
obs_audio_encoder_create           obs_audio_monitoring_available
obs_enum_audio_monitoring_devices  obs_get_audio_info
obs_get_audio_info2                obs_get_audio_monitoring_device
obs_get_output_supported_audio_codecs obs_hotkeys_set_audio_hotkeys_translations
obs_output_get_audio_encoder       obs_output_get_supported_audio_codecs
obs_output_set_audio_conversion    obs_output_set_audio_encoder
obs_remove_raw_audio_callback      obs_reset_audio_monitoring
obs_service_get_supported_audio_codecs obs_set_audio_monitoring_device
obs_transition_audio_render
```

**Capabilities:** Audio output device management, resampling, raw callback injection, monitoring device enumeration, codec enumeration, audio conversion setup.

---

### Video (55 exports)

```
obs_add_raw_video_callback         obs_add_raw_video_callback2
obs_canvas_get_video_info          obs_encoder_get_preferred_video_format
obs_encoder_set_preferred_video_format obs_encoder_video_tex_active
obs_get_output_supported_video_codecs obs_get_video_frame_time
obs_get_video_hdr_nominal_peak_level obs_get_video_info
obs_get_video_sdr_white_level      obs_output_get_supported_video_codecs
obs_output_get_video_conversion    obs_output_get_video_encoder
obs_output_get_video_encoder2      obs_output_set_video_conversion
obs_output_set_video_encoder       obs_output_set_video_encoder2
obs_remove_raw_video_callback      obs_service_get_supported_video_codecs
obs_set_video_levels               obs_transition_video_get_color_space
obs_transition_video_render        obs_transition_video_render2
obs_transition_video_render_direct obs_video_active
obs_video_encoder_create           obs_view_enum_video_info
video_format_from_fourcc           video_format_get_parameters
video_format_get_parameters_for_format video_frame_copy
video_frame_init                   video_output_active
video_output_close                 video_output_connect
video_output_connect2              video_output_disconnect
video_output_disconnect2           video_output_get_format
```

**Capabilities:** Raw video callback injection, video output lifecycle, format negotiation (FourCC, HDR/SDR levels), frame management, encoder/video output binding, color space.

---

### Encoder (70 exports)

```
obs_encoder_active                 obs_encoder_add_roi
obs_encoder_clear_roi              obs_encoder_create_rerouted
obs_encoder_defaults               obs_encoder_enum_roi
obs_encoder_get_caps               obs_encoder_get_codec
obs_encoder_get_defaults           obs_encoder_get_display_name
obs_encoder_get_encoded_frames     obs_encoder_get_extra_data
obs_encoder_get_frame_rate_divisor obs_encoder_get_frame_size
obs_encoder_get_height             obs_encoder_get_id
obs_encoder_get_last_error         obs_encoder_get_mixer_index
obs_encoder_get_module             obs_encoder_get_name
obs_encoder_get_pause_offset       obs_encoder_get_preferred_color_space
obs_encoder_get_preferred_range    obs_encoder_get_priming_samples
obs_encoder_get_ref                obs_encoder_get_roi_increment
obs_encoder_get_sample_rate        obs_encoder_get_scale_type
obs_encoder_get_settings           obs_encoder_get_type
obs_encoder_get_type_data          obs_encoder_get_weak_encoder
obs_encoder_get_width              obs_encoder_gpu_scaling_enabled
obs_encoder_group_create           obs_encoder_group_destroy
obs_encoder_has_roi                obs_encoder_load_state
obs_encoder_packet_ref             obs_encoder_packet_release
obs_encoder_parent_video           obs_encoder_paused
obs_encoder_properties             obs_encoder_release
obs_encoder_scaling_enabled        obs_encoder_set_audio
obs_encoder_set_frame_rate_divisor obs_encoder_set_gpu_scale_type
obs_encoder_set_group              obs_encoder_set_last_error
obs_encoder_set_name               obs_encoder_set_preferred_color_space
obs_encoder_set_preferred_range    obs_encoder_set_scaled_size
obs_encoder_set_video              obs_encoder_update
obs_encoder_video                  obs_enum_encoder_types
obs_get_encoder_by_name            obs_get_encoder_caps
obs_get_encoder_codec              obs_get_encoder_properties
obs_get_encoder_type               obs_register_encoder_s
obs_service_apply_encoder_settings obs_weak_encoder_addref
obs_weak_encoder_get_encoder       obs_weak_encoder_references_encoder
obs_weak_encoder_release
```

**Capabilities:** Full encoder lifecycle, ROI (region of interest), scaling (GPU/CPU), frame rate control, extra data (codec headers), pause/resume, groups, properties, weak references.

---

### Output (64 exports)

```
obs_output_active                  obs_output_add_packet_callback
obs_output_audio                   obs_output_begin_data_capture
obs_output_can_begin_data_capture  obs_output_can_pause
obs_output_caption                 obs_output_create
obs_output_defaults                obs_output_end_data_capture
obs_output_force_stop              obs_output_get_active_delay
obs_output_get_congestion          obs_output_get_connect_time_ms
obs_output_get_delay               obs_output_get_display_name
obs_output_get_flags               obs_output_get_frames_dropped
obs_output_get_height              obs_output_get_height2
obs_output_get_id                  obs_output_get_last_error
obs_output_get_mixer               obs_output_get_mixers
obs_output_get_module              obs_output_get_name
obs_output_get_pause_offset        obs_output_get_proc_handler
obs_output_get_protocols           obs_output_get_ref
obs_output_get_service             obs_output_get_settings
obs_output_get_signal_handler      obs_output_get_total_bytes
obs_output_get_total_frames        obs_output_get_type_data
obs_output_get_weak_output         obs_output_get_width
obs_output_get_width2              obs_output_initialize_encoders
obs_output_pause                   obs_output_release
obs_output_set_delay               obs_output_set_last_error
obs_output_set_media               obs_output_set_media2
obs_output_set_mixer               obs_output_set_name
obs_output_set_pause_offset        obs_output_set_service
obs_output_set_video_conversion    obs_output_set_video_encoder
obs_output_start                   obs_output_start_data_capture
obs_output_stop                    obs_output_update
obs_weak_output_addref             obs_weak_output_get_output
obs_weak_output_references_output  obs_weak_output_release
```

**Capabilities:** Output lifecycle, packet callbacks, congestion/delay monitoring, service binding, encoder assignment, start/stop/pause, weak references.

---

### Service / Streaming (in Plugin/Load group)

```
obs_service_create                 obs_service_apply_encoder_settings
obs_service_get_supported_video_codecs obs_service_get_supported_audio_codecs
obs_service_load_state
```

---

### Plugin / Module Load (22 exports)

```
gs_load_default_samplerstate       gs_load_indexbuffer
gs_load_pixelshader                gs_load_samplerstate
gs_load_swapchain                  gs_load_texture
gs_load_vertexbuffer               gs_load_vertexshader
obs_hotkey_load_bindings           obs_hotkeys_load_encoder
obs_hotkeys_load_output            obs_hotkeys_load_service
obs_hotkeys_load_source            obs_load_all_modules
obs_load_all_modules2              obs_load_canvas
obs_load_private_source            obs_load_source
obs_load_sources                   obs_module_load_locale
obs_post_load_modules              obs_service_load_state
```

**Capabilities:** Plugin discovery/loading (`obs_load_all_modules*`), graphics state loading (`gs_load_*`), hotkey binding persistence, canvas/source loading.

---

### Data / Settings (156 exports — `obs_data_*` family)

```
obs_data_addref                    obs_data_apply
obs_data_array_addref              obs_data_array_count
obs_data_array_create              obs_data_array_enum
obs_data_array_erase               obs_data_array_insert
obs_data_array_item                obs_data_array_push_back
obs_data_array_push_back_array     obs_data_array_release
obs_data_clear                     obs_data_create
obs_data_create_from_json          obs_data_create_from_json_file
obs_data_create_from_json_file_safe obs_data_erase
obs_data_first                     obs_data_get_array
obs_data_get_autoselect_array      obs_data_get_autoselect_bool
obs_data_get_autoselect_double     obs_data_get_autoselect_frames_per_second
obs_data_get_autoselect_int        obs_data_get_autoselect_obj
obs_data_get_autoselect_quat       obs_data_get_autoselect_string
obs_data_get_autoselect_vec2       obs_data_get_autoselect_vec3
obs_data_get_autoselect_vec4       obs_data_get_bool
obs_data_get_default_array         obs_data_get_default_bool
obs_data_get_default_double        obs_data_get_default_frames_per_second
obs_data_get_default_int           obs_data_get_default_obj
obs_data_get_default_quat          obs_data_get_default_string
obs_data_get_default_vec2          obs_data_get_default_vec3
obs_data_get_default_vec4          obs_data_get_double
obs_data_get_int                   obs_data_get_obj
obs_data_get_ptr                   obs_data_get_quat
obs_data_get_string                obs_data_get_type
obs_data_get_vec2                  obs_data_get_vec3
obs_data_get_vec4                  obs_data_has_autoselect_value
obs_data_has_user_value            obs_data_item_get_autoselect_frames_per_second
obs_data_item_get_frames_per_second obs_data_item_set_frames_per_second
obs_data_new                       obs_data_release
obs_data_remove_autoselect_value   obs_data_set_array
obs_data_set_autoselect_bool       obs_data_set_autoselect_double
obs_data_set_autoselect_int        obs_data_set_autoselect_string
obs_data_set_bool                  obs_data_set_double
obs_data_set_default_array         obs_data_set_default_bool
obs_data_set_default_double        obs_data_set_default_int
obs_data_set_default_string        obs_data_set_int
obs_data_set_obj                   obs_data_set_ptr
obs_data_set_quat                  obs_data_set_string
obs_data_set_vec2                  obs_data_set_vec3
obs_data_set_vec4                  obs_data_set_default_vec2
obs_data_set_default_vec3          obs_data_set_default_vec4
```

**Capabilities:** Hierarchical typed data model (bool, int, double, string, vec2/3/4, quat, array, object), JSON serialization, autoselect (per-device profiles), defaults, reference counting.

---

### Property / UI (81 exports — `obs_property_*` family)

```
obs_property_button_clicked        obs_property_button_set_type
obs_property_button_set_url        obs_property_button_type
obs_property_button_url            obs_property_description
obs_property_editable_list_default_path obs_property_editable_list_filter
obs_property_editable_list_type    obs_property_enabled
obs_property_float_max             obs_property_float_min
obs_property_float_set_limits      obs_property_float_set_suffix
obs_property_float_step            obs_property_float_suffix
obs_property_float_type            obs_property_frame_rate_clear
obs_property_frame_rate_fps_range_add obs_property_frame_rate_fps_range_insert
obs_property_frame_rate_fps_range_max obs_property_frame_rate_fps_range_min
obs_property_frame_rate_fps_ranges_clear obs_property_frame_rate_fps_ranges_count
obs_property_frame_rate_option_add obs_property_frame_rate_option_description
obs_property_frame_rate_option_insert obs_property_frame_rate_option_name
obs_property_frame_rate_options_clear obs_property_frame_rate_options_count
obs_property_frame_rate_option_description obs_property_frame_rate_option_name
... (frame-rate option management continues)
obs_property_int_max               obs_property_int_min
obs_property_int_set_limits        obs_property_int_step
obs_property_int_suffix            obs_property_int_type
obs_property_list_add_int          obs_property_list_add_string
obs_property_list_clear            obs_property_list_item_bool
obs_property_list_item_disabled    obs_property_list_item_int
obs_property_list_item_string      obs_property_list_type
obs_property_long_description      obs_property_modified
obs_property_next                  obs_property_path_type
obs_property_set_description       obs_property_set_long_description
obs_property_set_modified_callback obs_property_set_visible
obs_property_text_info_type        obs_property_text_info_word_wrap
obs_property_text_type             obs_property_type
```

**Capabilities:** Property sheet for UI generation — buttons, editable lists, frame-rate presets, int/float with limits/steps/suffixes, path selectors, list types (int/string), text info, visibility/modified callbacks.

---

### Object / Refcount (3 exports)

```
obs_object_get_ref                 obs_object_get_weak_object
obs_object_release
```

**Capabilities:** COM-style reference counting + weak references — base for all opaque handles.

---

### Other / Uncategorized (~1,050 exports)

Includes: logging, hotkeys, transitions, canvas, platform abstraction, profiler, memory, locale, platform-specific modules, etc.

---

## Summary Statistics

| Category | Export Count |
|----------|-------------|
| Scene / SceneItem | 92 |
| Source | 158 |
| Filter | 2 |
| Audio | 31 |
| Video | 55 |
| Encoder | 70 |
| Output | 64 |
| Plugin / Load | 22 |
| Data / Settings | 156 |
| Property / UI | 81 |
| Object / Refcount | 3 |
| **Total Categorized** | **734** |
| **Other / Uncategorized** | **~1,050** |
| **Grand Total** | **1,784** |

---

## Verification

- **Tool:** REA `inspect_native_exports` (reads PE export directory only)
- **Coverage:** `status: "complete", examined_entries: 1784, exports: 1784`
- **Limitations:** *"Rows reproduce the PE export directory; they do not establish that an export is reachable, safe to call or loaded at runtime."*

---

*Data extracted 2026-10-27 via REA MCP stdio channel. No decompiler used.*