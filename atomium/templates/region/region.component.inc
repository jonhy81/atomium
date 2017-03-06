<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_region(&$variables, $hook) {
  $classes = array(
    'hook__' . $hook,
    'hook__' . $hook . '__' . $variables['region'],
  );

  $variables['classes_array'] = array_merge($variables['classes_array'], $classes);
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('region')));
  $variables['attributes_array']['class'] = $variables['classes_array'];
  $variables['attributes_array']['role'] = 'complementary';

  $variables[$hook] = array(
    '#markup' => $variables['content'],
    '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
    '#tag' => 'aside',
    '#attributes' => $variables['attributes_array'],
  );
}