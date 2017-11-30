<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_page(&$variables, $hook) {
  // This is important to set this variable to an empty string.
  $variables['action_links']['#type'] = '';
  $variables['action_links']['#wrapper'] = FALSE;

  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.4.1/js/foundation.min.js', 'external');
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.4.1/css/foundation.min.css', 'external');
}
