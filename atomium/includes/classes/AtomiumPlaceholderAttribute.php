<?php

namespace Drupal\atomium;

use drupol\htmltag\Attribute\AbstractAttribute;

/**
 * Class AtomiumPlaceholderAttribute.
 */
class AtomiumPlaceholderAttribute extends AbstractAttribute {

  /**
   * {@inheritdoc}
   */
  public function preprocess(array &$values, $name = NULL) {
    $values = \array_map('strip_tags', $values);
  }

}
