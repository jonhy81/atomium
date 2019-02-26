<?php

namespace Drupal\atomium;

use drupol\htmltag\Attribute\Attribute;

/**
 * Class AtomiumPlaceholderAttribute.
 */
class AtomiumPlaceholderAttribute extends Attribute {

  /**
   * {@inheritdoc}
   */
  public function preprocess(array $values, $name = NULL) {
    $values = \array_map('strip_tags', $values);

    return parent::preprocess($values, $name);
  }

}
