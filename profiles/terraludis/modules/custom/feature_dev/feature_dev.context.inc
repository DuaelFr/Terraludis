<?php
/**
 * @file
 * feature_dev.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_dev_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dev';
  $context->description = '';
  $context->tag = 'Development';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'context_ui-devel' => array(
          'module' => 'context_ui',
          'delta' => 'devel',
          'region' => 'help',
          'weight' => '-10',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'help',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Development');
  $export['dev'] = $context;

  return $export;
}
