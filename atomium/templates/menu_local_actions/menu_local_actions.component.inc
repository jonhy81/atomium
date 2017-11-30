<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_actions() {
  return array(
    'menu_local_actions' => array(
      'template' => 'menu-local-actions',
      'variables' => array(
        'actions' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_local_actions(&$variables, $hook) {
  $variables[$hook] = array(
    $hook => array(
      '#theme' => array('item_list__' . $variables['theme_hook_original'] . '__actions'),
      '#items' => $variables['actions'],
      '#type' => 'ul',
      '#attributes' => array(),
      '#wrapper_attributes' => array(),
    ),
  );
}
