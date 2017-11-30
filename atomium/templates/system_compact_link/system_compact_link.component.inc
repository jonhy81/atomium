<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_compact_link() {
  return array(
    'system_compact_link' => array(
      'variables' => array('link' => array()),
      'template' => 'system-compact-link',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_compact_link(&$variables, $hook) {
  $variables['link'] = array(
    '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
    '#text' => NULL,
    '#path' => NULL,
    '#options' => array(
      'attributes' => array(),
      'query' => drupal_get_destination(),
    ),
  );
}
