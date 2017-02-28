<?php

/**
 * @file
 * html.preprocess.inc
 */

/**
 * Implements hook_preprocess_html().
 */
function atomium_foundation_preprocess_html(&$variables, $hook) {
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.3.0/js/foundation.min.js', 'external');
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.3.0/css/foundation.min.css', 'external');
}