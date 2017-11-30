<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_header(&$variables) {
  $logo = $variables['logo'];
  $logo_attributes = $variables['logo_attributes'];

  // Add classes and height/width to logo.
  if ($logo) {
    $logo_wrapper_classes = array();
    $logo_wrapper_classes[] = 'header-logo-wrapper';
    if ($logo_attributes['width'] <= $logo_attributes['height']) {
      $logo_wrapper_classes[] = 'header-logo-tall';
    }

    $variables['logo_wrapper_classes'] = $logo_wrapper_classes;
  }
}
