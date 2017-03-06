<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_link() {
  return array(
    'link' => array(
      'render element' => 'element',
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_link(&$variables, $hook) {
  global $language_url;

  $variables += array('options' => array('attributes' => array()));
  $variables['options'] += array(
    'html' => FALSE,
    'attributes' => array(),
  );

  $path = url($variables['path'], $variables['options']);

  // Append active class.
  if (($path == '/' . $_GET['q'] || ($path == '<front>' && drupal_is_front_page())) &&
    (empty($variables['options']['language']) || $variables['options']['language']->language == $language_url->language)) {
    $variables['options']['attributes']['class'][] = 'active';
  }

  $variables['attributes_array'] = $variables['options']['attributes'];
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge((array) $variables['attributes_array']['class'], array('hook__' . $hook));
  $variables['attributes_array']['href'] = $path;

  $variables['text'] = ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text']));

  $variables[$hook] = array(
    '#markup' => $variables['text'],
    '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
    '#tag' => 'a',
    '#attributes' => $variables['attributes_array'],
  );
}