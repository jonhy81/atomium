<?php

/**
 * @file
 * List of functions used to alter the theme registry in Atomium based themes.
 */

/**
 * Stub implementation for atomium_theme().
 *
 * This base-theme's custom theme hook implementations. Never define "path"
 * or "template" as these are detected and automatically added.
 *
 * @see atomium_theme_registry_alter()
 * @see atomium_theme()
 * @see hook_theme()
 */
function _atomium_theme(&$existing, $type, $theme, $path) {
  $hooks = array();

  foreach (atomium_find_templates() as $atomium_based_theme => $theme_data) {
    foreach ($theme_data as $component => $component_data) {

      $file = sprintf('%s/%s.component.inc', $component_data['directory'], $component);
      if (file_exists($file)) {
        include_once $file;
        $function_name = $atomium_based_theme . '_atomium_theme_' . $component;

        if (!function_exists($function_name)) {
          continue;
        }

        $hooks = drupal_array_merge_deep(
          (array) call_user_func_array(
            $function_name,
            array(&$existing, $type, $atomium_based_theme, $path)),
          $hooks
        );

        $hooks = array_map(function ($hook) use ($component_data, $component) {
          $hook += array(
            'path' => $component_data['directory'],
            'file' => sprintf('%s.component.inc', $component),
          );

          return $hook;
        }, $hooks);
      }
    }
  }

  return $hooks;
}
