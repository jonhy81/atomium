<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_item_list() {
  return array(
    'item_list' => array(
      'template' => 'item-list',
      'variables' => array(
        'items' => array(),
        'title' => NULL,
        'type' => 'ul',
        'attributes' => array(),
        'wrapper' => TRUE,
        'wrapper_attributes' => array(
          'class' => array(
            'item-list',
          ),
        ),
        'atomium' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_item_list(array &$variables, $hook) {
  $variables += array(
    'wrapper' => TRUE,
    'wrapper_attributes' => array(),
  );

  if (empty($variables['items'])) {
    return;
  }

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $num_items = \count($variables['items']);
  $i = 0;
  foreach ($variables['items'] as $key => $item) {
    $i++;
    if (1 === $i) {
      $variables['atomium']['attributes'][$key]->append('class', 'first');
    }
    if ($i === $num_items) {
      $variables['atomium']['attributes'][$key]->append('class', 'last');
    }

    if (\is_array($item) && isset($item['data'])) {
      $item += array('class' => array());
      $variables['atomium']['attributes'][$key]->append('class', $item['class']);
      $item = array(
        '#theme' => 'html_tag',
        '#tag' => 'li',
        '#atomium' => array(
          'attributes' => array(
            'element' => $variables['atomium']['attributes'][$key],
          ),
        ),
        '#value' => $item['data'],
      );
      _atomium_extend_theme_property(
        $item,
        array($item['#tag'], $variables['theme_hook_original']));
      $variables['items'][$key] = $item;
    }

    if (\is_string($item)) {
      $item = array(
        '#theme' => 'html_tag',
        '#tag' => 'li',
        '#atomium' => array(
          'attributes' => array(
            'element' => $variables['atomium']['attributes'][$key],
          ),
        ),
        '#value' => $item,
      );
      _atomium_extend_theme_property(
        $item,
        array($item['#tag'], $variables['theme_hook_original']));
      $variables['items'][$key] = $item;
    }

    $variables['items'][$key] += array('#attributes' => array());
  }

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['list']->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']->merge($variables['wrapper_attributes']);
}
