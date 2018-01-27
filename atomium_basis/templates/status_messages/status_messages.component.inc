<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_status_messages(&$variables, $hook) {
  array_walk($variables['status_messages']['status_messages'], function(&$messages) {
    unset($messages['messages']['#title']);
    $messages['#attributes']['class'][] = 'messages';
  });
}
