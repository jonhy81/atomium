<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_comment() {
  return array(
    'comment' => array(
      'render element' => 'elements',
      'template' => 'comment',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_comment(array &$variables, $hook) {
  if (isset($variables['elements']['#comment']->new) && $variables['elements']['#comment']->new) {
    $variables['classes_array'][] = 'new';

  }

  if ('comment-unpublished' === $variables['status']) {
    $variables['classes_array'][] = 'unpublished';
  }

  $variables['classes_array'][] = 'comment-' . $variables['id'];
  $variables['classes_array'][] = $variables['zebra'];

  // Remove inline class from the ul links.
  $variables['content']['links']['#attributes']['class'] = \array_values(\array_diff($variables['content']['links']['#attributes']['class'], array('inline')));

  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['content']->append('class', 'content');

  $picture = '';
  if (theme_get_setting('toggle_comment_user_picture')) {
    $picture = array(
      '#theme' => 'user_picture',
      '#account' => $variables['elements']['#comment'],
    );

    _atomium_extend_theme_property(
      $picture,
      array($variables['theme_hook_original']));
  }
  $variables['picture'] = $picture;
}
