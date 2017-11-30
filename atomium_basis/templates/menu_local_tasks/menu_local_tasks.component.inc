<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_menu_local_tasks(&$variables, $hook) {
  if (!empty($variables['primary'])) {
    $variables['primary']['#attributes']['class'][] = array(
      'tabs',
      'primary',
    );

  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#attributes']['class'][] = array(
      'tabs',
      'secondary',
      'clearfix',
    );
  }
}
