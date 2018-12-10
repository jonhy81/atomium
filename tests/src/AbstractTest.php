<?php

namespace Drupal\Tests\atomium;

use PHPUnit\Framework\TestCase;
use Symfony\Component\Finder\Finder;
use Symfony\Component\Yaml\Yaml;

/**
 * Class AbstractTest.
 */
abstract class AbstractTest extends TestCase {

  /**
   * Return component fixtures.
   *
   * @return array
   *   List of component fixtures.
   */
  public function componentsProvider() {
    $finder = (new Finder())
      ->files()->in(\realpath(__DIR__ . '/../fixtures/components'));

    return \array_map(function ($file) {
      return array(
        'hook' => drupal_basename($file->getRelativePathname(), '.yml'),
        'content' => Yaml::parse($file->getContents()),
      );
    }, \iterator_to_array($finder));
  }

  /**
   * Return preprocess fixtures.
   *
   * @return array
   *   List of variables fixtures.
   */
  public function variablesPreprocessProvider() {
    $data = array();

    $finder = new Finder();
    $finder->files()->in(drupal_realpath(__DIR__ . '/../fixtures/preprocess'));
    foreach ($finder as $file) {
      $data[] = array(
        'variable_fixture' => Yaml::parse($file->getContents()),
      );
    }

    return $data;
  }

  /**
   * Return process fixtures.
   *
   * @return array
   *   List of variables fixtures.
   */
  public function variablesProcessProvider() {
    $data = array();

    $finder = new Finder();
    $finder->files()->in(drupal_realpath(__DIR__ . '/../fixtures/process'));
    foreach ($finder as $file) {
      $data[] = array(
        'variable_fixture' => Yaml::parse($file->getContents()),
      );
    }

    return $data;
  }

}
