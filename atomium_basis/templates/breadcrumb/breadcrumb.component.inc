<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_breadcrumb(&$variables, $hook) {
  if (isset($variables[$hook][$hook]['#type'])) {
    $variables[$hook][$hook]['#type'] = 'ol';
  }
}
