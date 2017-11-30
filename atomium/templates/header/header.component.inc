<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_header() {
  return array(
    'header' => array(
      'template' => 'header',
      'variables' => array(
        'logo' => NULL,
        'site_name' => NULL,
        'site_slogan' => NULL,
        'menu' => NULL,
      ),
    ),
  );
}
