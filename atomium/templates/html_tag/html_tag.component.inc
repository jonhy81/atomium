<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_html_tag() {
  return array(
    'html_tag' => array(
      'render element' => 'element',
      'template' => 'html-tag',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_html_tag(array &$variables, $hook) {
  $element = &$variables['element'];
  $element += array(
    '#value' => '',
    '#children' => '',
    '#attributes' => array(),
  );

  if (\is_string($element['#value'])) {
    $element['#value'] = array(
      array(
        '#markup' => $element['#value'],
      ),
    );
  }

  // Loop over element children, render them, and add them to the #value array.
  foreach (element_children($element) as $key) {
    $element['#value'][] = $element[$key];
  }

  if (!empty($element['#atomium']['attributes'])) {
    foreach ($element['#atomium']['attributes'] as $attribute => $data) {
      $variables['atomium']['attributes'][$attribute]->setAttributes($data);
    }
  }

  $variables['atomium']['attributes']['element']
    ->merge($element['#attributes']);

  // Remove type="..." and CDATA prefix/suffix.
  unset(
    $element['#attributes']['type'],
    $element['#value_prefix'],
    $element['#value_suffix']
  );

  // Remove media="all" but leave others unaffected.
  if (isset($element['#attributes']['media']) &&
    'all' === $element['#attributes']['media']) {
    unset($element['#attributes']['media']);
  }
}
