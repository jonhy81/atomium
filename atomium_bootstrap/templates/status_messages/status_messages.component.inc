<?php

/**
 * @file
 * Status_messages.preprocess.inc.
 */

/**
 * Implements hook_preprocess_status_messages().
 */
function atomium_bootstrap_preprocess_status_messages(&$variables) {
  $status_mapping = array(
    'error' => 'alert-danger',
    'status' => 'alert-success',
    'warning' => 'alert-warning',
  );

  foreach ($variables['messages'] as $type => &$messages) {
    $messages['#attributes']['class'][] = 'alert';
    $messages['#attributes']['class'][] = 'alert-dismissible';
    $messages['#attributes']['class'][] = $status_mapping[$type];
    $messages['value']['#attributes']['class'][] = 'list-unstyled';

    // TODO: Use render arrays.
    $messages['close'] = array(
      '#markup' => '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>',
      '#weight' => -1,
    );
  }
}