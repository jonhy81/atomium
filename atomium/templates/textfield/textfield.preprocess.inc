<?php

/**
 * @file
 * textfield.preprocess.inc
 */

/**
 * Implements hook_preprocess_textfield().
 */
function atomium_preprocess_textfield(&$variables) {
  $element = &$variables['element'];

  if (isset($element['#title']) && !empty($element['#title'])) {
    $element['#attributes']['placeholder'] = $element['#title'];
  }

  $element['#attributes']['type'] = 'text';
  element_set_attributes(
    $element,
    array(
      'id',
      'name',
      'value',
      'size',
      'maxlength',
    )
  );
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && !empty($element['#autocomplete_input'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#autocomplete_input']['#id'];
    $attributes['value'] = $element['#autocomplete_input']['#url_value'];
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  if (isset($element['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'textfield__' . $element['#field_name'];
  }
  if (isset($element['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'textfield__' . $element['#entity_type'];
    if (isset($element['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'textfield__' . $element['#entity_type'] . '__' . $element['#field_name'];
    }
    if (isset($element['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'textfield__' . $element['#entity_type'] . '__' . $element['#bundle'];
    }
  }

  $variables['attributes_array'] = $element['#attributes'];
  $variables['extra'] = $extra;
}