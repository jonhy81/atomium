<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_page(&$variables, $hook) {
  // This is important to set this variable to an empty string.
  $variables['action_links']['#type'] = 'div';
  $variables['action_links']['#wrapper'] = FALSE;
  $variables['action_links']['#attributes']['class'][] = 'btn-group';
  $variables['action_links']['#attributes']['class'][] = 'btn-group-justified';
  drupal_add_js('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js', 'external');
  drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css', 'external');
}
