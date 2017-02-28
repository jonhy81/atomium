<?php

/**
 * @file
 * radio.preprocess.inc
 */

/**
 * Implements hook_preprocess_select().
 */
function atomium_preprocess_radio(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes(
    $element,
    array(
      'id',
      'name',
      '#return_value' => 'value',
    )
  );

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio'));
  $variables['attributes_array'] = $element['#attributes'];
}