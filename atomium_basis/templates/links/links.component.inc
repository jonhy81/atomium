<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_links(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->remove('class', 'links');
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_links__header_menu(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'links');
}
